#include <stdio.h>

void greet(char name[], int age){
	
	printf("\nHappy Birthday %s!!", name);
	printf("\nYou are now %d years old", age);
	
}


int main(){
	
	char name[] = "Jaypee";
	int age = 26;
	
	greet(name, age);
	
	return 0;	
}
