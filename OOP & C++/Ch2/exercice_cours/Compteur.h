#include <iostream>
class Compteur
{
private:
    static int ctr;

public:
    Compteur();
    ~Compteur();
};

int Compteur::ctr = 0;

Compteur::Compteur()
{
    std::cout << "Un nouvel objet vient de se creer: " << std::endl;
    std::cout << "Il y a maintenant " << ++ctr << " objets" << std::endl;
    std::cin.get();
}
Compteur::~Compteur()
{
    std::cout << "Un nouvel objet vient de se detruire: " << std::endl;
    std::cout << "Il rest maintenant " << --ctr << " objets" << std::endl;
    std::cin.get();
}