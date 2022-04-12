#include <iostream>

class Liste
{
private:
    int taille;
    float *adr;

public:
    Liste(int);
    Liste(const Liste &);
    ~Liste();
};

Liste::Liste(int t)
{
    taille = t;
    adr = new float[taille];
    std::cout << "\nConstruction";
    std::cout << "\nAdresse de l'objet: " << this;
    std::cout << "\nAdresse de la liste: " << adr;
}

Liste::Liste(const Liste &v)
{
    taille = v.taille;
    adr = new float[taille];
    for (int i = 0; i < taille; i++)
        adr[i] = v.adr[i];
    std::cout << "\nConstructeur par recopie";
    std::cout << "Adresse de l'objet: " << this;
    std::cout << "Adresse de la liste: " << adr;
}

Liste::~Liste()
{
    std::cout << "\nDestruction";
    std::cout << "\nAdresse de l'objet: " << this;
    std::cout << "\nAdresse de la liste: " << adr;
    delete[] adr;
}

int main(int argc, char const *argv[])
{
    std::cout << "Debut du programme\n";
    Liste a(3);
    Liste b = a;
    std::cout << "\nFin du programme\n";
    return 0;
}
