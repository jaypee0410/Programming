#include <cmath>
#include <windows.h>
//general config:
const int res_X=140; //resolution x
const int res_Y=60; //resolution y; right-click on the window title, select properties and set the proper size
const int fov=600; //field of view, in 0.1 degree increments (60 degrees)
POINT point0; //mouse starting point
const int mouse_speed=100; //mouse speed division
const int map_size=16; //square map size
const double torad=M_PI/180; //degrees to radians conversion factor
double sintab[3600]; //lookup table of sine values, every 0.1 degree
double fisheye[res_X]; //lookup table for fisheye correction, 1 value for every screen column
//rendering - specific variables:
char buff[res_X*res_Y]; //screen character buffer
WORD cbuff[res_X*res_Y]; //screen color buffer
char grad[11]=" .-,=+*%#@"; //character gradient used to denote brightness
int hmap[res_X]; //map of heights of wall columns
int tmap[res_X]; //map of texture coordinates of wall columns
int typemap[res_X]; //map of types of walls (for multiple possible tetures)
double lmap[res_X]; //brightness map of wall columns
int textures[32*32*8]; //array containing 8 32x32 textures (1024 pixels); first byte is character, second one is color
//game state - map, player
double player[6]; //x,y position, x,y velocity, angle (in 0.1 deg increments), vertical angle
long map[map_size][map_size]; //world map; could be 1-d array but its not speed-critical here; 1st byte = wall type (0=none), 2nd=floor, 3rd=ceiling
int t,ext; //time, exit flag

void init()//initialization, precalculation, map, textures
{
for(int i=0;i<map_size;i++){map[i][0]=1;map[i][map_size-1]=1;map[0][i]=1;map[map_size-1][i]=1;};//make walls on the map edge
map[3][1]=1;map[2][4]=1;map[7][7]=1; //some random blocks; generally one can use some random map generation or load it from file etc.
for(int x=0;x<map_size;x++)for(int y=0;y<map_size;y++)map[x][y]+=(2*256+1*256*256); //set floor and ceiling types
map[6][6]=3*256;//some random floor/ceiling blocks
player[0]=5;player[1]=5; //put the player somewhere in the middle
for(int x=0;x<32;x++)for(int y=0;y<32;y++)//texture generation - again, it could be loaded from file
	{
	textures[x+y*32]=(12-8*((y%6==0)||((x+4*(y/6))%16==0))+rand()%2)+(4+4*((y%6==0)||((x+4*(y/6))%16==0)))*256; //brick texture;last term is color (4=red, 8=gray)
	textures[x+y*32+1024]=8-4*((y%31==0)||((x+4*(y/31))%16==0))+rand()%2+1*256; //large brick texture;last term is color (1=blue)
	textures[x+y*32+2048]=8-4*((y%31==0)||((x+4*(y/31))%16==0))+rand()%2+2*256; //large brick texture;last term is color (2=green)
	textures[x+y*32+3072]=8-4*((y%31==0)||((x+4*(y/31))%16==0))+rand()%2+6*256; //large brick texture;last term is color (6=yellow)
	}
for(int i=0;i<3600;i++){double v=sin(i*0.1*torad);if(v==0)v=0.0001;sintab[i]=v;};//calculate sine values; change 0 to non-0 to avoid division by zero errors
for(int i=0;i<res_X;i++)fisheye[i]=cos(0.1*(i-res_X/2)*torad*fov/res_X); //fisheye correction term
GetCursorPos(&point0); //record starting point of the mouse
}

