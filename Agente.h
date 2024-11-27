//
// Created by Pablo Alcolea Sesse on 27/11/24.
//

#ifndef AGENTE_H
#define AGENTE_H

#include <string>
#include <vector>
#include <iostream>

class Agente {
private:
  std::string nombre;
  std::vector<std::string> dependencias;
public:
  Agente() = default; // Default constructor
  Agente(std::string nombre, std::vector<std::string> dependencias);

  void setNombre(std::string nombre);
  void setDependencias(std::vector<std::string> dependencias);
  void addDependencias(const std::string& dependencia);

  std::string getNombre() const;
  std::vector<std::string> getDependencias() const;
};


#endif //AGENTE_H
