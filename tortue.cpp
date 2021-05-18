//
//  tortue.cpp
//  Miniprojet
//
//  Created by Maxime Perrin on 10/05/2021.
//

#include "tortue.h"

Tortue::Tortue(sf::RenderWindow *window){
    window_ = window;
    pos_x_ = 0;
    pos_y_ = 0;
    angle_ = 0;
    visible_ = true;
    if (!texture_.loadFromFile("assets/logo.png"))
    {
    }
    texture_.setSmooth(true);
    sprite_.setTexture(texture_);
    sf::FloatRect spriteSize=sprite_.getGlobalBounds();
    sprite_.setOrigin(spriteSize.width/2.,spriteSize.height/2.);
    sprite_.setScale(0.2, 0.2);
    sprite_.setPosition(pos_x_,pos_y_);
    sprite_.setRotation(90);
}
/*
 * Déplacement de la tortue en fonction du crayon et avec une vitesse
 * Entrée : pointA et pointB => un vecteur de position correspondant au point de départ et d'arrivée, factor => un réel contenant la vitesse de déplacement calculée
 */
void Tortue::move(sf::Vector2f pointA, sf::Vector2f pointB, float factor){
    pos_x_ = Interpolate(pointA, pointB, factor).x;
    pos_y_ = Interpolate(pointA, pointB, factor).y;
    cout<<Interpolate(pointA, pointB, factor).x<<" "<<Interpolate(pointA, pointB, factor).y<<endl;
    cout<<pos_x_<<" "<<pos_y_<<endl;
    sprite_.setPosition(Interpolate(pointA, pointB, factor));
}

/*
 * Rendu du sprit dans la fenêtre
 */
void Tortue::draw(){
    window_->draw(sprite_);
}

/*
 * Rotation du sprite en fonction d'un angle
 * Entrée : angle => un réel
 */
void Tortue::rotate(float angle){
    angle_+=angle;
    sprite_.setRotation(90+angle_);
}

/*
 * Défini l'état de visibilité de la tortue
 * Entrée : visbile => un booléen
 */
void Tortue::setVisible(bool visible){
    visible_ = visible;
}

/*
 * Fonction d'interpolation pour calculer le chemin à prendre entre deux points
 * Entrée : pointA et pointB => deux vecteurs de position, factor => un réel contenant la vitesse
 * Sortie : un vecteur de position correspondant à la position calculée
 */
sf::Vector2f Tortue::Interpolate(const sf::Vector2f& pointA,const sf::Vector2f& pointB,float factor) {
    if( factor > 1.f )
        factor = 1.f;

    else if( factor < 0.f )
        factor = 0.f;
    
    return pointA + (pointB - pointA) * factor;
}
