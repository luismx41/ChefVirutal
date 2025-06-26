#include "GestorRecetas.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void GestorRecetas::cargarRecetasDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre;
        std::getline(ss, nombre, ':');

        std::string ingrediente;
        std::set<std::string> ingredientes;
        while (std::getline(ss, ingrediente, ',')) {
            // para limpiar espacios y pasar a minúscula
            ingrediente.erase(0, ingrediente.find_first_not_of(" \t"));
            ingrediente.erase(ingrediente.find_last_not_of(" \t") + 1);
            std::transform(ingrediente.begin(), ingrediente.end(), ingrediente.begin(), ::tolower);

            ingredientes.insert(ingrediente);
        }

        recetas.emplace_back(nombre, ingredientes);
    }
}

std::vector<Receta> GestorRecetas::buscarRecetas(const std::set<std::string>& disponibles) const {
    std::vector<Receta> posibles;

    for (const auto& receta : recetas) {
        bool puedePreparar = true;
        for (const auto& ing : receta.getIngredientes()) {
            if (disponibles.find(ing) == disponibles.end()) {
                puedePreparar = false;
                break;
            }
        }
        if (puedePreparar) {
            posibles.push_back(receta);
        }
    }

    return posibles;
}

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
