//
// Created by Pablo Alcolea Sesse on 30/11/24.
//

#ifndef TAREA_H
#define TAREA_H


#include <string>

class Tarea {
private:
    std::string id;
    std::string descripcion;
    int duracion;

public:
    Tarea(const std::string& id, const std::string& descripcion, int duracion);
    std::string getId() const;
    std::string getDescripcion() const;
    int getDuracion() const;
    std::string toString() const;
};

#endif //TAREA_H
