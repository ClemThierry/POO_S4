#include "Hangman.hpp"
#include "random.hpp"

void hangmanGame()
{
    std::string wordToGuess = chooseRandomWord();
    std::string findingLetterOfTheWordToGuess(wordToGuess.size(), '_');

    std::cout << wordToGuess << std::endl;
    std::cout << findingLetterOfTheWordToGuess << std::endl;

    int playerLives = 10;

    while (isPlayerAlive(playerLives) && !isWordFound(findingLetterOfTheWordToGuess, wordToGuess)) {
        char letter = askLetterToThePlayer();
        if (isTheLetterInTheWord(letter, wordToGuess)) {
            // actualiser le mot à chercher
            std::cout << "c'est dans le mot";
        }
        else {
            playerLives--;
        }
    }

    // char   letter  = askLetterToThePlayer();
    // size_t pos     = 0;
    // size_t lastPos = 0;
    // while (wordToGuess.find(letter, pos) < wordToGuess.size()) {
    //     std::cout << "GG elle y est !" << std::endl;
    //     std::cout << pos << std::endl;
    //     findingLetterOfTheWordToGuess[wordToGuess.find(letter, pos + lastPos - 1)] = letter;
    //     lastPos                                                                    = wordToGuess.find(letter, pos);
    //     std::cout << findingLetterOfTheWordToGuess << std::endl;
    //     pos += wordToGuess.find(letter, pos);
    // }
}

std::string chooseRandomWord()
{
    std::vector<std::string> listOfWords = {"chaat",
                                            "chat",
                                            "chien",
                                            "crocodile",
                                            "loup"};
    return listOfWords[0];
}

char askLetterToThePlayer()
{
    char returnLetter;
    std::cout << "Propose une lettre :" << std::endl;
    std::cin >> returnLetter;
    return returnLetter;
}

bool isWordFound(std::string playerWord, std::string wordToGuess)
{
    return (playerWord == wordToGuess);
}

bool isPlayerAlive(int livesOfPlayer)
{
    return (livesOfPlayer > 0);
}

bool isTheLetterInTheWord(char letterChooseByPlayer, std::string wordToGuess)
{
    return (wordToGuess.find(letterChooseByPlayer) < wordToGuess.size());
}