//
// Created by Pablo Alcolea Sesse on 30/11/24.
//
#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <vector>
#include "../Tarea/Tarea.h"

class Actor {
private:
    std::string id;
    std::string descripcion;
    std::vector<Tarea> tareas;
public:
    Actor(const std::string& id, const std::string& descripcion);
    std::string getId() const;
    std::string getDescripcion() const;
    int addTarea(const Tarea& tarea);
    int getDuracionTotal() const;
    std::string tostring() const;
    std::vector<Tarea> getTareas() const;
};
#endif //ACTOR_H