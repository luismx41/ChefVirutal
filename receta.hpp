#ifndef RECETA_HPP
#define RECETA_HPP

#include <string>
#include <set>

class Receta {
private:
    std::string nombre;
    std::set<std::string> ingredientes;

public:
    Receta(std::string nombre, std::set<std::string> ingredientes);

    std::string getNombre() const;
    std::set<std::string> getIngredientes() const;
};

#endif
