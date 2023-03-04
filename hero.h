#ifndef INCLUDE_H_HERO
#define INCLUDE_H_HERO

#include <iostream>
#include <string>
#include "personnage.h"

class Hero : public Personnage     
{
    public:
    Hero(int vie, int defense, int degats, std::string arme, std::string nom);
    virtual void superPouvoir();
};

#endif