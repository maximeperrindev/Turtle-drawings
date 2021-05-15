//
//  tortue.hpp
//  Miniprojet
//
//  Created by Maxime Perrin on 10/05/2021.
//

#ifndef tortue_h
#define tortue_h
#include <iostream>
using namespace std;
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Tortue{
    sf::RenderWindow *window_;
    sf::Texture texture_;
    sf::Sprite sprite_;
    float pos_x_;
    float pos_y_;
    float angle_;
    bool visible_;
public:
    Tortue(sf::RenderWindow *window);
    ~Tortue(){delete window_;};
    void move(sf::Vector2f pointA, sf::Vector2f pointB, float factor);
    void draw();
    void rotate(float angle);
    void setVisible(bool visible);
    bool getVisible(){return visible_;};
    void setPosition(float x, float y){sprite_.setPosition(x,y); pos_x_=x;pos_y_=y;};
    sf::Vector2f Interpolate (const sf::Vector2f& pointA,const sf::Vector2f& pointB,float factor);
    sf::Vector2f getPosition(){sf::Vector2f position; position.x =pos_x_;position.y = pos_y_; return position;};
};

#endif /* tortue_hpp */
