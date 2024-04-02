//
// Created by laptop on 2/04/2024.
//

#include "Grupos.h"

const std::string &Grupos::getNombreGrupo() const {
    return nombreGrupo;
}
void Grupos::setNombreGrupo(const std::string &nombreGrupo) {
    Grupos::nombreGrupo = nombreGrupo;
}
Grupos::~Grupos() {

}