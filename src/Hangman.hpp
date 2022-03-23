#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

void        hangmanGame();
std::string chooseRandomWord();
char        askLetterToThePlayer();
bool        isWordFound(const std::string& playerWord);
bool        isPlayerAlive(const int livesOfPlayer);
bool        isTheLetterInTheWord(char letterChooseByPlayer, const std::string wordToGuess);
void        findAllOccurances(std::vector<size_t>& vec, const char letterChooseByPlayer, const std::string wordToGuess);
std::string updateGuessedWord(const char letterChooseByPlayer, const std::string wordToGuess, std::string wordGuessed);
void        endGameAnnounce(const int livesOfPlayer);