//
// Created by laptop on 2/04/2024.
//

#ifndef PRACTICA2OFICIAL_TABLAHASH_H
#define PRACTICA2OFICIAL_TABLAHASH_H
#include "ListaDoblemente.h"
#include "../clases/Grupos.h"

template <typename T>
class TablaHash {
public:
    ListaDoblemente<T>* tabla;
    int size;
    int count;

    TablaHash() {
        size = 5;
        count = 0;
        tabla = new ListaDoblemente<T>[size];
        for (int i = 0; i < size; i++) {
            tabla[i] = ListaDoblemente<T>();
        }
    }

    int funcionHash(std::string nombreGrupo) {
        int suma = 0;
        for (char c : nombreGrupo) {
            suma += c;
        }
        return suma % size;
    }

     void insertGroup(Grupos *grupo) {
        if (count >= size * 0.7) {
            rehash();
        }
        int indice = funcionHash(grupo->getNombreGrupo());
        Nodo<T>* aux = tabla[indice].getInicio();
        while (aux != nullptr) {
            std::cout << aux->getDato()->getNombreGrupo() << std::endl;
            aux = aux->getSiguiente();
        }
        if(estaLlena()){
            rehash();
        } else {
            if(tabla[indice].getInicio() == nullptr){
                tabla[indice].insertarInicio(grupo);
            } else {
                if(tabla[indice+1].getInicio() == nullptr){
                    tabla[indice+1].insertarInicio(grupo);
                } else {
                    rehash();
                    insertGroup(grupo);
                }
            }
        }
        count++;
    }

    bool estaLlena() {
        int contador = 0;
        for (int i = 0; i < size; ++i) {
            if(tabla[i].getInicio() != nullptr){
                contador++;
            }
        }
        return contador == 5;
    }

    void insertGroupRehash(Grupos* grupo) {
        Grupos* grupos = new Grupos(*grupo);
        int indice = funcionHash(grupos->getNombreGrupo());
        Nodo<T>* aux = tabla[indice].getInicio();
        while (aux != nullptr) {
            std::cout << aux->getDato()->getNombreGrupo() << std::endl;
            aux = aux->getSiguiente();
        }
        tabla[indice].insertarInicio(grupos);
    }

    void rehash() {
        int lastSize = size;
        size *= 2;
        ListaDoblemente<T>* temp = tabla;
        tabla = new ListaDoblemente<T>[size * 2];
        for (int i = 0; i < size; i++) {
            tabla[i] = ListaDoblemente<T>();
        }
        for (int i = 0; i < lastSize; i++) {
            Nodo<T>* aux = temp[i].getInicio();
            while (aux != nullptr) {
                insertGroupRehash(aux->getDato());
                aux = aux->getSiguiente();
            }
        }
        delete[] temp;
    }

    void mostrarTabla() {
        for (int i = 0; i < size; i++) {
            cout << "Indice " << i << ": ";
            tabla[i].mostrar();
        }
    }
};


#endif //PRACTICA2OFICIAL_TABLAHASH_H
