#include <iostream>

int main(){

    int x = 5;

    //printing square pattern
    for(int i = 1; i<=x; i++){
        for(int j = 1; j<=x; j++){
            std::cout << "@ ";
        }
        std::cout << "\n";
    }

std::cout << "\n";

    //printing increasing triangle pattern
    for(int i = 1; i<=x; i++){
        for(int j = 1; j<=i; j++){
            std::cout << "@ ";
        }
        std::cout << "\n";
    }

std::cout << "\n";

    //printing decreasing triangle pattern
    for(int i = 1; i<=x; i++){
        for(int j = i; j<=x; j++){
            std::cout << "@ ";
        }
        std::cout << "\n";
    }

    return 0;
}