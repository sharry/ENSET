#include <iostream>

class Vehicule
{
protected:
    int m_prix;

public:
    void Afficher() const
    {
        std::cout << "Ceci est un vehicule."
                  << "\n";
    }
    // virtual void Afficher() const;
};

class Voiture : public Vehicule

{
private:
    int m_portes;

public:
    void Afficher() const
    {
        std::cout << "Ceci est une voiture."
                  << "\n";
    }
};

class Moto : public Vehicule
{
private:
    double m_vitesse;

public:
    void Afficher() const
    {
        std::cout << "Ceci est un moto."
                  << "\n";
    }
};

int main()
{
    Vehicule v;
    v.Afficher();
    Moto m;
    m.Afficher();
    return 0;
}