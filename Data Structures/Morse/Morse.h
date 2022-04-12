#include <iostream>
#include <sstream>

std::string morse(char c)
{
    if (c == ' ')
        return "\n";
    std::string dic = ".-  -...-.-.-.. .   ..-.--. ......  .----.- .-..--  -.  --- .--.--.-.-. ... -   ..- ...-.-- -..--.----..";
    int index = c - 'a';
    std::ostringstream strm;
    for (int i = 0; i < 4; i++)
    {
        auto tok = dic[index * 4 + i];
        if (tok == ' ')
            break;
        strm << tok;
    }
    return strm.str();
}

struct MorseDecoderTree
{
    char c;
    MorseDecoderTree *dash;
    MorseDecoderTree *dot;

public:
    MorseDecoderTree() {}
    MorseDecoderTree(char ch) : c(ch), dash(nullptr), dot(nullptr) {}
};

char decode(MorseDecoderTree *tree, std::string morse)
{
    if (morse[0] == '.')
        return decode(tree->dot, morse.substr(1));
    else if (morse[0] == '-')
        return decode(tree->dash, morse.substr(1));
    else
        return tree->c;
}

void init(MorseDecoderTree *head)
{
    head->c = '\0';
    head->dash = new MorseDecoderTree('t');
    head->dot = new MorseDecoderTree('e');
    head->dash->dash = new MorseDecoderTree('m');
    head->dash->dot = new MorseDecoderTree('n');
    head->dot->dash = new MorseDecoderTree('a');
    head->dot->dot = new MorseDecoderTree('i');
    head->dash->dash->dot = new MorseDecoderTree('g');
    head->dash->dash->dash = new MorseDecoderTree('o');
    head->dash->dot->dash = new MorseDecoderTree('k');
    head->dash->dot->dot = new MorseDecoderTree('d');
    head->dot->dash->dash = new MorseDecoderTree('w');
    head->dot->dash->dot = new MorseDecoderTree('r');
    head->dot->dot->dash = new MorseDecoderTree('u');
    head->dot->dot->dot = new MorseDecoderTree('s');
    head->dot->dot->dot->dot = new MorseDecoderTree('h');
    head->dot->dot->dot->dash = new MorseDecoderTree('v');
    head->dot->dot->dash->dot = new MorseDecoderTree('f');
    head->dot->dash->dot->dot = new MorseDecoderTree('l');
    head->dot->dash->dash->dot = new MorseDecoderTree('p');
    head->dot->dash->dash->dash = new MorseDecoderTree('j');
    head->dash->dot->dot->dot = new MorseDecoderTree('b');
    head->dash->dot->dot->dash = new MorseDecoderTree('x');
    head->dash->dot->dash->dot = new MorseDecoderTree('c');
    head->dash->dot->dash->dash = new MorseDecoderTree('y');
    head->dash->dash->dot->dot = new MorseDecoderTree('z');
    head->dash->dash->dot->dash = new MorseDecoderTree('q');
}