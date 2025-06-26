#include "GestorRecetas.hpp"
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

int main() {
    GestorRecetas gestor;
    gestor.cargarRecetasDesdeArchivo("recetas.txt");

    std::set<std::string> ingredientes;
    int opcion;
    std::string entrada;

    do {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Agregar ingrediente\n";
        std::cout << "2. Mostrar recetas disponibles\n";
        std::cout << "3. Limpiar ingredientes\n";
        std::cout << "4. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1:
                std::cout << "Ingrese un ingrediente: ";
                std::getline(std::cin, entrada);

            
                entrada.erase(0, entrada.find_first_not_of(" 	"));
                entrada.erase(entrada.find_last_not_of(" 	") + 1);

                
                std::transform(entrada.begin(), entrada.end(), entrada.begin(), ::tolower);

                ingredientes.insert(entrada);
                break;
            case 2:
                gestor.mostrarRecetasDisponibles(ingredientes);
                break;
            case 3:
                ingredientes.clear();
                std::cout << "Lista de ingredientes limpiada.\n";
                break;
            case 4:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}
