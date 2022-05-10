#include <iostream>
#include <sstream>

class Employe
{
protected:
    int matricule;
    std::string nom;
    double salaire;
    int age;

public:
    Employe();
    ~Employe();
    std::string ToString() const;
    double GetSalaire() const;
    void SetSalaire(double salaire);
    int GetAge() const;
    void SetAge(int age);
    void AfficherSalaire() const;
    void AfficherAge() const;
};

Employe::Employe() {}
Employe::~Employe() {}
std::string Employe::ToString() const
{
    std::ostringstream ss;
    ss << "Employe " << nom << " (" << matricule << ")\n";
    ss << "Salaire: " << salaire << "\n";
    ss << "Age: " << age << "\n";
    return ss.str();
}
double Employe::GetSalaire() const
{
    return salaire;
}
void Employe::SetSalaire(double salaire)
{
    this->salaire = salaire;
}
int Employe::GetAge() const
{
    return age;
}
void Employe::SetAge(int age)
{
    this->age = age;
}
void Employe::AfficherSalaire() const
{
    std::cout << "Salaire: " << salaire << std::endl;
}