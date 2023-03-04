#ifndef INCLUDE_H_CLERC
#define INCLUDE_H_CLERC

#include <iostream>
#include <string>
#include "hero.h"

class Clerc : public Hero     
{
    public:
    Clerc(std::string arme, std::string nom);
    void superPouvoir();
};

#endif