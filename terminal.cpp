//
//  menu.cpp
//  Miniprojet
//
//  Created by Maxime Perrin on 06/05/2021.
//

#include "terminal.h"

Terminal::Terminal(Crayon *crayon){
    crayon_ = crayon;
}
Terminal::~Terminal(){
    delete crayon_;
}

void Terminal::start(string action, bool hist){
    bool drawed = false;
    bool success = true;
    //Conversion en minuscule
    std::transform(action.begin(), action.end(), action.begin(),
        [](unsigned char c){ return std::tolower(c); });
    
        if(action != "stop"){
            long parenthesisIndex = action.find(' ');
            string arguments = action.substr(parenthesisIndex+1, action.back());
            vector<string> args = split(arguments, " ");
            string function = action.substr(0,parenthesisIndex);
            if(parenthesisIndex != -1){
                if(function == "avance"){
                    crayon_->Move(stoi(args[0]));
                    cout<<"Avance de "<<stoi(args[0])<<endl;
                    drawed = true;
                }
                else if(function == "recule"){
                    crayon_->Move(-(stoi(args[0])));
                    drawed = true;
                }
                else if(function == "droite") crayon_->setAngle(stof(args[0]));
                else if(function == "gauche") crayon_->setAngle(-(stof(args[0])));
                else if(function == "taille") crayon_->setTaille(stoi(args[0]));
                else if(function == "couleur") crayon_->setColor(stoi(args[0]), stoi(args[1]), stoi(args[2]));
                else if(function == "repete"){
                    int occurations = stoi(args[0]);
                    long argsIndex = action.find('[');
                    long argsIndexEnd = action.find(']');
                    string strArgs = action.substr(argsIndex+1, argsIndexEnd - argsIndex -1);
                    vector<string> argsRepete = split(strArgs, " ");
                    vector<string> argsTab = {};
                    for(int x = 0; x<argsRepete.size(); x++){
                        if( x%2 == 0 ) argsTab.push_back(argsRepete[x]);
                        else argsTab[argsTab.size()-1] += " " + argsRepete[x];
                    }
                    for(int i = 0; i<occurations; i++){
                        for(int y=0; y<argsTab.size();y++){
                            start(argsTab[y], false);
                        }
                    }
                }
                else success = false;
            }else{
                if(function == "origine") crayon_->goOrigine();
                else if(function == "nettoie") {
                    crayon_->getHistorique()->clearHistorique();
                }
                else if(function == "levestylo") crayon_->setEnable(false);
                else if(function == "posestylo") crayon_->setEnable(true);
                else if(function == "cachetortue") crayon_->getTortue()->setVisible(false);
                else if(function == "montretortue") crayon_->getTortue()->setVisible(true);
                else if(function == "retour"){
                    if(crayon_->getHistorique()->getHistorique().size() != 0){
                        crayon_->goBack();
                        crayon_->getHistorique()->deleteLasteEvent();
                    }
                }
                else success = false;
            }
            if(success && hist){
                crayon_->getHistorique()->addHistorique(action);
                cout<<"Historique"<<endl;
            }
        }
}

vector<string> Terminal::split(string s, string delimiter){
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


