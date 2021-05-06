#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string.h>
using namespace std;
#include "historique.h"
#include "terminal.h"

int main()
{
    // création de la fenêtre
    std::vector<sf::VideoMode> i = sf::VideoMode::getFullscreenModes();
    sf::RenderWindow window(i.front(), "Logo translate");
    unsigned int width = i.front().width; //Largeur de la fenêtre
    unsigned int height = i.front().height; //Hauteur de la fenêtre
    Historique *hist = new Historique();
    Crayon *crayon = new Crayon(&window, hist);
    Terminal *terminal = new Terminal(crayon);
    crayon->setTaille(1);
    crayon->setPos_x(200);
    crayon->setPos_y(200);
    /* Police */
    sf::String playerInput;
    sf::Font font;
    if (!font.loadFromFile("assets/LouisGeorgeCafe.ttf")) cout<<"Erreur lors du chargement de la police"<<endl;
    
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
    
    /* Commande utilisateur */
    sf::Text playerText("",font, 40);
    playerText.setPosition(60,300);
    playerText.setColor(sf::Color::Black);

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Return)
                {
                    playerInput.clear();
                    playerText.setString("");
                }
            }
            if (event.type == sf::Event::TextEntered)
            {
                if(event.text.unicode != '\n'){
                    playerInput +=event.text.unicode;
                    playerText.setString(playerInput);
                    cout<<(string)playerInput<<endl;
                }
            }
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);


        //terminal->start();
        
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
        playerText.setPosition(width*0.5 + 35, height*0.7 + 35);
        window.draw(drawingForm);
        window.draw(historiqueForm);
        window.draw(inputForm);
        window.draw(lexique);
        window.draw(input);
        window.draw(playerText);
        window.draw(logoSprite);

        window.display();
    }

    return 0;
}

