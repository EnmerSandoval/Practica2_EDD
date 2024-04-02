//
// Created by laptop on 2/04/2024.
//

#ifndef PRACTICA2OFICIAL_ARBOLAVL_H
#define PRACTICA2OFICIAL_ARBOLAVL_H
#include "NodoArbol.h"
#include "iostream"

template <typename T>
class ArbolAVL {
public:
    NodoArbol<T> *raiz;
    ArbolAVL() {
        raiz = nullptr;
    }

    NodoArbol<T> insertar(T dato) {

        return insertar(this->raiz, dato);
    }

    NodoArbol<T> insertar(NodoArbol<T> *nodo, T dato) {
        if (nodo == nullptr) {
            nodo = new NodoArbol<T>(dato);
        } else if (dato < nodo->dato) {
            nodo->izquierda = insertar(nodo->izquierda, dato);
            if (altura(nodo->izquierda) - altura(nodo->derecha) == 2) {
                if (dato < nodo->izquierda->dato) {
                    nodo = rotacionIzquierda(nodo);
                } else {
                    nodo = rotacionDobleIzquierda(nodo);
                }
            }
        } else if (dato > nodo->dato) {
            nodo->derecha = insertar(nodo->derecha, dato);
            if (altura(nodo->derecha) - altura(nodo->izquierda) == 2) {
                if (dato > nodo->derecha->dato) {
                    nodo = rotacionDerecha(nodo);
                } else {
                    nodo = rotacionDobleDerecha(nodo);
                }
            }
        }
        nodo->altura = max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;
        return nodo;
    }

    NodoArbol<T> rotacionDerecha(NodoArbol<T> *nodo) {
        NodoArbol<T> *aux = nodo->izquierda;
        nodo->izquierda = aux->derecha;
        aux->derecha = nodo;
        nodo->alturaIzquierda = altura(nodo->izquierda);
        nodo->alturaDerecha = altura(nodo->derecha);
        nodo->balance = nodo->alturaDerecha - nodo->alturaIzquierda;
        aux->alturaIzquierda = altura(aux->izquierda);
        aux->alturaDerecha = altura(aux->derecha);
        aux->balance = aux->alturaDerecha - aux->alturaIzquierda;
        return aux;
    }

    NodoArbol<T> rotacionIzquierda(NodoArbol<T> *nodo) {
        NodoArbol<T> *aux = nodo->derecha;
        nodo->derecha = aux->izquierda;
        aux->izquierda = nodo;
        nodo->alturaIzquierda = altura(nodo->izquierda);
        nodo->alturaDerecha = altura(nodo->derecha);
        nodo->balance = nodo->alturaDerecha - nodo->alturaIzquierda;
        aux->alturaIzquierda = altura(aux->izquierda);
        aux->alturaDerecha = altura(aux->derecha);
        aux->balance = aux->alturaDerecha - aux->alturaIzquierda;
        return aux;
    }

    NodoArbol<T> rotacionDobleDerecha(NodoArbol<T> *nodo) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    NodoArbol<T> rotacionDobleIzquierda(NodoArbol<T> *nodo) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    NodoArbol<T> buscar(NodoArbol<T> *nodo, T dato) {
        if (nodo == nullptr) {
            return nullptr;
        } else if (dato < nodo->dato) {
            return buscar(nodo->izquierda, dato);
        } else if (dato > nodo->dato) {
            return buscar(nodo->derecha, dato);
        } else {
            return nodo;
        }
    }

    NodoArbol<T> eliminar(NodoArbol<T> *nodo, T dato) {
        if (nodo == nullptr) {
            return nullptr;
        } else if (dato < nodo->dato) {
            nodo->izquierda = eliminar(nodo->izquierda, dato);
            if (altura(nodo->derecha) - altura(nodo->izquierda) == 2) {
                if (nodo->derecha->balance >= 0) {
                    nodo = rotacionDerecha(nodo);
                } else {
                    nodo = rotacionDobleDerecha(nodo);
                }
            }
        } else if (dato > nodo->dato) {
            nodo->derecha = eliminar(nodo->derecha, dato);
            if (altura(nodo->izquierda) - altura(nodo->derecha) == 2) {
                if (nodo->izquierda->balance <= 0) {
                    nodo = rotacionIzquierda(nodo);
                } else {
                    nodo = rotacionDobleIzquierda(nodo);
                }
            }
        } else {
            if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
                delete nodo;
                return nullptr;
            } else if (nodo->izquierda == nullptr) {
                NodoArbol<T> *aux = nodo;
                nodo = nodo->derecha;
                delete aux;
            } else if (nodo->derecha == nullptr) {
                NodoArbol<T> *aux = nodo;
                nodo = nodo->izquierda;
                delete aux;
            } else {
                NodoArbol<T> *aux = nodoMenor(nodo->derecha);
                nodo->dato = aux->dato;
                nodo->derecha = eliminar(nodo->derecha, aux->dato);
                if (altura(nodo->izquierda) - altura(nodo->derecha) == 2) {
                    if (nodo->izquierda->balance <= 0) {
                        nodo = rotacionIzquierda(nodo);
                    } else {
                        nodo = rotacionDobleIzquierda(nodo);
                    }
                }
            }
        }
        nodo->alturaIzquierda = altura(nodo->izquierda);
        nodo->alturaDerecha = altura(nodo->derecha);
        nodo->balance = nodo->alturaDerecha - nodo->alturaIzquierda;
        return nodo;
    }

    NodoArbol<T> nodoMenor(NodoArbol<T> *nodo) {
        if (nodo->izquierda == nullptr) {
            return nodo;
        } else {
            return nodoMenor(nodo->izquierda);
        }
    }

    NodoArbol<T> nodoMayor(NodoArbol<T> *nodo) {
        if (nodo->derecha == nullptr) {
            return nodo;
        } else {
            return nodoMayor(nodo->derecha);
        }
    }

    int altura(NodoArbol<T> *nodo) {
        if (nodo == nullptr) {
            return -1;
        } else {
            return 1 + max(altura(nodo->izquierda), altura(nodo->derecha));
        }
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int getBalance(NodoArbol<T> *nodo) {
        if (nodo == nullptr) {
            return 0;
        } else {
            return altura(nodo->derecha) - altura(nodo->izquierda);
        }
    }

    void preOrden(NodoArbol<T> *nodo) {
        if (nodo != nullptr) {
            std::cout << nodo->dato << " ";
            preOrden(nodo->izquierda);
            preOrden(nodo->derecha);
        }
    }

    void inOrden(NodoArbol<T> *nodo) {
        if (nodo != nullptr) {
            inOrden(nodo->izquierda);
            std::cout << nodo->dato << " ";
            inOrden(nodo->derecha);
        }
    }

};


#endif //PRACTICA2OFICIAL_ARBOLAVL_H
