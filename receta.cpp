#include "Receta.hpp"

Receta::Receta(std::string nombre, std::set<std::string> ingredientes)
    : nombre(nombre), ingredientes(ingredientes) {}

std::string Receta::getNombre() const {
    return nombre;
}

std::set<std::string> Receta::getIngredientes() const {
    return ingredientes;
}
