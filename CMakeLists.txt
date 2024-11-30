cmake_minimum_required(VERSION 3.29)
project(Examen_Parcial_Parcial_3_Vinculante_)

set(CMAKE_CXX_STANDARD 14)

include_directories(Actor)
include_directories(Tarea)

add_executable(Examen_Parcial_Parcial_3_Vinculante_
    Actor/Actor.cpp
    Actor/Actor.h
    Tarea/Tarea.cpp
    Tarea/Tarea.h
        Launcher/Launcher.h
        Launcher/Launcher.cpp
        crud/crud.h
        main.cpp)
