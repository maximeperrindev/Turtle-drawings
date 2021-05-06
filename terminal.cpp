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

void Terminal::start(){
    string action = "";
    bool drawed = false;
    do{
        cin>>action;
        if(action != "stop"){
            unsigned long parenthesisIndex = action.find('(');
            unsigned long parenthesisEnd = action.find(')');
            string arguments = action.substr(parenthesisIndex+1, parenthesisEnd);
            vector<string> args = split(arguments, ",");
            string function = action.substr(0,parenthesisIndex);
            /*cout<<function<<endl;
            for(auto i : args) cout<<i<<endl;*/
            if(function == "avance"){
                crayon_->Move(stoi(args[0]));
                drawed = true;
            }
            else if(function == "rotate") crayon_->setAngle(stof(args[0]));
        }
        if(drawed){
            for(auto i : crayon_->getHistorique()->getHistorique()) crayon_->getWindow()->draw(i);
            crayon_->getWindow()->display();
        }
    }while(action != "stop");
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


