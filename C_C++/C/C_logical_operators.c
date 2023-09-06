#include <stdio.h>
#include <stdbool.h>

int main(){
	
	float temp;
	
	printf("\nEnter Temperature (C): ");
	scanf("%d", &temp);
	
	if(temp >= 0 && temp <= 30){
		printf("\nThe weather is Good!");
	}
	else{
		printf("\nThe weather is Bad!");
		}
	
}
