#include "../headerfiles/GestorRecetas.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

// Cargar recetas desde archivo
void GestorRecetas::cargarRecetasDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo de recetas." << std::endl;
        return;
    } else {
        std::cout << "Archivo abierto correctamente." << std::endl;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre;
        if (!getline(ss, nombre, ':')) continue;

        std::string ingredientesStr;
        if (!getline(ss, ingredientesStr)) continue;

        std::set<std::string> ingredientes;
        std::string ingrediente;
        std::stringstream ssIngredientes(ingredientesStr);
        while (getline(ssIngredientes, ingrediente, ',')) {
            ingrediente.erase(remove_if(ingrediente.begin(), ingrediente.end(), ::isspace), ingrediente.end());
            transform(ingrediente.begin(), ingrediente.end(), ingrediente.begin(), ::tolower);
            ingredientes.insert(ingrediente);
        }

        recetas.emplace_back(nombre, ingredientes);
    }

    archivo.close();
    std::cout << "Total de recetas cargadas: " << recetas.size() << std::endl;
}

// Agregar ingrediente del usuario
void GestorRecetas::agregarIngredienteDisponible(const std::string& ingrediente) {
    std::string limpio = ingrediente;
    transform(limpio.begin(), limpio.end(), limpio.begin(), ::tolower);
    ingredientesDisponibles.insert(limpio);
}

// Limpiar todos los ingredientes ingresados
void GestorRecetas::limpiarIngredientesDisponibles() {
    ingredientesDisponibles.clear();
}

// Buscar recetas que se pueden hacer con los ingredientes disponibles
std::vector<Receta> GestorRecetas::buscarRecetas() const {
    std::vector<Receta> posibles;
    for (const auto& receta : recetas) {
        std::set<std::string> ing = receta.getIngredientes();
        bool disponible = true;
        for (const auto& i : ing) {
            if (ingredientesDisponibles.find(i) == ingredientesDisponibles.end()) {
                disponible = false;
                break;
            }
        }
        if (disponible) {
            posibles.push_back(receta);
        }
    }
    return posibles;
}

// Mostrar recetas disponibles
void GestorRecetas::mostrarRecetasDisponibles() const {
    std::vector<Receta> posibles = buscarRecetas();
    if (posibles.empty()) {
        std::cout << "No hay recetas disponibles con los ingredientes ingresados.\n";
    } else {
        std::cout << "Recetas disponibles:\n";
        for (const auto& r : posibles) {
            std::cout << "- " << r.getNombre() << "\n";
        }
    }
}
