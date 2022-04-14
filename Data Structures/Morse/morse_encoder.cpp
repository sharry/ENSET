#include <iostream>
#include <sstream>
#include <vector>

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

std::vector<std::string> encode()
{
    std::vector<std::string> result;
    std::string token;
    std::cin >> token;
    for (int i = 0; i < token.size(); i++)
        result.push_back(morse(token[i]));
    return result;
}

int main(int argc, char const *argv[])
{
    std::cout << "Encoding : ";
    auto encoded = encode();
    std::cout << '{';
    for (auto letter : encoded)
    {
        std::cout << '"' << letter << '"';
        if (letter != encoded.back())
            std::cout << ", ";
    }
    std::cout << '}';
    return 0;
}
