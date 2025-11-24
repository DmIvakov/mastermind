#include "game.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

Game::Game(int tries) : maxTries(tries) {
    secret.randomize();
}

void Game::run() {
    bool useColors = true;
    #ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE) {
            DWORD dwMode = 0;
            if (GetConsoleMode(hOut, &dwMode)) {
                if (!(dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING))
                    useColors = false;
            }
        }
    #endif

    const std::string RED   = useColors ? "\033[31m" : "";
    const std::string GREEN = useColors ? "\033[32m" : "";
    const std::string YELLOW= useColors ? "\033[33m" : "";
    const std::string CYAN  = useColors ? "\033[36m" : "";
    const std::string RESET = useColors ? "\033[0m"  : "";

    std::system("cls");
    std::cout << CYAN << "Witaj w Mastermind!" << RESET << std::endl;
    std::cout << "Zgadnij 4-cyfrowy kod (cyfry od 1 do 8)." << std::endl;

    for(int attempt = 1; attempt <= maxTries; ++attempt) {
        std::string input;
        Code guess;
        bool valid = false;

        do {
            std::cout << YELLOW << "Próba " << attempt << "/" << maxTries << ": " << RESET;
            std::cin >> input;
            valid = guess.setFromString(input);
            if(!valid)
                std::cout << RED << "Nieprawidłowe dane! Wprowadź 4 cyfry od 1 do 8." << RESET << std::endl;
        } while(!valid);

        int black = secret.countBlackHits(guess);
        int white = secret.countWhiteHits(guess);

        if(black == 4) {
            std::cout << GREEN << "Gratulacje! Odgadłeś kod!" << RESET << std::endl;
            return;
        }

        std::cout << CYAN << "Czarne trafienia: " << black 
                  << " | Białe trafienia: " << white << RESET << std::endl;
    }

    std::cout << RED << "Koniec gry! Kod to: " << RESET;
    secret.print();
}