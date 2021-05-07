//
//  renderer.cpp
//  Miniprojet
//
//  Created by Maxime Perrin on 07/05/2021.
//
#include <iostream>
using namespace std;
#include "renderer.h"

void Renderer::renderLayout(float width, float height){
    /* LOGO */
    sf::Texture logo;
    sf::Sprite logoSprite;
    logoSprite.setPosition(500, 500);
    if (!logo.loadFromFile("assets/logo.png")) cout<<"Erreur lors du chargement du logo"<<endl;
    logo.setSmooth(true);
    logoSprite.setTexture(logo);
    logoSprite.setScale(0.5, 0.5);
    sf::FloatRect spriteSize=logoSprite.getGlobalBounds();
    logoSprite.setOrigin(spriteSize.width/2.,spriteSize.height/2.);
    logoSprite.setPosition(spriteSize.width/4,spriteSize.height/4);
    
    /* Layout */
    sf::RectangleShape drawingForm(sf::Vector2f(width*0.8, height*0.725));
    sf::RectangleShape historiqueForm(sf::Vector2f(width*0.2, height*0.725));
    sf::RectangleShape inputForm(sf::Vector2f(width*0.5, height*0.2));
    sf::RectangleShape lexique(sf::Vector2f(width*0.5, height*0.2));
    sf::RectangleShape input(sf::Vector2f(width*0.5 - 50, height*0.075));
    drawingForm.setPosition(width*0.2,0);
    drawingForm.setOutlineThickness(2);
    drawingForm.setOutlineColor(sf::Color::Black);
    drawingForm.setFillColor(sf::Color::White);
    historiqueForm.setPosition(0,0);
    historiqueForm.setOutlineThickness(2);
    historiqueForm.setOutlineColor(sf::Color::Black);
    historiqueForm.setFillColor(sf::Color(202, 218, 243));
    lexique.setPosition(0,height*0.7);
    lexique.setOutlineThickness(2);
    lexique.setOutlineColor(sf::Color::Black);
    lexique.setFillColor(sf::Color(202, 218, 243));
    inputForm.setOutlineThickness(2);
    inputForm.setOutlineColor(sf::Color::Black);
    inputForm.setPosition(width*0.5,height*0.7);
    inputForm.setFillColor(sf::Color(202, 218, 243));
    input.setPosition(width*0.5 + 25,height*0.7 + 30);
    
    window_->draw(drawingForm);
    window_->draw(historiqueForm);
    window_->draw(inputForm);
    window_->draw(lexique);
    window_->draw(input);
    window_->draw(logoSprite);
}
