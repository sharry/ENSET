#include "Employe.h"

class Adherent : public Employe
{
private:
    int montantParticipation;
    std::string dateAdherence;

public:
    int GetMontant() const;
    void SetMontant(int montant);
    void AfficherSalaire() const
    {
        std::cout << "Salaire: " << GetSalaire() << std::endl;
    }
    double GetSalaire() const
    {
        return GetMontant() * salaire;
    }
};
int Adherent::GetMontant() const
{
    return montantParticipation;
}
void Adherent::SetMontant(int montant)
{
    montantParticipation = montant;
}