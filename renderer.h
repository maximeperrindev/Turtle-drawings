//
//  renderer.hpp
//  Miniprojet
//
//  Created by Maxime Perrin on 07/05/2021.
//

#ifndef renderer_h
#define renderer_h

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Renderer{
    sf::RenderWindow *window_;
public:
    Renderer(sf::RenderWindow *window){window_ = window;};
    ~Renderer(){delete window_;};
    void renderLayout(float width, float height);
};

#endif /* renderer_hpp */
