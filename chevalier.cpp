#include "chevalier.h"
#include <iostream>
#include <string>

Chevalier::Chevalier(std::string arme, std::string nom):Hero((rand() % (70-50+1)+50), (rand() % (6-4+1)+4), 8, arme, nom){}

void Chevalier::superPouvoir(){
    degats = degats + 5;
}