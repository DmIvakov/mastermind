#ifndef CODE_H
#define CODE_H
#include <string>

class Code {
private:
    int digits[4];

public:
    Code();

    void randomize();
    bool setFromString(const std::string& input);
    int countBlackHits(const Code& guess) const;
    int countWhiteHits(const Code& guess) const;
    void print() const; 
};

#endif