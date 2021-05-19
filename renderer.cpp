//
//  renderer.cpp
//  Miniprojet
//
//  Created by Maxime Perrin on 07/05/2021.
//
#include <iostream>
using namespace std;
#include "renderer.h"

/*
 * Création de l'interface de jeu
 * Entrée : width => un réel correspondant à la largeur de l'écran, height => un réel correspondant à la hauteur de l'écran, 
 */
void Renderer::renderLayout(float width, float height){
    /* Logo tortue */
    sf::Texture logo;
    sf::Sprite logoSprite;
    logoSprite.setPosition(500, 500);
    if (!logo.loadFromFile("assets/logo.png")) cout<<"Erreur lors du chargement du logo"<<endl;
    logo.setSmooth(true);
    logoSprite.setTexture(logo);
    logoSprite.setScale(0.4, 0.4);
    sf::FloatRect spriteSize=logoSprite.getGlobalBounds();
    logoSprite.setOrigin(spriteSize.width/2.,spriteSize.height/2.);
    logoSprite.setPosition(spriteSize.width/4,spriteSize.height/4);
    
    /* Police */
    sf::Font font;
    if (!font.loadFromFile("assets/LouisGeorgeCafe.ttf")) cout<<"Erreur lors du chargement de la police"<<endl;
    sf::Text historiqueTitle("Historique :",font, 50);
    historiqueTitle.setFillColor(sf::Color::Black);
    historiqueTitle.setPosition(30, 170);
    
    sf::Text lexiqueTitle("Exemples :",font, 50);
    lexiqueTitle.setFillColor(sf::Color::Black);
    lexiqueTitle.setPosition(30, height*0.8 + 20);
    
    /* Layout/GUI */
    sf::RectangleShape drawingForm(sf::Vector2f(width*0.8, height*0.825));
    sf::RectangleShape historiqueForm(sf::Vector2f(width*0.3, height*0.825));
    sf::RectangleShape historique(sf::Vector2f(width*0.3-30, height*0.45));
    sf::RectangleShape inputForm(sf::Vector2f(width*0.5, height*0.2));
    sf::RectangleShape lexique(sf::Vector2f(width*0.5, height*0.2));
    sf::RectangleShape input(sf::Vector2f(width*0.5 - 50, height*0.075));
    drawingForm.setPosition(width*0.3,0);
    drawingForm.setOutlineThickness(2);
    drawingForm.setOutlineColor(sf::Color::Black);
    drawingForm.setFillColor(sf::Color::White);
    historiqueForm.setPosition(0,0);
    historiqueForm.setOutlineThickness(2);
    historiqueForm.setOutlineColor(sf::Color::Black);
    historiqueForm.setFillColor(sf::Color(202, 218, 243));
    historique.setPosition(15,250);
    historique.setOutlineThickness(2);
    historique.setOutlineColor(sf::Color::Black);
    lexique.setPosition(0,height*0.8);
    lexique.setOutlineThickness(2);
    lexique.setOutlineColor(sf::Color::Black);
    lexique.setFillColor(sf::Color(202, 218, 243));
    inputForm.setOutlineThickness(2);
    inputForm.setOutlineColor(sf::Color::Black);
    inputForm.setPosition(width*0.5,height*0.8);
    inputForm.setFillColor(sf::Color(202, 218, 243));
    input.setOutlineThickness(1);
    input.setOutlineColor(sf::Color::Black);
    input.setPosition(width*0.5 + 25,height*0.8 + 30);
    
    /* Rendering/Affichage */
    window_->draw(drawingForm);
    window_->draw(historiqueForm);
    window_->draw(historique);
    window_->draw(historiqueTitle);
    window_->draw(inputForm);
    window_->draw(lexique);
    window_->draw(lexiqueTitle);
    window_->draw(input);
    window_->draw(logoSprite);
}
