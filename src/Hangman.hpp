#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

struct Player {
    int m_nbLife;
};

void        hangmanGame();
std::string chooseRandomWord();
char        askLetterToThePlayer();
bool        isWordFound(std::string playerWord, std::string wordToGuess);
bool        isPlayerAlive(int livesOfPlayer);
bool        isTheLetterInTheWord(char letterChooseByPlayer, std::string wordToGuess);