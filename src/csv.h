#pragma once

#include <vector>
#include <string>
#include "musica.h"

/**
 * @brief Carrega músicas a partir de um arquivo CSV.
 * @param nomeArquivo Caminho do arquivo CSV.
 * @return Vetor contendo as músicas carregadas.
 */
std::vector<Musica> carregarMusicas(const std::string& nomeArquivo);