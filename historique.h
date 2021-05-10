//
//  historique.hpp
//  Miniprojet
//
//  Created by Maxime Perrin on 06/05/2021.
//
#include <SFML/Graphics.hpp>
#include <string.h>
#ifndef historique_h
#define historique_h

class Historique {
    std::vector<sf::RectangleShape> tableau_;
    std::vector<std::string> historique_texte_;
public:
    Historique();
    std::vector<sf::RectangleShape> getHistorique(){return tableau_;};
    std::vector<std::string> getHistoriqueTexte(){return historique_texte_;};
    void addEvent(sf::RectangleShape rectangle);
    void addHistorique(std::string commande);
    void clearEvent(){ tableau_.clear();};
    void clearHistorique(){tableau_.clear();};
    void deleteLasteEvent();
};


#endif /* historique_hpp */
