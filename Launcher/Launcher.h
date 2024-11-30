//
// Created by Pablo Alcolea Sesse on 30/11/24.
//

#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "../Actor/Actor.h"
#include "../Tarea/Tarea.h"
#include <vector>

class Launcher {
public:
    void ejecutar();
    std::vector<Tarea> getListaDeTareas() const; // New method declaration
private:
    std::vector<Tarea> crearTareas();
    std::vector<Actor> crearActores();
    void asignarTareas(std::vector<Actor>& actores, const std::vector<Tarea>& tareas);
    std::vector<Tarea> tareas; // Store the list of tasks
};

#endif //LAUNCHER_H