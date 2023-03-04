#ifndef INCLUDE_H_PERSONNAGE
#define INCLUDE_H_PERSONNAGE

#include <iostream>
#include <string>

class Personnage
{
    protected:
    int vie;
    int defense;
    int degats;
    std::string arme;
    std::string nom;
    int tmpDamage;

    public:
    Personnage(int vie, int defense, int degats, std::string arme, std::string nom);
    void Attaquer(Personnage *p);
    void Defendre(Personnage *p);
    void BaisserDefense(Personnage *p);
    int recupererVie();
    int recupererDefense();
    int recupererDegats();
    std::string recupererArme();
    std::string recupererNom();
};

#endif