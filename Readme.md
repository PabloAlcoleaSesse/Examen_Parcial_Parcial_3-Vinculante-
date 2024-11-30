## Link de GitHub
https://github.com/PabloAlcoleaSesse/Examen_Parcial_Parcial_3-Vinculante-.git
      

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

## Explicación del Código

### Clase `Tarea`

La clase `Tarea` representa una tarea con un identificador, una descripción y una duración.

```cpp
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
```

### Clase `Actor`
La clase Actor representa un actor que realiza tareas. Contiene un identificador, una descripción y una lista de tareas asignadas.
```cpp
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
```
### Clase `Launcher`
La clase Launcher es el controlador principal del sistema. Se encarga de crear tareas, crear actores, asignar tareas a actores y ejecutar el sistema.
```cpp
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
```
### Funcio `main`
Función main
La función main es el punto de entrada del programa. Inicializa el sistema y ejecuta las funcionalidades de Launcher.
```cpp
int main() {
    try {
        Launcher launcher;
        launcher.imprimirTareas(); // Imprime la lista de tareas antes de la entrada del usuario
        launcher.ejecutar();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
```

### Metodo `imprimirTareas`
El método imprimirTareas en la clase Launcher imprime la lista de tareas almacenadas en el vector tareas .
```cpp
void Launcher::imprimirTareas() {
    cout << "=== Lista de tareas ===" << endl;
    for (const auto& tarea : tareas) {
        cout << tarea.toString() << endl;
    }
    cout << "=======================" << endl;
}
```

### Metodo`crearActoresConInput`
El método crearActoresConInput solicita al usuario que ingrese el número de actores y sus detalles, y luego los agrega al vector actores.
```cpp
void Launcher::crearActoresConInput() {
    int numActores;
    cout << "Ingrese el numero de actores: ";
    if (!(cin >> numActores)) {
        throw runtime_error("Error al leer el numero de actores.");
    }
    cin.ignore();

    for (int i = 0; i < numActores; ++i) {
        string id, descripcion;
        cout << "Ingrese el ID del actor " << i + 1 << ": ";
        if (!getline(cin, id)) {
            throw runtime_error("Error al leer el ID del actor.");
        }
        cout << "Ingrese la descripcion del actor " << i + 1 << ": ";
        if (!getline(cin, descripcion)) {
            throw runtime_error("Error al leer la descripcion del actor.");
        }
        actores.emplace_back(id, descripcion);
    }
}
```
### Método `asignarTareasConInput`
El método asignarTareasConInput permite al usuario asignar tareas a los actores.
```cpp
void Launcher::asignarTareasConInput() {
    for (auto& actor : actores) {
        while (true) {
            string respuesta;
            cout << "¿Quieres asignarle una nueva tarea al actor " << actor.getDescripcion() << "? (s/n): ";
            if (!getline(cin, respuesta)) {
                throw runtime_error("Error al leer la respuesta.");
            }

            if (respuesta != "s" && respuesta != "S") {
                break;
            }

            string tareaId;
            cout << "Ingrese el ID de la tarea para el actor " << actor.getDescripcion() << ": ";
            if (!getline(cin, tareaId)) {
                throw runtime_error("Error al leer el ID de la tarea.");
            }

            auto it = find_if(tareas.begin(), tareas.end(), [&tareaId](const Tarea& tarea) {
                return tarea.getId() == tareaId;
            });

            if (it != tareas.end()) {
                actor.addTarea(*it);
            } else {
                cout << "Tarea con ID " << tareaId << " no encontrada." << endl;
            }
        }
    }
}
```

### Método `ejecutar`
El método ejecutar coordina la creación de tareas, la creación de actores, la asignación de tareas y la evaluación del tiempo total para completar las tareas.
```cpp
void Launcher::ejecutar() {
    try {
        tareas = crearTareas();
        crearActoresConInput();
        asignarTareasConInput();

        unordered_map<string, int> taskEndTimes;
        int tiempoTotal = 0;

        cout << "=== Resumen de tareas por actor ===" << endl;

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

        cout << "\n=== Verificacion de tiempos ===" << endl;
        for (const auto& actor : actores) {
            if (actor.getDuracionTotal() > 100) {
                cout << "El actor " << actor.getDescripcion() << " NO puede completar sus tareas a tiempo." << endl;
            } else {
                cout << "El actor " << actor.getDescripcion() << " puede completar sus tareas a tiempo." << endl;
            }
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
```
### Diagrama de Flujo
```graph TD
 A[Inicio] --> B[Crear tareas]
    B --> C[Crear actores]
    C --> D[Asignar tareas]
    D --> E[Calcular tiempos]
    E --> F{¿Se completan a tiempo?}
    F -->|Sí| G[Mostrar resumen]
    F -->|No| H[Notificar problemas]
    G --> I[Fin]
    H --> I
```

