#include <iostream>

class Liste
{
private:
    int taille;
    float *adr;

public:
    Liste(int);
    ~Liste();
};

Liste::Liste(int t)
{
    taille = t;
    adr = new float[t];
    std::cout << "Constructeur de la liste de taille " << taille << std::endl;
    std::cout << "Son adresse (" << this << ')' << std::endl;
}

Liste::~Liste()
{
    std::cout << "Destructeur de la liste de taille " << taille << std::endl;
    std::cout << "Son adresse (" << this << ')' << std::endl;
    delete[] adr;
}

int main(int argc, char const *argv[])
{
    std::cout << "Debut du programme\n";
    Liste a(3);
    Liste b = a;
    std::cout << "Fin du programme\n";
    return 0;
}
