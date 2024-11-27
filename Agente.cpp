//
// Created by Pablo Alcolea Sesse on 27/11/24.
//

#include "Agente.h"

Agente::Agente(std::string nombre, std::vector<std::string> dependencias) {
    this->nombre = nombre;
    this->dependencias = dependencias;
}

void Agente::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Agente::setDependencias(std::vector<std::string> dependencias) {
    this->dependencias = dependencias;
}

void Agente::addDependencias(const std::string& dependencia) {
    this->dependencias.push_back(dependencia);
}

std::string Agente::getNombre() const {
    return this->nombre;
}

std::vector<std::string> Agente::getDependencias() const {
    return this->dependencias;
}