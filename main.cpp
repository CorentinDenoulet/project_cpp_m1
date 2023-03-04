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
    char afficher = 'n';

    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Introduction

    cout << "Bienvenue sur mon projet de fin de semestre de C++ !\n" << endl;
    cout << "Le pricipe est simple, une équipe de héros combat une équipe de monstres au tour par tour,\nà chaque tour, vous devez choisir ce que doivent faire les héros pour les mener à la victoire !\n\n" << endl;

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

    cout << "-------------------------------------------------------------------------------------------" << endl; // facilité la lecture lors du jeu

    for (Hero hero : equipehero){ // résumé des héros
        cout<< "Nom : " << hero.recupererNom() << "\n   Vie : " << hero.recupererVie() << "\n   Arme : " << hero.recupererArme() << "\n   Dégats : " << hero.recupererDegats() << "\n Défense : " << hero.recupererDefense() << "\n"  << endl;      
    }

    cout << "-------------------------------------------------------------------------------------------" << endl; 

    while (afficher != 'y'){     // tant que l'on ne sélectionne pas une classe
            cout << "\nEntrez 'y' pour continuer l'affichage : \n ";   // on laisse le choix
            cin >> afficher;
        }
        cin.ignore();
        afficher = 'n';

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
    
    cout << "-------------------------------------------------------------------------------------------" << endl;

    // -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Déroulement de la partie

    int comptour = 0;
    vector<Hero> baisserdefensehero;

    while (equipehero.size() != 0 && equipemonstre.size() != 0){   // tant que tous les membres d'une équipe ne sont pas morts

        comptour ++;
        cout << "\n\nTour n° : " << comptour << endl;
        cout << "Au tour des héros : \n\n" << endl;

        for (Hero hero : equipehero){   // pour chaque héro
            int actHero = 0;
            while (actHero != 1 && actHero != 2 && actHero != 3){ // demande à l'utilisateur ce que fait le héro
                switch (comptour % 3){
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
                    baisserdefensehero.push_back(hero);
                    break;
                case 3 :
                    if (comptour % 3 == 0){ // ou on utilise son super pouvoir si le tour est un multiple de 3
                        hero.superPouvoir();
                    }  
                    else {cout << "Un héro ne peut utiliser son super pouvoir que tous les 3 tours, son attaque sera donc basique.\n" << endl;}
                    hero.Attaquer(&equipemonstre[(rand() % equipemonstre.size())]);
                    break;
            }
        }

        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "Les monstres attaquent ! \n" << endl;

        for (Monstre monstre : equipemonstre){
            if (monstre.recupererVie() > 0){
                monstre.Attaquer(&equipehero[(rand() % equipehero.size())]);
            }
        }

        cout << "-------------------------------------------------------------------------------------------" << endl;

        if (baisserdefensehero.size() != 0){        // on redescend la défense des héros qui se la sont augmentée
            for (Hero hero : baisserdefensehero){
                hero.BaisserDefense(&hero);
            }
        }

        baisserdefensehero.clear(); // on vide le vecteur

        // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // Suppression des personnages vaincu

        for (int i = 0 ; i < equipehero.size()+ 1 ; i++){          // si la vie d'un héro est négative ou null, on le retire de la liste
            if (equipehero[i].recupererVie() < 1){
                equipehero.erase(equipehero.begin()+i);
            }
        }

        for (int i = 0 ; i < equipemonstre.size()+1 ; i++){       // si la vie d'un monstre est négative ou null, on le retire de la liste
            if (equipemonstre[i].recupererVie() < 1){
                equipemonstre.erase(equipemonstre.begin()+i);
            }
        }

        // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        // Récapitulatif du tour

        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "Conclusion du tour :" << endl; 

        for (Hero hero : equipehero){
            cout<< "Nom : " << hero.recupererNom() << "\n   Vie : " << hero.recupererVie() << "\n Défense : "<< hero.recupererDefense() << endl;      
        }

        while (afficher != 'y'){     // tant que l'on ne sélectionne pas une classe
            cout << "\nEntrez 'y' pour continuer l'affichage : \n ";   // on laisse le choix
            cin >> afficher;
        }
        cin.ignore();
        afficher = 'n';

        for (Monstre monstre : equipemonstre){
            cout<< "Nom : " << monstre.recupererNom() << "\n   Vie : " << monstre.recupererVie() << endl;
        }

        cout << "-------------------------------------------------------------------------------------------" << endl;
    }
    
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Annonce vainqueur et message de fin

    if (equipehero.size() == 0){
        cout << "Les monstres ont gagné !\n\n" << endl;
    }
    else {cout << "Les héros ont gagnés !\n\n";}

    cout << "Ce jeu a été développé par Corentin Denoulet dans le cadre de son projet de fin de semestre de C++ en M1 à JUNIA ISEN Lille" << endl;
    cout << "Merci d'avoir joué et à bientot !" << endl;

}