### Propuesta de solucion 
**Agentes Involucrados:**

•	**Agente 1**

•	**Agente 2**

•	**Agente 3**

•	**Agente 4**

•	**Agente 5** (Agencia de viajes)

•	**Familiares en casa** (No cuentan como agentes adicionales)

**Cronograma y Asignación de Tareas:**

**Agente 1:**

•	**Tarea A**: Reserva de vuelo

•	**Tiempo:** 0 - 20 min

•	**Descripción:** Realizar la reserva del vuelo.

•	**Tiempo libre:** 20 - 30 min

•	**Tarea E**: Recoger el billete de la agencia

•	**Tiempo:** 30 - 35 min

•	**Descripción:** Ir a la agencia a recoger el billete.

•	**Tarea F**: Llevar el billete a la oficina

•	**Tiempo:** 35 - 45 min

•	**Descripción:** Entregar el billete en la oficina.

•	**Tiempo libre:** 45 - 50 min

•	**Tarea H**: Llevar maletas a la oficina

•	**Tiempo:** 50 - 75 min

•	**Descripción:** Transportar las maletas desde casa hasta la oficina.

**Agente 2:**

•	**Tarea B**: Informar a casa para empacar

•	**Tiempo:** 0 - 5 min

•	**Descripción:** Comunicar a casa la necesidad de empacar.

•	**Tiempo libre:** 5 - 45 min

•	**Tarea G**: Recoger las maletas de casa

•	**Tiempo:** 45 - 65 min

•	**Descripción:** Ir a casa y recoger las maletas empacadas.

**Agente 3:**

•	**Tarea I**: Conversación sobre documentos requeridos

•	**Tiempo:** 0 - 35 min

•	**Descripción:** Reunión con el CEO para discutir documentos.

•	**Tarea K**: Reunir documentos

•	**Tiempo:** 35 - 50 min

•	**Descripción:** Recopilar los documentos necesarios.

•	**Tarea L**: Organizar documentos

•	**Tiempo:** 50 - 55 min

•	**Descripción:** Ordenar y preparar los documentos.

**Agente 4:**

•	**Tarea J**: Dictar instrucciones para ausencia

•	**Tiempo:** 0 - 25 min

•	**Descripción:** CEO dicta instrucciones; Agente 4 las registra.

•	**Tiempo libre:** 25 - 45 min

•	**Tarea D**: Preparación del billete por la agencia (asistencia)

•	**Tiempo:** 20 - 30 min (monitoreo)

•	**Descripción:** Coordinar con la agencia la preparación del billete (asistencia remota si es posible).

•	**Tiempo libre:** 45 - 65 min

•	**Apoyo adicional** si es necesario.

**Agente 5 (Agencia de Viajes):**

•	**Tarea D**: Preparación del billete por la agencia

•	**Tiempo:** 20 - 30 min

•	**Descripción:** Agencia prepara el billete.

**Familiares en Casa:**

•	**Tarea C**: Empacar maletas

•	**Tiempo:** 5 - 45 min

•	**Descripción:** Familiares empacan las maletas.

**CEO:**

•	**Tarea I**: Conversación sobre documentos requeridos

•	**Tiempo:** 0 - 35 min

•	**Tarea J**: Dictar instrucciones para ausencia

•	**Tiempo:** 0 - 25 min

•	**Tarea K**: Reunir documentos

•	**Tiempo:** 35 - 50 min

•	**Tarea L**: Organizar documentos

•	**Tiempo:** 50 - 55 min

•	**Tiempo de espera:** 55 - 75 min

•	**Tarea M**: Viajar al aeropuerto y facturar

•	**Tiempo:** 75 - 100 min