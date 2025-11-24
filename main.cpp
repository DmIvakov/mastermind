#include "Game.h"

#include <iostream>
#include <windows.h>

int getNumberFromUser() {
    int number;
    while (true) {
        std::cout << "Podaj liczbę: ";
        if (std::cin >> number) {
            return number;
        } else {
            std::cin.clear(); 
            std::cin.ignore(); 
            std::cout << "To nie jest liczba! Spróbuj ponownie." << std::endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);      

    int tries = 10;

    std::cout << "Wybierz ilość prób." << std::endl;
    tries = getNumberFromUser();

    Game game(tries);
    game.run();

    return 0;
}
