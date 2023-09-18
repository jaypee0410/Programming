#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int x, i, is_prime = 1;

    printf("\nEnter a positive integer: ");
    scanf("%d", &x);
    printf("\nYour number is %d", x);
    
    if(x <= 1){
        is_prime = 0;
    }
    else{
        for (i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    if(is_prime){
        printf("\nYour number (%d) is a prime number",x);
    }
    else{
        printf("\nYour number (%d) is NOT a prime number",x);
    }
    
    return 0;
}