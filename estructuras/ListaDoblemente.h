//
// Created by laptop on 2/04/2024.
//

#ifndef PRACTICA2OFICIAL_LISTADOBLEMENTE_H
#define PRACTICA2OFICIAL_LISTADOBLEMENTE_H
#include "Nodo.h"
#include "iostream"

template <typename T>
class ListaDoblemente {
private:
    T dato;
    Nodo<T> *inicio;
    Nodo<T> *fin;
public:
    Nodo<T>* getInicio() { return inicio; }

    ListaDoblemente() {
        inicio = nullptr;
        fin = nullptr;
    }

    ~ListaDoblemente() {
        Nodo<T> *aux = inicio;
        while (aux != nullptr) {
            inicio = inicio->getSiguiente();
            delete aux;
            aux = inicio;
        }
    }

    void insertarInicio(T dato) {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        if (inicio == nullptr) {
            inicio = nuevo;
            fin = nuevo;
        } else {
            nuevo->setSiguiente(inicio);
            inicio->setAnterior(nuevo);
            inicio = nuevo;
        }
    }

    void insertarFinal(T dato) {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        if (inicio == nullptr) {
            inicio = nuevo;
            fin = nuevo;
        } else {
            fin->setSiguiente(nuevo);
            nuevo->setAnterior(fin);
            fin = nuevo;
        }
    }

    void mostrar() {
        Nodo<T> *aux = inicio;
        if(aux == nullptr){
            std::cout << "No hay elementos en la lista" << std::endl;
        } else {
                std::cout << aux->getDato()->getNombreGrupo() << std::endl;
        }
    }

    void mostrarContacto(){
        Nodo<T> *aux = inicio;
        if (aux == nullptr){
            std:: cout << "No hay elementos en la lista" << std::endl;
        }else {
            std::cout << aux->getDato()->getNombre() << std::endl;
        }
    }

};

#endif //PRACTICA2OFICIAL_LISTADOBLEMENTE_H