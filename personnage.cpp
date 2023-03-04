#include "personnage.h"
#include <iostream>
#include <string>

// constructeur

Personnage::Personnage(int vie, int defense, int degats, std::string arme, std::string nom) {
    this->vie = vie;
    this->defense = defense;
    this->degats = degats;
    this->arme = arme;
    this->nom = nom;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
// fonctions d'attaque et de défense

void Personnage::Attaquer(Personnage *p) {
    if (this->degats > p->defense){ // si les dégats sont plus grand que la défense, il s'applique
        std::cout << this->nom << " attaque " << p->nom << " et lui enlève " << this->degats - p->defense << " points de vie" << std::endl;
        p->vie -= this->degats - p->defense;
    }
    else {std::cout << p->nom << " a paré le coup  et ne prend donc pas de dégats !" << std::endl;}    // sinon, on considère le coup bloqué
}

void Personnage::Defendre(Personnage *p){
    p->defense *= 1.75;
    std::cout << nom << " augmente sa défense !" << std::endl;
}
void Personnage::BaisserDefense(Personnage *p){
    p->defense = p->defense / 1.75;
    std::cout << nom << " baisse sa défense !" << std::endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
// fonctions de récupéraiton des statistiqueq

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