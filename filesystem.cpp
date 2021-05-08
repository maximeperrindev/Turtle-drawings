//
//  filesystem.cpp
//  Miniprojet
//
//  Created by Maxime Perrin on 08/05/2021.
//

#include "filesystem.h"

FileSystem::FileSystem(string url, Historique *historique){
    url_ = url;
    historique_ = historique;
}

bool FileSystem::save(){
    try{
    ofstream save(url_+"historique.txt");
    for(auto i : historique_->getHistoriqueTexte()) save<<i<<"\n";
    save.close();
        return true;
    }catch(...){
        return false;
    }
}
