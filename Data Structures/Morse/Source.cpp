#include "Morse.h"
#include <string>
#include <vector>
// #include "portaudio/portaudio.h"

std::vector<std::string> encode()
{
    std::vector<std::string> result;
    std::string token;
    std::cin >> token;
    for (int i = 0; i < token.size(); i++)
        result.push_back(morse(token[i]));
    return result;
}

char revert(std::string token)
{
    MorseDecoderTree tree;
    init(&tree);
    return decode(&tree, token);
}

int main(int argc, char const *argv[])
{
    std::cout << "Encoding : ";
    auto encoded = encode();
    for (auto letter : encoded)
        std::cout << letter << ' ';
    std::cout << "\nDecoding : ";
    for (auto token : encoded)
        std::cout << revert(token);
    return 0;
}
