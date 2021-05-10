//
//  crayon.c
//  Miniprojet
//
//  Created by Maxime Perrin on 06/05/2021.
//
#include "crayon.h"

Crayon::Crayon(sf::RenderWindow * window,Historique *historique,Tortue *tortue,float taille, sf::Color couleur, bool enable, int pos_x, int pos_y, float angle){
    window_ = window;
    historique_ = historique;
    taille_ = taille;
    couleur_ = couleur;
    enable_ = enable;
    pos_x_ = pos_x;
    pos_y_ = pos_y;
    angle_ = angle;
    tortue_ = tortue;
}

Crayon::~Crayon(){
    delete historique_;
    delete window_;
    delete tortue_;
}

void Crayon::Move(int val)
{
        if (enable_ == true) {
            
            //création d'un rectangle de pour chaque point
                
            sf::RectangleShape rectangle(sf::Vector2f(val, taille_));
                
            //Création d'un rectangle de longueur 1 et de largeur taille crayon
            rectangle.setPosition(pos_x_, pos_y_);
            rectangle.setRotation(angle_);
            rectangle.setFillColor(couleur_);
            historique_->addEvent(rectangle);
        }
            //delay pour la vitesse
            pos_x_ = (val)*cos(degToRad(angle_)) + pos_x_;
            pos_y_ = (val)*sin(degToRad(angle_)) + pos_y_;
            if(angle_ != 0){
                pos_x_ += taille_/2;
                pos_y_ += taille_/2;

            }
            tortue_->move(pos_x_, pos_y_);
            
}

void Crayon::goBack(){
    float size = historique_->getHistorique()[historique_->getHistorique().size()-1].getSize().x;
    pos_x_ -= (size)*cos(degToRad(angle_));
    pos_y_ -= (size)*sin(degToRad(angle_));
    tortue_->move(pos_x_, pos_y_);
    
    
}
    
