#include "headerfiles/GestorRecetas.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits>
#include <filesystem> // Para rutas relativas seguras

int main()
{
    // Mostrar la ruta actual de ejecución (útil para depurar)
    std::cout << "Ejecutando desde: " << std::filesystem::current_path() << std::endl;

    // Ruta relativa segura: datos/recetas.txt (desde el directorio del .exe)
    std::filesystem::path ruta = std::filesystem::current_path() / "datos" / "recetas.txt";

    GestorRecetas gestor;
    gestor.cargarRecetasDesdeArchivo(ruta.string());

    int opcion;
    std::string entrada;

    do
    {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Agregar ingredientes\n";
        std::cout << "2. Mostrar recetas disponibles\n";
        std::cout << "3. Limpiar ingredientes\n";
        std::cout << "4. Salir\n";
        std::cout << "Opcion: ";

        if (!(std::cin >> opcion))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada no valida. Por favor escribe 1, 2, 3 o 4.\n";
            continue;
        }

        std::cin.ignore();

        switch (opcion)
        {
        case 1:
            std::cout << "Ingrese uno o varios ingredientes separados por coma o espacio: ";
            std::getline(std::cin, entrada);

            for (char &c : entrada)
            {
                if (c == ',')
                    c = ' ';
            }

            {
                std::stringstream ss(entrada);
                std::string ing;

                while (ss >> ing)
                {
                    ing.erase(0, ing.find_first_not_of(" \t"));
                    ing.erase(ing.find_last_not_of(" \t") + 1);
                    std::transform(ing.begin(), ing.end(), ing.begin(), ::tolower);
                    gestor.agregarIngredienteDisponible(ing);
                }
            }
            break;

        case 2:
            gestor.mostrarRecetasDisponibles();
            break;

        case 3:
            gestor.limpiarIngredientesDisponibles();
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