void trace()//main ray casting function
{
double x,y,dx,dy,d,t1,t2; //ray x,y, step x, step y, traveled distance, time to x intersection, time to y intersection
int mx,my,dmx,dmy,ang,collision; //integer ray coordinates, integer steps, ray angle
for (int xs=0;xs<res_X;xs++)//go through all screen columns
	{
	ang=(int)(3600+player[4]+(xs-res_X/2)*fov/res_X);//ray angle = player angle +-half of FoV at screen edges; add 360 degrees to avoid negative values
	dx=sintab[(ang+900)%3600];dmx=(dx>0) ? 1 : -1;//calculate horizontal step and its integer equivalent; +900 (90 degrees) is used to get cosine
	dy=sintab[ang%3600];dmy=(dy>0) ? 1 : -1;//calculate vertical step and its integer equivalent
	x=player[0];y=player[1];mx=(int)x;my=(int)y;d=0; //ray starts from player position; tracing is done on doubles (x,y), map checks on integers(mx,my)
	for(int i=0;i<2*map_size;i++)//ray tracing; we check only intersections with horizontal/vertical grid lines, so maximum of 2*map_size is possible
	{
	if(map[mx][my]%256>0)break;//map>0 is a wall; hit a wall? end tracing
	t1=(mx-x+(dx>0))/dx; t2=(my-y+(dy>0))/dy; //calculate times to intersection of x and y grid lines; we look for fractional coordinate (difference between its int and double value) and divide by speed in that direction 
	if(t1<t2){y+=dy*t1;mx+=dmx;x=mx-(dx<0)*dmx;d+=t1;}else{x+=dx*t2;my+=dmy;y=my-(dy<0)*dmy;d+=t2;}//select lower of these two times, then update the coordinates and traveled distance
	}//end of tracing; the distance is updated during steps, so there is no need to use slow pythagorean theory to calculate it
	hmap[xs]=(int)(res_Y/2/d/fisheye[xs]); //record wall height; it is inversely proportional to distance / fisheye correction term
	tmap[xs]=(t1<t2) ? 32*fabs(y-(int)(y)) : 32*fabs(x-(int)(x)); //calculate texture coordinate; it is equal to 32*fractional part of x/y coordinate, depending on whether x or y collision occured
	lmap[xs]=(t1<t2) ? 1 : 0.5; //record brightness; north/south walls are brighter, like in Wolfenstein 3D. Here, one can also use some distance-based brightness etc.
	lmap[xs]*=hmap[xs]/32.0; //OPTIONAL distance based brightness; change factor 32.0 for faster/slower faloff
	typemap[xs]=map[mx][my]%256-1; //record wall type; 0=no wall, 1=wall type 0, 2=wall type 1 etc.
	}//end of tracing
}

void draw()//main wall and floor/ceiling drawing function
{
int off; //offset in the 1-d char/color buffer we are writing to 
int horizon_pos=(int)player[5]; //position of the horizon, for looking up/down 0=in the middle
int lm1,lm2,ang; //upper/lower limit of the wall slice; ray angle
int crdx,crdy,crd,mcx,mcy; //texture x,y coordinate, final coordinate in 1-d texture buffer, max x,y coordinate of floor/ceiling pixel
double cha,col; //character and color to draw; use double for smooth distance falloff etc.
double dx,dy,dz; //ray steps for floor rendering; dz=distance to floor;

for (int x=0;x<res_X;x++)//we go column by column
	{
	lm1=-(hmap[x]+horizon_pos>res_Y/2 ? res_Y/2 : hmap[x]+horizon_pos); //upper limit of the wall, capped at half vertical resolution (middle of the screen=0)
	lm2=(hmap[x]-horizon_pos>res_Y/2 ? res_Y/2 : hmap[x]-horizon_pos); //lower limit of the wall, capped at -half vertical resolution (middle of the screen=0)
	off=x; //we draw on the column x
	ang=(int)(3600+player[4]+(x-res_X/2)*fov/res_X);//calculate ray angle; needed for floor
	dx=sintab[(ang+900)%3600];dy=sintab[ang%3600];//steps in x and y direction, the same as in tracing, needed for floor
	for (int y=-res_Y/2;y<res_Y/2;y++){//go along the whole screen column, drawing either wall or floor/ceiling
		if(y>=lm1&&y<=lm2)
		{//are we drawing a wall?
		crdx=tmap[x];//we get texture x coordinate from coordinate buffer made in tracing step 
		crdy=16+(int)(14*(y+horizon_pos)/hmap[x]);//texture y coordinate depends on y, horizon position and height
		crd=crdx+32*crdy+1024*typemap[x];//calculate coordinate to use in 1-d texture buffer
		cha=textures[crd]%256;//get texture pixel (1st byte)
		col=textures[crd]/256;//get texture color (2nd byte)
		cha=cha*lmap[x];//multiply character number (pixel) by brightness
		}
		else//we are drawing floor/ceiling
		{//this part is a bit hack-ish, could be written and optimized better
		dz=res_Y/2/(fabs(y+horizon_pos)+0.1)/cos((x-res_X/2)*torad*0.1*fov/res_X); //calculate distance to the floor pixel; 0.1 is here to avoid division by 0
		crdx=(int)(1024+32.0*(player[0]+dx*dz))%32; //floor/ceiling texture coordinates
		crdy=(int)(1024+32.0*(player[1]+dy*dz))%32;
		mcx=(int)(player[0]+dx*dz)%map_size; //floor/ceiling map coordinates
		mcy=(int)(player[1]+dy*dz)%map_size;
		crd=crdx+32*crdy; //base texture coordinate
		if(y>(-horizon_pos))crd+=1024*((map[mcx][mcy]/256)%256); //2nd byte = floor type
		else crd+=1024*((map[mcx][mcy]/65536)%256); //3rd byte = ceiling type
		cha=textures[crd]%256;//get texture pixel (1st byte)
		col=textures[crd]/256;//get texture color (2nd byte)
		cha=cha*1.0/(0.1+1.5*dz); //OPTIONAL distance based brightness; change factor 1.5 for faster/slower faloff; factor 0.1 is to avoid division by 0 if dz=0
		}
	cha*=(1+0.25*(abs(y)%2)+0.25*(abs(x)%2));//OPTIONAL add dithering to avoid ugly edges
	if(cha>9)cha=9;if(cha<0)cha=0; //limit the value to the limits of character gradient (especially important if there are multiple brightness modifiers)
	buff[off]=grad[(int)cha];//save the character in character buffer
	cbuff[off]=(int)col; //save the color in color buffer
	off+=res_X; //go down by 1 row
	}//end of column
	}//end of drawing
}

