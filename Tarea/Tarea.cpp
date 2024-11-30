//
// Created by Pablo Alcolea Sesse on 30/11/24.
//

#include "Tarea.h"
Tarea::Tarea(const std::string& id, const std::string& descripcion, int duracion)
    : id(id), descripcion(descripcion), duracion(duracion) {}
std::string Tarea::getId() const {
    return id;
}
std::string Tarea::getDescripcion() const {
    return descripcion;
}
int Tarea::getDuracion() const {
    return duracion;
}
std::string Tarea::toString() const {
    return "Id: " + id + " Descripcion: " + descripcion + " Duracion: " + std::to_string(duracion);
}