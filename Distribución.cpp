//
// Created by Pablo Alcolea Sesse on 27/11/24.
//

#include "Distribución.h"
#include <iostream>
#include "Agente.h"

void distribuir(std::vector<Agente> agentes, std::vector<std::string> dependencias) {
    Agente agenteUno;
    std::string nombre = "Agente 1";
    agenteUno.setNombre(nombre);

    dependencias = {"Tarea A: Reserva de vuelo", "Tarea E: Recoger el billete de la agencia", "Tarea F: Llevar el billete a la oficina", "Tarea H: Llevar maletas a la oficina" };
    for (int i = 0; i < dependencias.size(); i++) {
        agenteUno.addDependencias(dependencias[i]);
    }

}