//
//  historique.cpp
//  Miniprojet
//
//  Created by Maxime Perrin on 06/05/2021.
//

#include "historique.h"

Historique::Historique(){
    tableau_ = {};
}
/*
 * Ajoute un rectangle dans un vecteur de rectangle
 * Entrée : rectangle => le rectangle à stocker
 */
void Historique::addEvent(sf::RectangleShape rectangle){
    tableau_.push_back(rectangle);
}
/*
 * Ajoute un string correspondant à un evenement dans l'historique
 * Entrée : commande => le string à stocker
 */
void Historique::addHistorique(std::string commande){
    historique_texte_.insert(historique_texte_.begin(),commande);
}
/*
 * Supprime le dernier rectangle stocké
 */
void Historique::deleteLasteEvent(){
    tableau_.pop_back();
}
