#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace std;
#include "crayon.h"

int main()
{
    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Blue);

        // c'est ici qu'on dessine tout
        // window.draw(...);
        Crayon crayon(&window);
        crayon.setTaille(1);
        crayon.setPos_x(200);
        crayon.setPos_y(200);
        for(int i =1; i<7;i++){
            crayon.setAngle(60*i);
            crayon.Move(50);
        }
        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }

    return 0;
}
