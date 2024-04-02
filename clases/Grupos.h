//
// Created by laptop on 2/04/2024.
//

#ifndef PRACTICA2OFICIAL_GRUPOS_H
#define PRACTICA2OFICIAL_GRUPOS_H

#include <string>
#include <map>
#include <iostream>
#include "../estructuras/ListaDoblemente.h"
#include "../estructuras/ArbolAVL.h"
#include "Contactos.h"

using namespace std;
class Grupos {
public:
    Grupos() = default;
    std::string nombreGrupo;
    std::map<std::string, std::string> group;
    void setNombreGrupo(const std::string &nombreGrupo);
    const std::string &getNombreGrupo() const;

    virtual ~Grupos();
};


#endif //PRACTICA2OFICIAL_GRUPOS_H
