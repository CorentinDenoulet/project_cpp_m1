#ifndef INCLUDE_H_CHEVALIER
#define INCLUDE_H_CHEVALIER

#include <iostream>
#include <string>
#include "hero.h"

class Chevalier : public Hero     
{
    public:
    Chevalier(std::string arme, std::string nom);
    void superPouvoir();
};

#endif