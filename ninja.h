#ifndef INCLUDE_H_NINJA
#define INCLUDE_H_NINJA

#include <iostream>
#include <string>
#include "hero.h"

class Ninja : public Hero     
{
    public:
    Ninja(std::string arme, std::string nom);
    void superPower();
};

#endif