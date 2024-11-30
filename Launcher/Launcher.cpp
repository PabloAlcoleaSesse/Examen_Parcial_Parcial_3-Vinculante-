//
// Created by Pablo Alcolea Sesse on 30/11/24.
//
#include "Launcher.h"
#include <iostream>
#include <iomanip> // Para formatear la salida
#include "../Actor/Actor.h"
#include <unordered_map>
#include <algorithm> // For std::max
#include <sstream>

using namespace std;

vector<Tarea> Launcher::crearTareas() {
    return {
        Tarea("A", "Reserva de vuelo", 20),
        Tarea("B", "Informar a casa para empacar", 5),
        Tarea("C", "Empacar maletas", 40),
        Tarea("D", "Preparacion del billete por la agencia", 10),
        Tarea("E", "Recoger el billete de la agencia", 5),
        Tarea("F", "Llevar el billete a la oficina", 10),
        Tarea("G", "Recoger las maletas de casa", 20),
        Tarea("H", "Llevar maletas a la oficina", 25),
        Tarea("I", "Conversacion sobre documentos requeridos", 35),
        Tarea("J", "Dictar instrucciones para ausencia", 25),
        Tarea("K", "Reunir documentos", 15),
        Tarea("L", "Organizar documentos", 5),
        Tarea("M", "Viajar al aeropuerto y facturar", 25)
    };
}

vector<Actor> Launcher::crearActores() {
    return {
        Actor("1", "Agente 1"),
        Actor("2", "Agente 2"),
        Actor("3", "Agente 3"),
        Actor("4", "Agente 4"),
        Actor("5", "Agencia de Viajes"),
        Actor("6", "Familiares en Casa"),
        Actor("7", "CEO")
    };
}

void Launcher::asignarTareas(vector<Actor>& actores, const vector<Tarea>& tareas) {
    // Manually assign tasks to actors
    actores[0].addTarea(tareas[0]); // Agente 1: Reserva de vuelo
    actores[0].addTarea(tareas[4]); // Agente 1: Recoger el billete de la agencia
    actores[0].addTarea(tareas[5]); // Agente 1: Llevar el billete a la oficina
    actores[0].addTarea(tareas[7]); // Agente 1: Llevar maletas a la oficina

    actores[1].addTarea(tareas[1]); // Agente 2: Informar a casa para empacar
    actores[1].addTarea(tareas[6]); // Agente 2: Recoger las maletas de casa

    actores[2].addTarea(tareas[8]); // Agente 3: Conversacion sobre documentos requeridos
    actores[2].addTarea(tareas[10]); // Agente 3: Reunir documentos
    actores[2].addTarea(tareas[11]); // Agente 3: Organizar documentos

    actores[3].addTarea(tareas[9]); // Agente 4: Dictar instrucciones para ausencia
    actores[3].addTarea(tareas[3]); // Agente 4: Preparacion del billete por la agencia (asistencia)

    actores[4].addTarea(tareas[3]); // Agencia de Viajes: Preparacion del billete por la agencia

    actores[5].addTarea(tareas[2]); // Familiares en Casa: Empacar maletas

    actores[6].addTarea(tareas[8]); // CEO: Conversacion sobre documentos requeridos
    actores[6].addTarea(tareas[9]); // CEO: Dictar instrucciones para ausencia
    actores[6].addTarea(tareas[10]); // CEO: Reunir documentos
    actores[6].addTarea(tareas[11]); // CEO: Organizar documentos
    actores[6].addTarea(tareas[12]); // CEO: Viajar al aeropuerto y facturar
}

std::vector<Tarea> Launcher::getListaDeTareas() const {
    return tareas;
}

void Launcher::ejecutar() {
    vector<Tarea> tareas = crearTareas();
    vector<Actor> actores = crearActores();

    asignarTareas(actores, tareas);

    unordered_map<string, int> taskEndTimes; // Track end times for each task
    int tiempoTotal = 0;

    cout << "=== Resumen de tareas por actor ===" << endl;

    // Mostrar informacion de cada actor
    for (const auto& actor : actores) {
        cout << "Actor: " << actor.getDescripcion() << endl;
        cout << actor.tostring();
        int currentTime = 0;
        for (const auto& tarea : actor.getTareas()) {
            int startTime = currentTime;
            if (taskEndTimes.find(tarea.getId()) != taskEndTimes.end()) {
                startTime = max(startTime, taskEndTimes[tarea.getId()]);
            }
            int endTime = startTime + tarea.getDuracion();
            taskEndTimes[tarea.getId()] = endTime;
            currentTime = endTime;
        }
        cout << "Tiempo total para " << actor.getDescripcion() << ": " << currentTime << " minutos" << endl;
        tiempoTotal = max(tiempoTotal, currentTime);
        cout << "----------------------------------" << endl;
    }

    cout << "=== Tiempo total para completar todas las tareas ===" << endl;
    cout << "Tiempo total: " << tiempoTotal << " minutos" << endl;

    // Verificar si los actores completan a tiempo
    cout << "\n=== Verificacion de tiempos ===" << endl;
    for (const auto& actor : actores) {
        if (actor.getDuracionTotal() > 100) {
            cout << "El actor " << actor.getDescripcion() << " NO puede completar sus tareas a tiempo." << endl;
        } else {
            cout << "El actor " << actor.getDescripcion() << " puede completar sus tareas a tiempo." << endl;
        }
    }
}