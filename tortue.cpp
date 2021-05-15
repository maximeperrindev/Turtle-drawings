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
    sprite_.setRotation(0);
}

void Tortue::move(sf::Vector2f pointA, sf::Vector2f pointB, float factor){
    pos_x_ = pointA.x;
    pos_y_ = pointA.y;
    sprite_.setPosition(Interpolate(pointA, pointB, factor));
}

void Tortue::draw(){
    window_->draw(sprite_);
}

void Tortue::rotate(float angle){
    angle_+=angle;
    sprite_.setRotation(angle_);
}

void Tortue::setVisible(bool visible){
    visible_ = visible;
}

sf::Vector2f Tortue::Interpolate(const sf::Vector2f& pointA,const sf::Vector2f& pointB,float factor) {
    if( factor > 1.f )
        factor = 1.f;

    else if( factor < 0.f )
        factor = 0.f;
    
    return pointA + (pointB - pointA) * factor;
}
