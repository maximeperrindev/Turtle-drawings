//
//  historique.hpp
//  Miniprojet
//
//  Created by Maxime Perrin on 06/05/2021.
//
#include <SFML/Graphics.hpp>
#ifndef historique_h
#define historique_h

class Historique {
    std::vector<sf::RectangleShape> tableau_;
public:
    Historique();
    std::vector<sf::RectangleShape> getHistorique(){return tableau_;};
    void addEvent(sf::RectangleShape rectangle);
};


#endif /* historique_hpp */
