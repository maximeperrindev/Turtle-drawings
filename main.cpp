#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string.h>
using namespace std;
#include "historique.h"
#include "terminal.h"
#include "renderer.h"
#include "filesystem.h"
#include "tortue.h"

int main()
{
    // création de la fenêtre
    std::vector<sf::VideoMode> i = sf::VideoMode::getFullscreenModes();
    sf::RenderWindow window(i.front(), "Logo translate");
    unsigned int width = i.front().width; //Largeur de la fenêtre
    unsigned int height = i.front().height; //Hauteur de la fenêtre
    
    
    Historique *hist = new Historique();
    Tortue *tortue = new Tortue(&window);
    Crayon *crayon = new Crayon(&window, hist, tortue);
    Terminal *terminal = new Terminal(crayon);
    Renderer *renderer = new Renderer(&window);
    FileSystem *file = new FileSystem("", hist);

    crayon->setOrigine(width, height);
    crayon->goOrigine();
    tortue->move(crayon->getPos_x(), crayon->getPos_y());

    /* Police */
    sf::String playerInput;
    sf::Font font;
    if (!font.loadFromFile("assets/LouisGeorgeCafe.ttf")) cout<<"Erreur lors du chargement de la police"<<endl;
    
    
    /* Commande utilisateur */
    sf::Text playerText("",font, 40);
    playerText.setFillColor(sf::Color::Black);
    playerText.setPosition(width*0.5 + 35, height*0.7 + 35);
    
    /* Boutons */
    sf::RectangleShape btn_nettoyer(sf::Vector2f(300, 60));
    btn_nettoyer.setFillColor(sf::Color(209, 109, 106));
    btn_nettoyer.setPosition(width*0.5 + 25,height*0.7 + 230);
    sf::Text txt_nettoyer("Nettoyer",font, 40);
    txt_nettoyer.setFillColor(sf::Color::Black);
    txt_nettoyer.setPosition((btn_nettoyer.getPosition().x+btn_nettoyer.getSize().x/2 - txt_nettoyer.getGlobalBounds().width/2),(btn_nettoyer.getPosition().y));
    
    sf::RectangleShape btn_envoyer(sf::Vector2f(300, 60));
    btn_envoyer.setFillColor(sf::Color(120, 165, 90));
    btn_envoyer.setPosition(width - btn_envoyer.getSize().x - 25,height*0.7 + 230);
    sf::Text txt_envoyer("Envoyer",font, 40);
    txt_envoyer.setFillColor(sf::Color::Black);
    txt_envoyer.setPosition((btn_envoyer.getPosition().x+btn_envoyer.getSize().x/2 - txt_envoyer.getGlobalBounds().width/2),(btn_envoyer.getPosition().y));
    
    sf::RectangleShape btn_save(sf::Vector2f(width*0.2-150, 60));
    btn_save.setFillColor(sf::Color(120, 165, 90));
    btn_save.setPosition(75,330+height*0.45 + 30);
    sf::Text txt_save("Sauvegarder",font, 40);
    txt_save.setFillColor(sf::Color::Black);
    txt_save.setPosition((btn_save.getPosition().x+btn_save.getSize().x/2 - txt_save.getGlobalBounds().width/2),(btn_save.getPosition().y));
    
    sf::RectangleShape btn_maison(sf::Vector2f(width*0.1-60, 50));
    btn_maison.setFillColor(sf::Color(255, 238, 248));
    btn_maison.setPosition(400, height*0.7 + 40);
    sf::Text txt_maison("Maison",font, 35);
    txt_maison.setFillColor(sf::Color::Black);
    txt_maison.setPosition((btn_maison.getPosition().x+btn_maison.getSize().x/2 - txt_maison.getGlobalBounds().width/2),(btn_maison.getPosition().y));

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::MouseButtonPressed){
                if (btn_envoyer.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton envoyer cliqué"<<endl;
                    terminal->start((string)playerInput);
                    playerInput.clear();
                    playerText.setString("");
                }
                if (btn_nettoyer.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton nettoyer cliqué"<<endl;
                    hist->clearHistorique();
                }
                if (btn_save.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton sauvegarder cliqué"<<endl;
                    if(file->save()){
                        cout<<"Fichier sauvegardé avec succès !"<<endl;
                    }else{
                        cout<<"Erreur lors de la sauvegarde"<<endl;
                    }
                }
                if (btn_maison.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton maison cliqué"<<endl;
                    for(auto i : file->load("maison.txt")){
                        terminal->start(i);
                    }
                }
            }
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
        window.draw(btn_nettoyer);
        window.draw(txt_nettoyer);
        window.draw(btn_envoyer);
        window.draw(txt_envoyer);
        window.draw(btn_save);
        window.draw(txt_save);
        window.draw(btn_maison);
        window.draw(txt_maison);
        window.draw(playerText); //Affichage saisie utilisateur
        for(auto i : crayon->getHistorique()->getHistorique()) window.draw(i); //Affichage du dessin
        int nbHist = 0;
        for(auto j : crayon->getHistorique()->getHistoriqueTexte()){
            if(345+nbHist*55<345+height*0.45){
            sf::Text textHistorique(j,font, 35);
            textHistorique.setFillColor(sf::Color::Black);
            textHistorique.setPosition(85, 345 + nbHist*50);
            window.draw(textHistorique);
            nbHist++;
            }
        }
        if(tortue->getVisible()) tortue->draw();
        window.display(); //Affichage fenetre;
    }

    return 0;
}

