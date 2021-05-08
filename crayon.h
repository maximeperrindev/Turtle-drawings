//
//  crayon.h
//  Miniprojet
//
//  Created by Maxime Perrin on 06/05/2021.
//
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "historique.h"

class Crayon {
    float taille_;
    sf::Color couleur_;
    bool enable_;
    int pos_x_;
    int pos_y_;
    float angle_;
    sf::RenderWindow *window_;
    Historique *historique_;
public:
    Crayon(sf::RenderWindow *window,Historique *historique,float taille = 1, sf::Color couleur = sf::Color::Black bool enable = true, int pos_x = 0, int pos_y = 0, float angle = 0);
    ~Crayon();
    void Move(int val);
    int getTaille() { return taille_; };
    sf::Color getCouleur() { return couleur_; };
    bool getEnable() { return enable_; };
    int getPos_x() { return pos_x_; };
    int getPos_y() { return pos_y_; };
    float getAngle() { return angle_; };
    void setAngle(float angle) { angle_ += angle; };
    void setTaille(float taille) { taille_ = taille; };
    void setCouleur(sf::Color color) { couleur_ = color; };
    void setEnable(bool enable) { enable_ = enable; };
    void setPos_x(int pos_x){pos_x_ = pos_x;};
    void setPos_y(int pos_y){pos_y_ = pos_y;};
    sf::RenderWindow* getWindow(){return window_;};
    Historique* getHistorique(){return historique_;};

};
