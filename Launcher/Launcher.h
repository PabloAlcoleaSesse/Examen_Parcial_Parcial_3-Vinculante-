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
    Launcher(); 
    void ejecutar();
    std::vector<Tarea> getListaDeTareas() const;
    void crearActoresConInput();
    void asignarTareasConInput();
    void imprimirTareas();

private:
    std::vector<Tarea> crearTareas();
    std::vector<Actor> actores;
    std::vector<Tarea> tareas;
};
#endif 
