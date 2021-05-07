#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string.h>
using namespace std;
#include "historique.h"
#include "terminal.h"
#include "renderer.h"

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
    Renderer *renderer = new Renderer(&window);
    
    crayon->setCouleur(sf::Color::Black);
    crayon->setPos_x(width*0.2 + width*0.8/2);
    crayon->setPos_y(0 + height*0.725/2);

    /* Police */
    sf::String playerInput;
    sf::Font font;
    if (!font.loadFromFile("assets/LouisGeorgeCafe.ttf")) cout<<"Erreur lors du chargement de la police"<<endl;
    
    
    /* Commande utilisateur */
    sf::Text playerText("",font, 40);
    playerText.setColor(sf::Color::Black);
    playerText.setPosition(width*0.5 + 35, height*0.7 + 35);

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
                /* Trigger entrée*/
                if (event.key.code == sf::Keyboard::Return)
                {
                    terminal->start((string)playerInput);
                    playerInput.clear();
                    playerText.setString("");
                }
                /* Trigger efface texte*/
                if(event.key.code == sf::Keyboard::Backspace)
                {
                    if(playerInput.getSize() != 0){
                        playerInput.erase(playerInput.getSize()-1);
                        playerText.setString(playerInput);
                    }
                }
            }
            /* Trigger saisie du texte*/
            if (event.type == sf::Event::TextEntered)
            {
                if(event.text.unicode != '\n' && event.text.unicode != '\b'){
                    playerInput +=event.text.unicode;
                    playerText.setString(playerInput);
                }
            }
        }
        window.clear(sf::Color::White); //Nettoyage de la fenetre
        renderer->renderLayout(width, height); //Affichage du layout
        window.draw(playerText); //Affichage saisie utilisateur
        for(auto i : crayon->getHistorique()->getHistorique()) window.draw(i); //Affichage du dessin
        window.display(); //Affichage fenetre;
    }

    return 0;
}

