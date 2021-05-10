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
    if (!texture_.loadFromFile("assets/logo.png"))
    {
    }
    texture_.setSmooth(true);
    sprite_.setTexture(texture_);
    sf::FloatRect spriteSize=sprite_.getGlobalBounds();
    sprite_.setOrigin(spriteSize.width/2.,spriteSize.height/2.);
    sprite_.setScale(0.15, 0.15);
    sprite_.setPosition(pos_x_,pos_y_);
    sprite_.setRotation(90);
}

void Tortue::move(float x, float y){
    pos_x_ = x;
    pos_y_ = y;
    sprite_.setPosition(pos_x_, pos_y_);
}

void Tortue::draw(){
    window_->draw(sprite_);
}

void Tortue::rotate(float angle){
    angle_+=angle;
    sprite_.setRotation(90+angle_);
}
