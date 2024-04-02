//
// Created by laptop on 2/04/2024.
//

#ifndef PRACTICA2OFICIAL_NODOARBOL_H
#define PRACTICA2OFICIAL_NODOARBOL_H

template <typename T>
class NodoArbol {
    T dato;
    NodoArbol *izquierda, *derecha, *padre;
    int balance, alturaIzquierda, alturaDerecha;
};

#endif //PRACTICA2OFICIAL_NODOARBOL_H