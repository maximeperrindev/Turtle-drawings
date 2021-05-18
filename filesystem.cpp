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
/*
 * Gestion de la sauvegarde de l'historique
 * un booléen d'état => true : sauvegarde réussie ; false : erreur de sauvegarde 
 */
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

/*
 * Gestion du chargement de fichier
 * Entrée : file => un string contenant le nom du fichier à charger
 * Sortie : un vecteur de string contenant toutes les instructions récupérées dans le fichier
 */
vector<string> FileSystem::load(string file){
    string line;
    vector<string> dataArray;
    ifstream txtFile(url_+file);
    if(!txtFile) //Always test the file open.
    {
        std::cout<<"Error opening output file"<< std::endl;
    }else{
        while(getline(txtFile, line)){
            dataArray.push_back(line);
        }
    }
    return dataArray;
}
