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

void Terminal::start(string action){
    bool drawed = false;
    //Conversion en minuscule
    std::transform(action.begin(), action.end(), action.begin(),
        [](unsigned char c){ return std::tolower(c); });
    
        if(action != "stop"){
            unsigned long parenthesisIndex = action.find(' ');
            string arguments = action.substr(parenthesisIndex+1, action.back());
            vector<string> args = split(arguments, ",");
            string function = action.substr(0,parenthesisIndex);
            if(args[0] != ""){
            if(function == "avance"){
                crayon_->Move(stoi(args[0]));
                cout<<"Avance de "<<stoi(args[0])<<endl;
                drawed = true;
            }
            if(function == "recule"){
                crayon_->Move(-(stoi(args[0])));
                drawed = true;
            }
            else if(function == "droite") crayon_->setAngle(stof(args[0]));
            else if(function == "gauche") crayon_->setAngle(-(stof(args[0])));
            else if(function == "nettoie") {
                crayon_->getHistorique()->clearHistorique();
            }
            else if(function == "taille") crayon_->setTaille(stoi(args[0]));
            else if(function == "levestylo") crayon_->setEnable(false);
            else if(function == "posestylo") crayon_->setEnable(true);
            else if(function == "retour"){
                if(crayon_->getHistorique()->getHistorique().size() != 0){
                    crayon_->goBack();
                    crayon_->getHistorique()->deleteLasteEvent();
                }
            }
            crayon_->getHistorique()->addHistorique(action);
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


