#include "personnage.h"
#include "hero.h"
#include "chevalier.h"
#include "clerc.h"
#include "ninja.h"
#include "monstre.h"

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>


int main(int argc, char *argv[]){

    srand(time(NULL));

    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Introduction

    cout << "Bienvenue sur mon projet de fin de semestre de C++ !\n" << endl;
    cout << "Le pricipe est simple, une équipe de héros combat une équipe de monstres au tour par tour,\nvous devrez choisir ce que doivent faire les héros pour les mener à la victoire !\n\n" << endl;

    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Génération des équipes
    
    vector<Hero> equipehero; 

    while (equipehero.size() < 4){
        int selectclasse = 0;     // variable de sélection de la classe
        string nom  = "";           // variable du nom
        while (selectclasse != 1 && selectclasse != 2 && selectclasse != 3){     // tant que l'on ne sélectionne pas une classe
            cout << "Choisissez la classe du héro :\n   [1] Chevalier\n   [2] Clerc\n   [3] Ninja\n ";   // on laisse le choix
            cin >> selectclasse;
        }
        cin.ignore();

        while (nom == ""){          // tant que le nom est vide
            cout << "\nEntrez le nom du héro:\n-> ";
            getline(cin, nom);      // on demande à l'utilisateur d'entrer un nom
        }

        int selectarme = rand() % 2;        // variable de sélection de l'arme (le choix est aléatoire)
        switch (selectclasse){
            case 1 :
                equipehero.push_back(Chevalier((selectarme == 0 ? "Hallebarde" : "Epee longue"), nom));            // création d'un chevalier
                break;
            case 2 :
                equipehero.push_back(Clerc((selectarme == 0 ? "Masse" : "Hache"), nom));                           // création d'un clerc
                break;
            case 3 :
                equipehero.push_back(Ninja("Sai", nom));                                                           // création d'un ninja
                break;
        }
    }

    for (Hero hero : equipehero){ // résumé des héros
        cout<< "Nom : " << hero.recupererNom() << "\n   Vie : " << hero.recupererVie() << "\n   Arme : " << hero.recupererArme() << "\n   Dégats : " << hero.recupererDegats() << "\n Défense : " << hero.recupererDefense() << "\n"  << endl;      
    }

 
    vector<Monstre> equipemonstre;
    int compteurmonstre = 1;
    while (equipemonstre.size() < 10){
        string races[] = {"orc", "goblin"};
        string armes[] = {"hache", "gourdin"};

        int selectrace = rand() % 2;     // variable de sélection de la race du monstre
        int selectarme = rand () % 2;    // variable de sélection de l'arme du monstre

        string race = races[selectrace];
        string arme = armes[selectarme];
        int degatHache = (rand() % (6-4+1)+4);
        string nommonstre = "monstre" + to_string(compteurmonstre);

        if (race == "orc"){     // création du monstre de façon aléatoire
            if (arme == "hache"){
                equipemonstre.push_back(Monstre(degatHache, 8, arme, race, nommonstre));
                compteurmonstre += 1;
            }
            else {
                equipemonstre.push_back(Monstre((rand() % (6-4+1)+4), 5, arme, race, nommonstre));
                compteurmonstre += 1;
            }
        }
        else {
            if (arme == "hache"){
                equipemonstre.push_back(Monstre(degatHache, 8, arme, race, nommonstre));
                compteurmonstre += 1;
            }
            else {
                equipemonstre.push_back(Monstre((rand() % (4-2+1)+2), 5, arme, race, nommonstre));
                compteurmonstre += 1;
            }
        }
    }

    for (Monstre monstre : equipemonstre){  // résumé des monstres
        cout<< "Nom : " << monstre.recupererNom() << "\n Race : " << monstre.recupererRace() << "\n   Vie : " << monstre.recupererVie() << "\n   Arme : " << monstre.recupererArme() << "\n   Dégats : " << monstre.recupererDegats() << "\n   Défense : " << monstre.recupererDefense() << "\n" << endl;      
    }
    
    // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Déroulement de la partie

    int tourCompteur = 0;

    while (equipehero.size() != 0 && equipemonstre.size() != 0){   // tant que tous les membres d'une équipe ne sont pas morts
        tourCompteur ++;
        cout << "Tour n° : " << tourCompteur << "\n\n" << endl;

        for (Hero hero : equipehero){   // pour chaque hero
            int actHero = 0;
            while (actHero != 1 && actHero != 2 && actHero != 3){ // demande à l'utilisateur ce que fait un hero
                switch (tourCompteur % 3){
                    case 0:
                        cout << "Que doit faire : " << hero.recupererNom() << "? :\n" << "    [1] Attaquer\n    [2] Défendre\n    [3] Utiliser son super pouvoir\n";
                        break;
                    default:
                        cout << "Que doit faire : " << hero.recupererNom() << "? :\n" << "    [1] Attaquer\n    [2] Défendre\n";
                        break;
                }
                cin >> actHero;
            }
            switch (actHero){   // en fonction de l'action choisit
                case 1 :
                    hero.Attaquer(&equipemonstre[(rand() % equipemonstre.size())]);  // on attaque
                    break;
                case 2 :
                    hero.Defendre(&hero);    // on défend
                    break;
                case 3 :
                    if (tourCompteur % 3 == 0){hero.superPouvoir();}  // ou on utilise son super pouvoir si l'on peut
                    else {cout << "Un héro ne peut utiliser son super pouvoir que tous les 3 tours, son attaque sera donc basique.\n" << endl;}
                    hero.Attaquer(&equipemonstre[(rand() % equipemonstre.size())]);
                    break;
            }
        }

        for (Monstre monstre : equipemonstre){
            if (monstre.recupererVie() > 0){
                monstre.Attaquer(&equipehero[(rand() % equipehero.size())]);
            }
        }

        // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // Suppression des personnages vaincu
        for (int i = 0 ; i < equipehero.size() ; i++){
            if (equipehero[i].recupererVie() <= 0){
                equipehero.erase(equipehero.begin()+i);
            }
        }
        for (int i = 0 ; i < equipemonstre.size() ; i++){
            if (equipemonstre[i].recupererVie() <= 0){
                equipemonstre.erase(equipemonstre.begin()+i);
            }
        }

        // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // Récapitulatif du tour

        for (Hero hero : equipehero){
            cout<< "Nom : " << hero.recupererNom() << "\n   Vie : " << hero.recupererVie() << "\n   Arme : " << hero.recupererArme() << "\n   Dégats : " << hero.recupererDegats() << "\n   Défense : " << hero.recupererDefense() << "\n"  << endl;      
        }
        for (Monstre monstre : equipemonstre){
            cout<< "Nom : " << monstre.recupererNom() << "\n Race : " << monstre.recupererRace() << "\n   Vie : " << monstre.recupererVie() << "\n   Arme : " << monstre.recupererArme() << "\n   Dégats : " << monstre.recupererDegats() << "\n Défense : " << monstre.recupererDefense() << "\n" << endl;      
        }
    }
    if (equipehero.size() == 0){
        cout << "Les monstres ont gagné !" << endl;
    }
    else {cout << "Les héros ont gagnés !";}
}