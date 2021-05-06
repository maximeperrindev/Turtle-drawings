#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace std;
#include "crayon.h"
#include "historique.h"

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

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
        window.clear(sf::Color::Black);
        Historique hist;
        Crayon crayon(&window, &hist);
        crayon.setTaille(1);
        crayon.setPos_x(200);
        crayon.setPos_y(200);
        string action = "";
        do{
            cin>>action;
            if(action != "stop"){
                unsigned long parenthesisIndex = action.find('(');
                unsigned long parenthesisEnd = action.find(')');
                string arguments = action.substr(parenthesisIndex+1, parenthesisEnd);
                vector<string> args = split(arguments, ",");
                string function = action.substr(0,parenthesisIndex);
                cout<<function<<endl;
                for(auto i : args) cout<<i<<endl;
                if(function == "avance") crayon.Move(stoi(args[0]));
            }
            for(auto i : hist.getHistorique()) window.draw(i);
            window.display();
        }while(action != "stop");
        // c'est ici qu'on dessine tout
        // window.draw(...);
        /*
        for(int i =1; i<7;i++){
            crayon.setAngle(60*i);
            crayon.Move(50);
        }*/
        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }

    return 0;
}

