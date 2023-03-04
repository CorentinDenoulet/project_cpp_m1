#ifndef INCLUDE_H_MONSTRE
#define INCLUDE_H_MONSTRE

#include <iostream>
#include <string>
#include "personnage.h"

class Monstre : public Personnage {
    protected:
    std::string race;

    public:
    Monstre(int defense, int degats, std::string arme, std::string race, std::string nom);
    std::string recupererRace();
    std::string getRace();
};

#endif