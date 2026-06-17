#include "csv.h"
#include <fstream>
#include <sstream>
#include <iostream>

//Função para carregar as músicas de um arquivo CSV.
std::vector<Musica> carregarMusicas(const std::string& nomeArquivo) {
    std::vector<Musica> musicas;

    std::ifstream arquivo(nomeArquivo);

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;

        return musicas;
    }

    std::string linha;

    //Ignora o cabeçalho.
    std::getline(arquivo, linha);

    while (std::getline(arquivo, linha)) {
        if (linha.empty()) {
            continue;
        }

        std::stringstream ss(linha);

        std::string campo;

        Musica musica;

        if (std::getline(ss, campo, ',')) {
            musica.titulo = campo;
        }

        if (std::getline(ss, campo, ',')) {
            musica.artista = campo;
        }

        if (std::getline(ss, campo, ',')) {
            try {
                musica.duracao = std::stod(campo);
            }
			catch (...) { //Em caso de erro na conversão, define a duração como 0.0
                musica.duracao = 0.0;
            }
        }

        if (std::getline(ss, campo, ',')) {
            musica.album = campo;
        }

        if (std::getline(ss, campo, ',')) {
            musica.genero = campo;
        }

        if (!musica.titulo.empty()) {
            musicas.push_back(musica);
        }
    }

    return musicas;
}