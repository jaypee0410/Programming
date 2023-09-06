#include <stdio.h>
#include <stdlib.h>

int main(){

    int age = 21;
    int *pAge = &age;

    printf("address of age: %p\n", pAge);
    printf("value of pAge: %p\n", &age);

    printf("size of age: %d bytes\n", sizeof(age));
    printf("size of pAge: %d bytes\n", sizeof(pAge));

    return 0;
}