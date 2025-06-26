#include "../headerfiles/Receta.hpp"

// Guardamos el nombre y los ingredientes en los atributos de la clase
Receta::Receta(std::string nombre, std::set<std::string> ingredientes)
    : nombre(nombre), ingredientes(ingredientes) {}

// Funcion para obtener el nombre de la receta
std::string Receta::getNombre() const {
    return nombre;
}

// Funcion para obtener los ingredientes de la receta
std::set<std::string> Receta::getIngredientes() const {
    return ingredientes;
}
