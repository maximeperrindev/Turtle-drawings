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
    sf::Cursor cursor;
    unsigned int width = i.front().width; //Largeur de la fenêtre
    unsigned int height = i.front().height; //Hauteur de la fenêtre
    unsigned int size =  0, frames = 0;
    float factor = 0.f, speed = .00001f;

    /*Déclaration des objets*/
    Historique *hist = new Historique();
    Tortue *tortue = new Tortue(&window);
    Crayon *crayon = new Crayon(&window, hist, tortue);
    Terminal *terminal = new Terminal(crayon);
    Renderer *renderer = new Renderer(&window);
    FileSystem *file = new FileSystem("data/", hist);

    /*Initialisation du crayon*/
    crayon->setOrigine(width, height);
    crayon->goOrigine();
    tortue->setPosition(crayon->getPos_x(), crayon->getPos_y());

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
    
    sf::RectangleShape btn_save(sf::Vector2f(width*0.2-340, 60));
    btn_save.setFillColor(sf::Color(120, 165, 90));
    btn_save.setPosition(15,330+height*0.45 + 30);
    sf::Text txt_save("Sauvegarder",font, 37);
    txt_save.setFillColor(sf::Color::Black);
    txt_save.setPosition((btn_save.getPosition().x+btn_save.getSize().x/2 - txt_save.getGlobalBounds().width/2),(btn_save.getPosition().y));
    
    sf::RectangleShape btn_load(sf::Vector2f(width*0.2-340, 60));
    btn_load.setFillColor(sf::Color(120, 165, 90));
    btn_load.setPosition(width*0.2-250,330+height*0.45 + 30);
    sf::Text txt_load("Charger",font, 37);
    txt_load.setFillColor(sf::Color::Black);
    txt_load.setPosition((btn_load.getPosition().x+btn_load.getSize().x/2 - txt_load.getGlobalBounds().width/2),(btn_load.getPosition().y));
    
    sf::RectangleShape btn_maison(sf::Vector2f(width*0.1-60, 50));
    btn_maison.setFillColor(sf::Color(255, 238, 248));
    btn_maison.setPosition(400, height*0.7 + 40);
    sf::Text txt_maison("Maison",font, 35);
    txt_maison.setFillColor(sf::Color::Black);
    txt_maison.setPosition((btn_maison.getPosition().x+btn_maison.getSize().x/2 - txt_maison.getGlobalBounds().width/2),(btn_maison.getPosition().y));
    
    sf::RectangleShape btn_fleur(sf::Vector2f(width*0.1 - 60, 50));
    btn_fleur.setFillColor(sf::Color(255, 238, 248));
    btn_fleur.setPosition(670, height*0.7 + 40);
    sf::Text txt_fleur("Fleur",font, 35);
    txt_fleur.setFillColor(sf::Color::Black);
    txt_fleur.setPosition((btn_fleur.getPosition().x+btn_fleur.getSize().x/2 - txt_fleur.getGlobalBounds().width/2),(btn_fleur.getPosition().y));
    
    vector<sf::RectangleShape> btn_list{btn_save, btn_load, btn_envoyer, btn_nettoyer, btn_maison, btn_fleur};
    vector<sf::Text> txt_list{txt_save, txt_load,txt_envoyer, txt_nettoyer, txt_maison, txt_fleur};
    /*Fin des boutons*/
    //Boucle infinie qui tourne en environ 60 IPS
    while (window.isOpen())
    {
        //Gestion des evenements liés à l'interaction de la fenetre
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseMoved){
                bool found = false;
                for(auto i:btn_list){
                    if(i.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                        if (cursor.loadFromSystem(sf::Cursor::Hand))
                            window.setMouseCursor(cursor);
                        i.setFillColor(sf::Color(i.getFillColor().Red.toInteger() - 100,i.getFillColor().Green.toInteger() - 100,i.getFillColor().Blue.toInteger() - 100));
                        found = true;
                    }
                    if(!found){
                        if (cursor.loadFromSystem(sf::Cursor::Arrow))
                            window.setMouseCursor(cursor);
                    }
                }
            }
            /*Si l'utilisateur effectue un clic*/
            if(event.type == sf::Event::MouseButtonPressed){
                /*Clic bouton envoyer*/
                if (btn_envoyer.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton envoyer cliqué"<<endl;
                    terminal->start((string)playerInput);
                    playerInput.clear();
                    playerText.setString("");
                }
                /*Clic bouton nettoyer*/
                if (btn_nettoyer.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton nettoyer cliqué"<<endl;
                    hist->clearHistorique();
                }
                /*Clic bouton sauvegarder*/
                if (btn_save.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton sauvegarder cliqué"<<endl;
                    if(file->save()){
                        cout<<"Fichier sauvegardé avec succès !"<<endl;
                    }else{
                        cout<<"Erreur lors de la sauvegarde"<<endl;
                    }
                }
                /*Clic bouton charger*/
                if (btn_load.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton charger cliqué"<<endl;
                    for(auto i : file->load("historique.txt")){
                        terminal->start(i);
                    }
                }
                /*Clic bouton maison*/
                if (btn_maison.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton maison cliqué"<<endl;
                    for(auto i : file->load("maison.txt")){
                        terminal->start(i);
                    }
                }
                /*Clic bouton fleur*/
                if (btn_fleur.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    cout<<"Bouton fleur cliqué"<<endl;
                    for(auto i : file->load("fleur.txt")){
                        terminal->start(i);
                    }
                }
            }
            //Fermeture de la fenêtre
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
        /*On dessine toutes nos formes sur la fenêtre*/
        window.clear(sf::Color::White); //Nettoyage de la fenetre
        renderer->renderLayout(width, height); //Affichage du layout
        for(auto i : btn_list) window.draw(i); //Boutons
        for(auto i : txt_list) window.draw(i); //Textes des boutons
        /*Carret qui clignote pour la saisie du texte*/
        if(frames < 240)
        {
            playerText.setString(playerInput + "|");
            frames++;
        }
        else if(frames < 480){
            playerText.setString(playerInput);
            frames++;
        }else{
            frames = 0;
        }
        window.draw(playerText); //Affichage saisie utilisateur
 
        /*Déplacement de la tortue a une certaine vitesse*/
        if(size != crayon->getHistorique()->getHistorique().size()){
            size = crayon->getHistorique()->getHistorique().size();
            factor = 0.0f;
        }
        factor += speed * 60;
        tortue->move(tortue->getPosition(), sf::Vector2f{(float)crayon->getPos_x(),(float)crayon->getPos_y()} , factor);
        /*Fin déplacement*/
        
        /*Affichage du dessin entier en parcourant l'historique qui stocke les rectangles*/
        for(auto i : crayon->getHistorique()->getHistorique()){
            window.draw(i); //Affichage du dessin
        }
        /*Affichage de l'historique sous forme textuelle*/
        int nbHist = 0;
        for(auto j : crayon->getHistorique()->getHistoriqueTexte()){
            if(345+nbHist*55<345+height*0.45){
            sf::Text textHistorique(j,font, 35);
            textHistorique.setFillColor(sf::Color::Black);
            textHistorique.setPosition(40, 345 + nbHist*50);
            window.draw(textHistorique);
            nbHist++;
            }
        }
        if(tortue->getVisible()) tortue->draw();
        
        
        window.display(); //Affichage fenetre;
    }

    return 0;
}

