#include "GestorRecetas.hpp"
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits> // esto se usa para limpiar la entrada si el usuario mete texto en lugar de un número

int main() {
    // Creamos el gestor de recetas y leemos las recetas desde el archivo
    GestorRecetas gestor;
    gestor.cargarRecetasDesdeArchivo("recetas.txt");

    // Aquí vamos a guardar los ingredientes que tiene el usuario
    std::set<std::string> ingredientes;
    int opcion;              // para guardar la opción que elige el usuario
    std::string entrada;     // para leer lo que el usuario escribe

    do {
        // Mostramos el menú principal
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Agregar ingredientes\n";
        std::cout << "2. Mostrar recetas disponibles\n";
        std::cout << "3. Limpiar ingredientes\n";
        std::cout << "4. Salir\n";
        std::cout << "Opcion: ";

        // Esto es por si el usuario mete texto en vez de número (como "tomate")
        if (!(std::cin >> opcion)) {
            std::cin.clear(); // limpiamos el error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // borramos la entrada
            std::cout << "Entrada no valida. Por favor escribe 1, 2, 3 o 4.\n";
            continue;
        }

        std::cin.ignore(); // para ignorar el enter que queda pendiente

        switch (opcion) {
            case 1:
                std::cout << "Ingrese uno o varios ingredientes separados por coma o espacio: ";
                std::getline(std::cin, entrada); // aquí leemos toda la línea que el usuario escribe

                // Recorremos el string y si hay comas las cambiamos por espacios
                // Así da igual si separa con comas o con espacios
                for (char& c : entrada) {
                    if (c == ',') c = ' ';
                }

                {
                    std::stringstream ss(entrada);
                    std::string ing;

                    // Vamos leyendo cada palabra (ingrediente)
                    while (ss >> ing) {
                        // Esto limpia los espacios que puedan quedar al principio o al final
                        ing.erase(0, ing.find_first_not_of(" \t"));
                        ing.erase(ing.find_last_not_of(" \t") + 1);

                        // Aqui pasamos todo a minúsculas para que no importe cómo lo escribe
                        std::transform(ing.begin(), ing.end(), ing.begin(), ::tolower);

                        // Finalmente lo añadimos al set de ingredientes
                        ingredientes.insert(ing);
                    }
                }
                break;

            case 2:
                // Llamamos a la función para mostrar qué recetas se pueden hacer
                gestor.mostrarRecetasDisponibles(ingredientes);
                break;

            case 3:
                // Esto simplemente borra todos los ingredientes agregados
                ingredientes.clear();
                std::cout << "Lista de ingredientes limpiada.\n";
                break;

            case 4:
                // Salimos del programa
                std::cout << "Saliendo del programa...\n";
                break;

            default:
                // Si elige un número que no es 1-4 para evitar que se me crashee si por error pongo otra cosa
                std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 4); // se repite el menú mientras no elija salir

    return 0;
}
