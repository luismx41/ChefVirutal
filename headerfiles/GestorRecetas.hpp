#ifndef GESTORRECETAS_HPP
#define GESTORRECETAS_HPP

#include "Receta.hpp"
#include <vector>
#include <string>

// Esta clase se encarga de manejar todas las recetas
class GestorRecetas {
private:
    std::vector<Receta> recetas; // Aqui se guardan todas las recetas cargadas

public:
    // Carga las recetas desde un archivo
    void cargarRecetasDesdeArchivo(const std::string& nombreArchivo);

    // Busca las recetas que se pueden preparar con los ingredientes que hay
    std::vector<Receta> buscarRecetas(const std::set<std::string>& disponibles) const;

    // Muestra en consola las recetas que se pueden hacer
    void mostrarRecetasDisponibles(const std::set<std::string>& disponibles) const;
};

#endif
