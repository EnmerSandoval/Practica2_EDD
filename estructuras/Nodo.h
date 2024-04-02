//
// Created by laptop on 2/04/2024.
//

#ifndef PRACTICA2OFICIAL_NODO_H
#define PRACTICA2OFICIAL_NODO_H

template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T> *siguiente;
    Nodo<T> *anterior;
public:
    Nodo(T dato) : dato(dato), siguiente(nullptr), anterior(nullptr) {}
    T getDato() const { return dato; }
    Nodo<T>* getSiguiente() const { return siguiente; }
    Nodo<T>* getAnterior() const { return anterior; }

    void setDatos(T dato) { this->dato = dato; }
    void setSiguiente(Nodo<T> *siguiente) { this->siguiente = siguiente; }
    void setAnterior(Nodo<T> *anterior) { this->anterior = anterior; }

};


#endif //PRACTICA2OFICIAL_NODO_H
