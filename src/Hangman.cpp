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
            std::cout << "Good choice !" << std::endl;
            findingLetterOfTheWordToGuess = updateGuessedWord(letter, wordToGuess, findingLetterOfTheWordToGuess);
        }
        else {
            std::cout << "Nope" << std::endl;
            playerLives--;
            std::cout << "You only have " << playerLives << " lives left." << std::endl;
        }
        std::cout << findingLetterOfTheWordToGuess << std::endl;
    }
    endGameAnnounce(playerLives);
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
    std::cout << "Give a letter :" << std::endl;
    std::cin >> returnLetter;
    return returnLetter;
}

bool isWordFound(const std::string playerWord, const std::string wordToGuess)
{
    return (playerWord == wordToGuess);
}

bool isPlayerAlive(const int livesOfPlayer)
{
    return (livesOfPlayer > 0);
}

bool isTheLetterInTheWord(const char letterChooseByPlayer, const std::string wordToGuess)
{
    return (wordToGuess.find(letterChooseByPlayer) < wordToGuess.size());
}

void findAllOccurances(std::vector<size_t>& vec, const char letterChooseByPlayer, std::string wordToGuess)
{
    size_t pos = wordToGuess.find(letterChooseByPlayer);
    while (pos < wordToGuess.size()) {
        vec.push_back(pos);
        pos = wordToGuess.find(letterChooseByPlayer, pos + 1);
    }
}

std::string updateGuessedWord(const char letterChooseByPlayer, const std::string wordToGuess, std::string wordGuessed)
{
    std::vector<size_t> vec;
    findAllOccurances(vec, letterChooseByPlayer, wordToGuess);
    for (size_t pos : vec) {
        wordGuessed[pos] = wordToGuess[pos];
    }
    return wordGuessed;
}

void endGameAnnounce(const int livesOfPlayer)
{
    if (livesOfPlayer != 0) {
        std::cout << "GG you win and you still have " << livesOfPlayer << " lives !";
    }
    else {
        std::cout << "You loose sorry :(";
    }
}