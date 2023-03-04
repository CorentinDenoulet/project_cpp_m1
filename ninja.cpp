#include "ninja.h"
#include <iostream>
#include <string>

Ninja::Ninja(std::string arme, std::string nom):Hero((rand() % (40-30+1)+30), (rand() % (3-1+1)+1), 5, arme, nom){}

void Ninja::superPouvoir(){
    degats = degats*2;
}