void display()//main display function; widows-specific
{
HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE); //handle to console window
COORD C;C.X=0;C.Y=0;//define coordinates, set them to 0,0
SetConsoleCursorPosition(hand, C); //set the cursor to 0,0
DWORD written; //helper flag, unused
WriteConsole(hand,buff,res_X*res_Y,&written,NULL); //write the character contents of buff[]
WriteConsoleOutputAttribute(hand, cbuff, res_X*res_Y, C, &written); //set colors according to cbuff[]
}

void controls()//handles keyboard, mouse controls and player movement; windows-specific
{
double dx=0.01*sintab[(int)player[4]%3600]; //x step in the direction player is looking; 0.01 is the player speed factor
double dy=0.01*sintab[((int)player[4]+900)%3600]; //y step in the direction player is looking
if (GetKeyState(0x41) & 0x8000){player[2]+=dx;player[3]-=dy;}; //WASD movement
if (GetKeyState(0x44) & 0x8000){player[2]-=dx;player[3]+=dy;};
if (GetKeyState(0x57) & 0x8000){player[2]+=dy;player[3]+=dx;};
if (GetKeyState(0x53) & 0x8000){player[2]-=dy;player[3]-=dx;};
if (GetKeyState(VK_ESCAPE) & 0x8000)ext=1;

if (map[(int)(player[0]+1*player[2])][(int)player[1]]%256>0)player[2]=-player[2]/2;//collisions in x axis - bounce back with half the velocity
if (map[(int)player[0]][(int)(player[1]+1*player[3])]%256>0)player[3]=-player[3]/2;//collisions in y axis
player[0]+=player[2];player[1]+=player[3]; //update x,y values with x,y velocities
player[2]*=0.9;player[3]*=0.9; //friction reduces velocity values

POINT point;//for mouse
if (GetCursorPos(&point)) {
 player[4]=500.0*(point.x-point0.x)/mouse_speed; //player horizontal angle
 player[5]=20.0*(point.y-point0.y)/mouse_speed; //player vertical angle
}
if(player[4]<3600)player[4]+=3600; //if player angle is less than 360 degrees, add 360 degrees so its never negative
}

int main()
{
init();
while(ext==0){controls();trace();draw();display();Sleep(1);t++;}//main game loop
}//note: 1 milisecond delay gives absurd upper limit of 1000 fps... which is almost reached. Some delay is necessary, otherwise console window starts glitching.
