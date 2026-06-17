#pragma once

#include <vector>
#include <string>
#include "musica.h"

//Converte uma string para minúsculo.
std::string paraMinusculo(const std::string& texto);

//Busca binária por título exato.
int buscaBinaria(const std::vector<Musica>& musicas, const std::string& chave);

//Busca por parte do título.
std::vector<int> buscaParcial(const std::vector<Musica>& musicas, const std::string& termo);

//Busca músicas de um artista específico.
std::vector<Musica> buscarPorArtista(const std::vector<Musica>& musicas, const std::string& artista);