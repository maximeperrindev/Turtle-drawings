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
/*
 Déplacement du crayon
 On dessine un rectangle de longueur val et on le rotate de l'angle angle_
 La position finale du crayon est calculée avec de la trigonométrie
 Entrée : val => la longueur du rectangle a dessiner
 */
void Crayon::Move(int val)
{
        if (enable_ == true) {
            
            //création d'un rectangle de pour chaque point
                
            sf::RectangleShape rectangle(sf::Vector2f(val, taille_));
                
            //Création d'un rectangle de longueur 1 et de largeur taille crayon
            rectangle.setPosition(pos_x_ + taille_/2, pos_y_+taille_/2);
            rectangle.setRotation(angle_);
            rectangle.setFillColor(couleur_);
            historique_->addEvent(rectangle);
        }
            pos_x_ = (val)*cos(degToRad(angle_)) + pos_x_ + taille_/2;
            pos_y_ = (val)*sin(degToRad(angle_)) + pos_y_ + taille_/2;
            if(angle_ != 0){
                pos_x_ += taille_/2;
                pos_y_ += taille_/2;
            }
}
/*
 Retourne à l'action précédente
 */
void Crayon::goBack(){
    float size = historique_->getHistorique()[historique_->getHistorique().size()-1].getSize().x;
    pos_x_ -= (size)*cos(degToRad(angle_));
    pos_y_ -= (size)*sin(degToRad(angle_));
}
/*
 * Défini l'origine
 * Entrée : width => un réel pour la largeur de l'écran, height => un réel pour la hauteur de l'écran
 */
void Crayon::setOrigine(float width, float height){
    o_x = width*0.2 + width*0.8/2;
    o_y = height*0.725/2;
}
/*
 Va à l'origine
 */
void Crayon::goOrigine(){
    pos_x_ = o_x;
    pos_y_ = o_y;
    Move(0);
}
    
