//
// Created by laptop on 2/04/2024.
//

#ifndef PRACTICA2OFICIAL_CONTACTOS_H
#define PRACTICA2OFICIAL_CONTACTOS_H
#include "iostream"
#include "../estructuras/ArbolAVL.h"
#include "Grupos.h"

using namespace std;
template <typename T>
class Contactos {
public:
    std::string nombre;
    Grupos grupo;
    ArbolAVL<T> *arbolAVL;

    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        Contactos::nombre = nombre;
    }

    Contactos(T) {
        arbolAVL = new ArbolAVL<T>();
    }

    Contactos(){};



};


#endif //PRACTICA2OFICIAL_CONTACTOS_H
