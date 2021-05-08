//
//  filesystem.hpp
//  Miniprojet
//
//  Created by Maxime Perrin on 08/05/2021.
//

#ifndef filesystem_h
#define filesystem_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "historique.h"

class FileSystem{
    string url_;
    Historique *historique_;
public:
    FileSystem(string url, Historique *historique);
    ~FileSystem(){delete historique_;};
    void load();
    bool save();
};

#endif /* filesystem_hpp */
