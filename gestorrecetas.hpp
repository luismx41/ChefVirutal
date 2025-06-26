#ifndef GESTORRECETAS_HPP
#define GESTORRECETAS_HPP

#include "Receta.hpp"
#include <vector>
#include <string>
#include <set>

class GestorRecetas {
private:
    std::vector<Receta> recetas;

public:
    void cargarRecetasDesdeArchivo(const std::string& nombreArchivo);
    std::vector<Receta> buscarRecetas(const std::set<std::string>& disponibles) const;
    void mostrarRecetasDisponibles(const std::set<std::string>& disponibles) const;
};

#endif
