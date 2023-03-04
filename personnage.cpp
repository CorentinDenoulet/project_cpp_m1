#include "personnage.h"
#include <iostream>
#include <string>


Personnage::Personnage(int vie, int defense, int degats, std::string arme, std::string nom) {
    this->vie = vie;
    this->defense = defense;
    this->degats = degats;
    this->arme = arme;
    this->nom = nom;
}
void Personnage::Attaquer(Personnage *p) {
    if (this->degats > p->defense){ 
        std::cout << this->nom << " attaque " << p->nom << " et lui enlève " << this->degats - p->defense << " points de vie" << "\n"<< std::endl;
        p->vie -= this->degats - p->defense;
    }
    else {std::cout << p->nom << " a paré le coup  et ne prend donc pas de dégats !\n" << std::endl;}    
}
void Personnage::Defendre(Personnage *p){
    p->defense *= 1.75;
    std::cout << nom << " augmente sa défense !\n" << std::endl;
}
int Personnage::recupererVie(){
    return this->vie;
}
int Personnage::recupererDefense(){
    return this->defense;
}
int Personnage::recupererDegats(){
    return this->degats;
}
std::string Personnage::recupererArme(){
    return this->arme;
}
std::string Personnage::recupererNom(){
    return this->nom;
}