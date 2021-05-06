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
void Historique::addEvent(sf::RectangleShape rectangle){
    tableau_.push_back(rectangle);
}
