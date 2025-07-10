cmake_minimum_required(VERSION 3.10)

project(ChefVirtual)

# Usar C++ estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir carpeta de headers
include_directories(headerfiles)

# Archivos fuente
add_executable(ChefVirtual
    main.cpp
    sourcefiles/Receta.cpp
    sourcefiles/GestorRecetas.cpp
)

