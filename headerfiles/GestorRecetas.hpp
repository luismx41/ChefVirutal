#ifndef GESTOR_RECETAS_HPP
#define GESTOR_RECETAS_HPP

#include "Receta.hpp"
#include <vector>
#include <string>
#include <set>

class GestorRecetas {
private:
    std::vector<Receta> recetas;                   // Lista de recetas cargadas desde el archivo
    std::set<std::string> ingredientesDisponibles; // Ingredientes que el usuario ha añadido

public:
    // Cargar recetas desde archivo
    void cargarRecetasDesdeArchivo(const std::string& nombreArchivo);

    // Mostrar recetas que se pueden preparar con los ingredientes ingresados
    void mostrarRecetasDisponibles() const;

    // Añadir un ingrediente que el usuario ha puesto
    void agregarIngredienteDisponible(const std::string& ingrediente);

    // Limpiar todos los ingredientes disponibles añadidos por el usuario
    void limpiarIngredientesDisponibles();

    // Método interno para buscar recetas posibles según los ingredientes
    std::vector<Receta> buscarRecetas() const;
};

#endif
