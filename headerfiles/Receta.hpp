#ifndef RECETA_HPP
#define RECETA_HPP

#include <string>
#include <set>

// Esta clase representa una receta.
// Guarda el nombre y los ingredientes que necesita.
class Receta {
private:
    std::string nombre;
    std::set<std::string> ingredientes;

public:
    // Constructor: le pasamos un nombre y un conjunto de ingredientes
    Receta(std::string nombre, std::set<std::string> ingredientes);

    // Devuelve el nombre de la receta
    std::string getNombre() const;

    // Devuelve los ingredientes de la receta
    std::set<std::string> getIngredientes() const;
};

#endif
