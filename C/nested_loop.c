#include <stdio.h>

//nested loop practice

int main(){
    int c,r;
    char sym;
    
    printf("Hello!\n");
    printf("Enter Row/s: ");
    scanf("%d", &r);
    printf("Enter Column/s: ");
    scanf("%d", &c);
    scanf("%c");

    printf("Enter Symbol: ");
    scanf("%c", &sym); 
    
    printf("\n");
    
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            printf("%c", sym); 
        }
        printf("\n");
    }
    
    return 0;
}

