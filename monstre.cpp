#include "monstre.h"
#include <iostream>
#include <string>

Monstre::Monstre(int defense, int degats, std::string arme, std::string race, std::string nom):Personnage((rand() % (60-20+1)+20), defense, degats, arme, nom){
    this->race = race;
}

std::string Monstre::getRace(){
    return this->race;
}
std::string Monstre::recupererRace(){
    return this->race;
}