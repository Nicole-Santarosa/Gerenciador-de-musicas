#include "busca.h"
#include <cctype>

//Converte uma string para minúsculo.
std::string paraMinusculo(const std::string& texto) {
    std::string resultado = texto;

    for (char& c : resultado) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    return resultado;
}

//Busca binária por título exato.
int buscaBinaria(const std::vector<Musica>& musicas, const std::string& chave) {
    std::string chaveBusca = paraMinusculo(chave);

    int esquerda = 0;
    int direita = static_cast<int>(musicas.size()) - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        std::string titulo = paraMinusculo(musicas[meio].titulo);

        if (titulo == chaveBusca) {
            return meio;
        }

        if (titulo < chaveBusca) {
            esquerda = meio + 1;
        }
        else {
            direita = meio - 1;
        }
    }

    return -1;
}

//Busca por parte do título.
std::vector<int> buscaParcial(const std::vector<Musica>& musicas, const std::string& termo) {
    std::vector<int> resultados;

    std::string busca = paraMinusculo(termo);

    for (size_t i = 0; i < musicas.size(); i++) {
        std::string titulo = paraMinusculo(musicas[i].titulo);

        if (titulo.find(busca) != std::string::npos) {
            resultados.push_back(static_cast<int>(i));
        }
    }

    return resultados;
}

//Busca músicas de um artista específico.
std::vector<Musica> buscarPorArtista(const std::vector<Musica>& musicas, const std::string& artista) {
    std::vector<Musica> resultado;

    std::string artistaBusca = paraMinusculo(artista);

    for (const auto& musica : musicas) {
        if (paraMinusculo(musica.artista) == artistaBusca) {
            resultado.push_back(musica);
        }
    }

    return resultado;
}