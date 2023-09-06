#include <stdio.h>

int main(){
	
	//this is a single line comment
	/*	
		this
		is
		a
		multiline
		comment
	*/
	
	/*1.VARIABLES*/
	/*
	int x; //declaration
	x = 3; // initialization
	int y = 0; // declaration and initialization
	
	int age = 24; //integer %d (decimal)
	float weight = 71.2; //floating point number %f (float)
	char grade = 'C'; //single character %c (char)
	char name[] = "Dog"; //array of characters %s (string)
	float pi_f = 3.141592653589793; //4 bytes (32 bits of precision) 6-7 digits %f
	double pi_d = 3.141592653589793; //8 bytes (64 bits of precision) 15-16 digits %lf
	
	print name
	printf("Hello %s\n", name); 
	
	print age
	printf("You are %d years old\n", age); 
	
	print grade
	printf("Your averge grade is %c\n", grade);
	
	print float
	printf("Your weight is %f\n", weight);
	
	print 
	printf("\"I like pizza!\"");
	*/
	
	/*----------------------------------------------*/
	
	/*2.DATA TYPES*/
	/*
	bool e = true; //1 byte (true of false) %d
	
	char f = 100; //1 byte (-128 to +127) %d or %c
	unsigned char g = 255; //1 byte (0 to +255) %d or %c
	
	short int h = 32767; //2 bytes (-32,768 to +32,767) %d
	unsigned short int i = 65535; //2 bytes (0 to +65,535) %d
	
	int j = 2147483647; //4 bytes (-2,147,483,648 to +2,147,483,647) %d
	unsigned int k = 4294967295U;//4 bytes (0 to +4,294,967,295) %u
	
	long long int l = 9223372036854775807; //8 bytes (-9 quintillion to +9 quintillion) %lld
	unsigned long long int m = 18446744073709551615U;//8 bytes (0 to +18 quintillion) %llu
			
	printf("%d\n", g); // unsigned char g
	printf("%d\n", h); // short int h
	printf("%d\n", i); // unsigned short int i
	printf("%d\n", j); // int j
	printf("%u\n", k); // unsigned int k
	printf("%lld\n", l); // long long int k
	printf("%llu\n", m); // unsigned long long int k
	*/
	
	/*----------------------------------------------*/
	
	/*3.FORMAT SPECIFIERS (%) = defines and formats a type of data to be displayed*/
	
	/*
	%c = character
	%s = string (array of characters)
	%f = float
	%lf = double
	%d = integer
	
	%.1 = decimal precision
	%1 = minimum field width
	%- = left align
	*/
	/*
	float item1 = 5.75;
	float item2 = 10.00;
	float item3 = 100.99;
	
	printf("Item 1: $%8.2f\n", item1);
	printf("Item 1: $%8.2f\n", item2);
	printf("Item 1: $%8.2f\n", item3);
	*/
	
	/*----------------------------------------------*/
	
	/*4.CONSTANTS - fixed values that cannot be altered by the program during its execution*/
	/*
	const float PI = 3.14159;
	
	printf("%f", PI);
	*/
	
	/*----------------------------------------------*/
	
	/*5.ARITHMETIC OPERATORS*/
	
	
	// + (addition)
	// - (subtraction)
	// / (division)
	// % (modulus)
	// ++ (increment)
	// -- (decrement)
	
	int x = 77;
	int y = 2;
	
	//int z = x + y;
	//int z = x - y;
	//int z = x * y;
	//float z = x / (float) y;
	int z = x%y;
	
	//x++;
	//y--;
	
	printf("%d", z);
	
	
	/*----------------------------------------------*/
	
	/*6. AUGMENTED ASSIGNMENT OPERATORS - Used to replace a statement where an
	operator takes a variable as one of its arguments and then assigns the result
	back to the same variable
	ex. x = x + 1
		x+=1
	*/
	
	/*7. USER INPUT */
	/*
	char name[25]; //bytes
	int age;
	
	printf("\nWhat's your name? ");
	scanf("%s", &name);
	
	printf("How old are you? ");
	scanf("%d", &age);
	
	printf("\nHello %s, how are you?", name);
	printf("\nYou are %d years old", age);
	*/
	
	
	return 0;
	
}
