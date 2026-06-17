#pragma once

#include <string>

/**
 * @brief Representa uma música do catálogo.
 */
struct Musica {
    std::string titulo;
    std::string artista;
    double duracao;
    std::string album;
    std::string genero;
};