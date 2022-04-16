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

std::string encode(std::string text)
{
    std::string encoded = "";
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
            encoded += '/';
        else
            encoded += morse(tolower(text[i]));
        if (i != text.size() - 1)
            encoded += ' ';
    }
    return encoded;
}

int main(int argc, char const *argv[])
{
    std::cout << "Enter the text to encode: ";
    std::string text;
    std::getline(std::cin, text);
    std::cout << "\n(" << text << ") in morse code: " << encode(text) << std::endl;
    return 0;
}
