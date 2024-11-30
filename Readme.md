# Sistema de Gestión de Tareas y Actores

## Descripción

Este proyecto implementa un sistema para gestionar tareas asignadas a diferentes actores. Cada tarea tiene una descripción, duración, y es asignada a un actor que puede completarla en un marco de tiempo definido. El sistema evalúa si los actores pueden completar sus tareas a tiempo.

## Estructura del Proyecto

El proyecto está compuesto por las siguientes clases:

1. **Tarea** (`Tarea.h`, `Tarea.cpp`):
    - Representa una tarea con:
        - `id`: Identificador único.
        - `descripcion`: Descripción de la tarea.
        - `duracion`: Duración estimada en minutos.

2. **Actor** (`Actor.h`, `Actor.cpp`):
    - Representa un actor que realiza tareas.
    - Contiene:
        - `id`: Identificador del actor.
        - `descripcion`: Descripción del actor.
        - `tareas`: Lista de tareas asignadas al actor.

3. **Launcher** (`Launcher.h`, `Launcher.cpp`):
    - Es el controlador principal del sistema.
    - Funcionalidades:
        - Crear tareas.
        - Crear actores.
        - Asignar tareas a actores.
        - Ejecutar y mostrar los resultados.

4. **Programa principal** (`main.cpp`):
    - Punto de entrada del programa. Inicializa el sistema y ejecuta las funcionalidades de `Launcher`.

## Optimización del Cronograma

### Problema Detectado

La tarea de llevar las maletas a la oficina (**Tarea H**) ocurría después de que el CEO debería estar en camino al aeropuerto (**Tarea M**). Esto causaba un retraso crítico en la ejecución del itinerario.

### Solución Propuesta

Se reorganizó el cronograma para paralelizar tareas dependientes y asegurar que las maletas lleguen a la oficina antes de que el CEO parta hacia el aeropuerto. Esto se logró sin eliminar ni modificar las tareas existentes.

### Cronograma Ajustado

1. **Inicio de tareas simultáneas**:
    - **Tarea B**: Informar a casa para empacar.
    - **Tarea A**: Reserva de vuelo.
    - **Tarea I**: Conversación sobre documentos requeridos.
    - **Tarea J**: Dictar instrucciones para ausencia.

2. **Paralelización clave**:
    - **Tarea G** (Recoger las maletas de casa) comienza mientras **Tarea C** (Empacar maletas) está en curso.
    - **Tarea H** (Llevar maletas a la oficina) comienza parcialmente dependiente de **Tarea G**.

3. **Finalización**:
    - Las maletas llegan a la oficina a los 75 minutos.
    - El CEO parte hacia el aeropuerto inmediatamente después, completando **Tarea M** en exactamente 100 minutos.

### Asignación de Tareas por Actor

- **Agente 1**: Reserva de vuelo, recoger billete, llevar billete a la oficina, llevar maletas a la oficina.
- **Agente 2**: Informar a casa, recoger maletas.
- **Agente 3**: Conversación sobre documentos requeridos, reunir y organizar documentos.
- **Agente 4**: Dictar instrucciones, asistir en la preparación del billete.
- **Agente 5 (Agencia de Viajes)**: Preparar billete.
- **Familiares en Casa**: Empacar maletas.
- **CEO**: Coordinar documentos y partir al aeropuerto.

### Resultados

El itinerario ajustado asegura que:
- Todas las tareas se completan dentro del límite de **100 minutos**.
- El CEO recibe las maletas y documentos necesarios a tiempo.

## Diagrama de Flujo

```mermaid
graph TD
    A[Inicio] --> B[Crear tareas]
    B --> C[Crear actores]
    C --> D[Asignar tareas]
    D --> E[Calcular tiempos]
    E --> F{¿Se completan a tiempo?}
    F -->|Sí| G[Mostrar resumen]
    F -->|No| H[Notificar problemas]
    G --> I[Fin]
    H --> I