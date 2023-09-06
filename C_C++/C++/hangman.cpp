#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <limits>

void randomWord(){
}
void playGame(){
}

int main(){

    std::string words[] = {"Chocolate", "Hotdog", "Spaghetti", "Burger", "Pizza", "Sushi", "Porkchop", 
                            "Bolognese", "Cheese", "Carbonara", "Cake", "Lasagna", "Chorizo"};
    std::string wordGuess[15];
    int choice, wordIndex, wordSize, healthPoints;
    char confirm, guessLetter;

    //
    
    //generate random seed
    srand(time(0));

    //get a random word from the array
    wordIndex = rand() % sizeof(words)/sizeof(words[0]);
    
    //check the length of the word
    wordSize = words[wordIndex].length();

    /*
    std::cout << wordIndex << '\n';
    std::cout << words[wordIndex] << '\n';;
    std::cout << wordSize << '\n';
    */
        
        main_menu:
        system("cls");
        std::cout << "......................................................................." <<'\n';
        std::cout << "..##.....##....###....##....##..######...##.....##....###....##....##.." <<'\n';
        std::cout << "..##.....##...##.##...###...##.##....##..###...###...##.##...###...##.." <<'\n';
        std::cout << "..##.....##..##...##..####..##.##........####.####..##...##..####..##.." <<'\n';
        std::cout << "..#########.##.....##.##.##.##.##...####.##.###.##.##.....##.##.##.##.." <<'\n';
        std::cout << "..##.....##.#########.##..####.##....##..##.....##.#########.##..####.." <<'\n';
        std::cout << "..##.....##.##.....##.##...###.##....##..##.....##.##.....##.##...###.." <<'\n';
        std::cout << "..##.....##.##.....##.##....##..######...##.....##.##.....##.##....##.." <<'\n';
        std::cout << "......................................................................." <<'\n';
        std::cout << "1. Play Game" << '\n';
        std::cout << "2. Instruction" << '\n';
        std::cout << "3. Exit Game" << '\n';
        
    do{
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Check if input operation failed
        if (std::cin.fail()) {
            std::cout << "Invalid Choice! Please enter a number.\n";

            // Clear the fail bit and ignore the rest of the input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }   

        switch(choice){
            case 1: // Game Mechanics
                system("cls");
                for(int i=0;i<wordSize;i++){
                    std::cout << "_ ";
                    wordGuess[i] = words[wordIndex][i]; // Transfer each words' char to wordGuess array
                    //std::cout << wordGuess[i] << '\n';  
                }
                healthPoints = 6; // Initialize health
				do{
                    std::cout << '\n';
                    std::cout << "\nHealth Points: " << healthPoints; // Show remain health
                    std::cout << "\nEnter your guess: ";
                    std::cin >> guessLetter;
                    std::cout << guessLetter;
                    std::cin.clear();
                    healthPoints--;
                }while(healthPoints != 0);
                std::cout << "Game Over!!\n";
                system("pause");
                goto main_menu;
                break;
            case 2: // Show game instructions
            	system("cls");
            	std::cout << "......................................................................." <<'\n';
		        std::cout << ".INSTRUCTIONS:........................................................." <<'\n';
		        std::cout << ".1.Guess the given words by typing a letter............................" <<'\n';
		        std::cout << ".2.One wrong guess will decrease health by 1..........................." <<'\n';
		        std::cout << ".3.Six wrong guesses will be game over................................." <<'\n';
		        std::cout << ".4.Good luck and Have fun!............................................." <<'\n';
		        std::cout << "......................................................................." <<'\n';
		        std::cout << "......................................................................." <<'\n';
		        std::cout << "......................................................................." <<'\n';
		        system("pause");
		        goto main_menu;
            	break;
            case 3: // Confirmation to quit the game.
                std::cout << "Are you sure (Y/N)?: ";
                std::cin >> confirm;
                if (confirm == 'Y' || confirm == 'y') {
                    std::cout << "Thank you for playing! Good Bye!!";
                    return 0;
                } else if (confirm == 'N' || confirm == 'n') {
                    goto main_menu;
                } else {
                    std::cout << "Invalid Choice!\n";
                }
                break;
            default:
                std::cout << "Invalid Choice!\n";
            }
    }while(choice != 2);

    return 0;
}
