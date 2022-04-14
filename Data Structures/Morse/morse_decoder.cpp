#include <iostream>
#include <vector>

class MorseDecoder
{
private:
    char letter;
    MorseDecoder *dash, *dot;

public:
    MorseDecoder(char letter) : letter(letter), dash(nullptr), dot(nullptr) {}
    MorseDecoder()
    {
        letter = '\0';
        dash = new MorseDecoder('t');
        dot = new MorseDecoder('e');
        dash->dash = new MorseDecoder('m');
        dash->dot = new MorseDecoder('n');
        dot->dash = new MorseDecoder('a');
        dot->dot = new MorseDecoder('i');
        dash->dash->dot = new MorseDecoder('g');
        dash->dash->dash = new MorseDecoder('o');
        dash->dot->dash = new MorseDecoder('k');
        dash->dot->dot = new MorseDecoder('d');
        dot->dash->dash = new MorseDecoder('w');
        dot->dash->dot = new MorseDecoder('r');
        dot->dot->dash = new MorseDecoder('u');
        dot->dot->dot = new MorseDecoder('s');
        dot->dot->dot->dot = new MorseDecoder('h');
        dot->dot->dot->dash = new MorseDecoder('v');
        dot->dot->dash->dot = new MorseDecoder('f');
        dot->dash->dot->dot = new MorseDecoder('l');
        dot->dash->dash->dot = new MorseDecoder('p');
        dot->dash->dash->dash = new MorseDecoder('j');
        dash->dot->dot->dot = new MorseDecoder('b');
        dash->dot->dot->dash = new MorseDecoder('x');
        dash->dot->dash->dot = new MorseDecoder('c');
        dash->dot->dash->dash = new MorseDecoder('y');
        dash->dash->dot->dot = new MorseDecoder('z');
        dash->dash->dot->dash = new MorseDecoder('q');
    }

    char decode_letter(std::string morse)
    {
        if (morse[0] == '.')
            return dot->decode_letter(morse.substr(1));
        else if (morse[0] == '-')
            return dash->decode_letter(morse.substr(1));
        else
            return letter;
    }
    std::string decode(std::vector<std::string> morse)
    {
        std::string decoded;
        for (std::string m : morse)
            decoded += decode_letter(m);
        return decoded;
    }
};

int main(int argc, char const *argv[])
{
    MorseDecoder decoder;
    std::vector<std::string> morse = {"....", ".", ".-..", ".--."};
    std::cout << decoder.decode(morse) << std::endl;
}
