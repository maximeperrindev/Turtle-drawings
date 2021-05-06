//
//  menu.hpp
//  Miniprojet
//
//  Created by Maxime Perrin on 06/05/2021.
//

#ifndef terminal_h
#define terminal_h
#include <string.h>
#include <stdio.h>
#include "crayon.h"
class Terminal{
    Crayon *crayon_;
public:
    Terminal(Crayon *crayon);
    ~Terminal();
    void start();
private:
    vector<string> split(string s, string delimiter);
};

#endif /* menu_hpp */
