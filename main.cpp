//
// Created by Pablo Alcolea Sesse on 30/11/24.
//

#include "Launcher/Launcher.h"
#include <iostream>
#include "Launcher/Launcher.h"

int main() {
    try {
        Launcher launcher;
         launcher.imprimirTareas();
        launcher.ejecutar();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
