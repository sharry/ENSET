#include <iostream>

class MorseDecoder
{
private:
    char letter;
    MorseDecoder *dash, *dot;
    MorseDecoder(char letter) : letter(letter), dash(nullptr), dot(nullptr) {}
    char decode_letter(std::string const morse) const
    {
        if (morse[0] == '.')
            return dot->decode_letter(morse.substr(1));
        else if (morse[0] == '-')
            return dash->decode_letter(morse.substr(1));
        else
            return letter;
    }

public:
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

        std::string decode(std::string const morse) const
    {
        std::string encoded_letter = "";
        std::string decoded = "";
        for (int i = 0; i < morse.size(); i++)
        {
            if (morse[i] == '.' || morse[i] == '-')
                encoded_letter += morse[i];
            else if (morse[i] == ' ')
            {
                decoded += decode_letter(encoded_letter);
                encoded_letter.clear();
            }
            else if (morse[i] == '/')
            {
                decoded += decode_letter(encoded_letter);
                decoded += ' ';
                encoded_letter.clear();
            }
        }
        decoded += decode_letter(encoded_letter);
        decoded += ' ';
        return decoded;
    }
};

int main(int argc, char const *argv[])
{
    MorseDecoder decoder;
    std::cout << decoder.decode(". -. ... . - / -- --- .... .- -- -- . -.. .. .-") << std::endl;
}
