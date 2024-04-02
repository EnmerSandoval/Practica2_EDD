//
// Created by laptop on 2/04/2024.
//

#ifndef PRACTICA2OFICIAL_CONTACTOS_H
#define PRACTICA2OFICIAL_CONTACTOS_H
#include "../clases/Grupos.h"
#include "iostream"
#include "../estructuras/ArbolAVL.h"

using namespace std;
template <typename T>
class Contactos {
public:
    std::string nombre;
    ArbolAVL<T> *arbolAVL;

    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        Contactos::nombre = nombre;
    }

    Contactos(){};

};


#endif //PRACTICA2OFICIAL_CONTACTOS_H