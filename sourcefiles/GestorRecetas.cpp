#include "../headerfiles/GestorRecetas.hpp"
#include "../headerfiles/Receta.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Esta funcion lee el archivo de recetas y guarda cada linea como una receta
void GestorRecetas::cargarRecetasDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre;
        std::getline(ss, nombre, ':'); // Separa el nombre de los ingredientes

        std::string ingrediente;
        std::set<std::string> ingredientes;

        // Lee todos los ingredientes separados por coma
        while (std::getline(ss, ingrediente, ',')) {
            // Quita espacios al inicio y al final
            ingrediente.erase(0, ingrediente.find_first_not_of(" \t"));
            ingrediente.erase(ingrediente.find_last_not_of(" \t") + 1);

            // Pasa todo a minusculas para que no haya problemas al comparar
            std::transform(ingrediente.begin(), ingrediente.end(), ingrediente.begin(), ::tolower);

            ingredientes.insert(ingrediente);
        }

        // Crea una receta y la añade a la lista
        recetas.emplace_back(nombre, ingredientes);
    }
}

// Esta funcion compara los ingredientes que tiene el usuario con cada receta
// y devuelve solo las que puede hacer completas
std::vector<Receta> GestorRecetas::buscarRecetas(const std::set<std::string>& disponibles) const {
    std::vector<Receta> posibles;

    for (const auto& receta : recetas) {
        bool puedePreparar = true;

        // Recorremos los ingredientes de la receta y verificamos si todos están disponibles
        for (const auto& ing : receta.getIngredientes()) {
            if (disponibles.find(ing) == disponibles.end()) {
                puedePreparar = false; // si falta uno, ya no vale
                break;
            }
        }

        if (puedePreparar) {
            posibles.push_back(receta);
        }
    }

    return posibles;
}

// Muestra en consola las recetas que si se pueden hacer
void GestorRecetas::mostrarRecetasDisponibles(const std::set<std::string>& disponibles) const {
    auto posibles = buscarRecetas(disponibles);

    if (posibles.empty()) {
        std::cout << "No hay recetas disponibles con los ingredientes ingresados.\n";
    } else {
        std::cout << "Recetas disponibles:\n";
        for (const auto& r : posibles) {
            std::cout << "- " << r.getNombre() << "\n";
        }
    }
}
