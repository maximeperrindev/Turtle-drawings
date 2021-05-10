//
//  tortue.hpp
//  Miniprojet
//
//  Created by Maxime Perrin on 10/05/2021.
//

#ifndef tortue_h
#define tortue_h

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Tortue{
    sf::RenderWindow *window_;
    sf::Texture texture_;
    sf::Sprite sprite_;
    float pos_x_;
    float pos_y_;
    float angle_;
public:
    Tortue(sf::RenderWindow *window);
    ~Tortue(){delete window_;};
    void move(float x, float y);
    void draw();
    void rotate(float angle);
};

#endif /* tortue_hpp */
