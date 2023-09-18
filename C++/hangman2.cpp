#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int MAX_TRIES = 5;
    int letterFill = 0;
    char letter;
    int num_of_wrong_guesses = 0;
    string word;
    string words[] =
    {
        "apple",
        "banana",
        "orange",
        "grape",
        "pear"
    };

    // Choose a random word from the array
    srand(time(NULL));
    int n = rand() % 5;
    word = words[n];

    // Initialize the secret word with underscores
    string unknown(word.length(), '_');

    // Start the game
    cout << "Welcome to Hangman!" << endl;
    cout << "The word to guess has " << word.length() << " letters." << endl;
    cout << unknown << endl;

    while (num_of_wrong_guesses < MAX_TRIES && letterFill != word.length())
    {
        cout << endl << "Guess a letter: ";
        cin >> letter;

        // Check if the letter is in the word
        bool found = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == letter)
            {
                unknown[i] = letter;
                letterFill++;
                found = true;
            }
        }

        // If the letter is not in the word, increment the number of wrong guesses
        if (!found)
        {
            cout << "Sorry, that letter is not in the word." << endl;
            num_of_wrong_guesses++;
        }

        cout << unknown << endl;
        cout << "You have " << MAX_TRIES - num_of_wrong_guesses << " guesses left." << endl;
    }

    if (num_of_wrong_guesses == MAX_TRIES)
    {
        cout << "Sorry, you lose. The word was " << word << endl;
    }
    else
    {
        cout << "Congratulations, you win!" << endl;
    }

    return 0;
}

