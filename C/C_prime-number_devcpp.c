#include <stdio.h>
#include <stdlib.h>



int main(){

    int x, result;

    printf("\nEnter a number: ");
    scanf("%d", &x);
    
    printf("\nYour number is %d", x);

    result = x % 2;
    
    printf("%d", result);

    if(result = 0){
        printf("\nYour number (%d) is NOT a prime number",x);
    }
    else{
        printf("\nYour number (%d) is a prime number",x);
    }
    
    return 0;
}
