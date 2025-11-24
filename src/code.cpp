#include "code.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Code::Code() {
    for(int i = 0; i < 4; ++i) digits[i] = 0;
}

void Code::randomize() {
    std::srand(std::time(nullptr));

    for(int i = 0; i < 4; ++i) {
        int num;
        bool unique;

        do {
            num = 1 + std::rand() % 8;
            unique = true;

            for(int j = 0; j < i; ++j) {
                if(digits[j] == num) {
                    unique = false;
                    break;
                }
            }
        } while(!unique);

        digits[i] = num;
    }
}

bool Code::setFromString(const std::string& input) {
    if(input.length() != 4) return false;
    for(int i = 0; i < 4; ++i) {
        if(input[i] < '1' || input[i] > '8') return false;
        digits[i] = input[i] - '0';
    }
    return true;
}

int Code::countBlackHits(const Code& guess) const {
    int count = 0;
    for(int i = 0; i < 4; ++i)
        if(digits[i] == guess.digits[i])
            ++count;
    return count;
}

int Code::countWhiteHits(const Code& guess) const {
    int count = 0;
    int secretCount[9] = {0};
    int guessCount[9] = {0};

    for(int i = 0; i < 4; ++i) {
        if(digits[i] != guess.digits[i]) {
            secretCount[digits[i]]++;
            guessCount[guess.digits[i]]++;
        }
    }

    for(int i = 1; i <= 8; ++i)
        count += (secretCount[i] < guessCount[i]) ? secretCount[i] : guessCount[i];

    return count;
}

void Code::print() const {
    for(int i = 0; i < 4; ++i)
        std::cout << digits[i];
    std::cout << std::endl;
}
