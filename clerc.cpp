#include "clerc.h"
#include <iostream>
#include <string>

Clerc::Clerc(std::string arme, std::string nom):Hero((rand() % (60-40+1)+40), (rand() % (5-3+1)+3), 6, arme, nom){}

void Clerc::superPower(){
    vie = vie + 5;
}
