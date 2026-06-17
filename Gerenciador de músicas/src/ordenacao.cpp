#include "ordenacao.h"
#include <utility> //Biblioteca para std::swap
#include <cctype> //Biblioteca para funções de manipulação de caracteres

//Função auxiliar para converter uma string para minúsculo, facilitando a comparação durante a ordenação.
static std::string paraMinusculo(const std::string& texto) {
    std::string resultado = texto;

    for (char& c : resultado) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    return resultado;
}

//Ordena as músicas pelo título utilizando Bubble Sort.
void bubbleSort(std::vector<Musica>& musicas) {
    bool trocado;

    for (size_t i = 0; i < musicas.size() - 1; i++) {
        trocado = false;

        for (size_t j = 0; j < musicas.size() - i - 1; j++) {
            if (paraMinusculo(musicas[j].titulo) > paraMinusculo(musicas[j + 1].titulo)) {
				std::swap(musicas[j], musicas[j + 1]); //Troca os elementos

                trocado = true;
            }
        }

        if (!trocado) {
            break;
        }
    }
}

//Ordena as músicas pelo título utilizando Insertion Sort.
void insertionSort(std::vector<Musica>& musicas) {
    for (size_t i = 1; i < musicas.size(); i++) {
        Musica chave = musicas[i];

        int j = static_cast<int>(i) - 1;

        while (j >= 0 && paraMinusculo(musicas[j].titulo) > paraMinusculo(chave.titulo)) {
            musicas[j + 1] = musicas[j];
            j--;
        }

        musicas[j + 1] = chave;
    }
}

//Função auxiliar do Merge Sort.
static void merge(std::vector<Musica>& musicas, int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    std::vector<Musica> esquerdaVet(n1);
    std::vector<Musica> direitaVet(n2);

    for (int i = 0; i < n1; i++) {
        esquerdaVet[i] = musicas[esquerda + i];
    }

    for (int j = 0; j < n2; j++) {
        direitaVet[j] = musicas[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esquerda;

    while (i < n1 && j < n2) {
        if (esquerdaVet[i].titulo <= direitaVet[j].titulo) {
            musicas[k] = esquerdaVet[i];
            i++;
        }
        else {
            musicas[k] = direitaVet[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        musicas[k] = esquerdaVet[i];
        i++;
        k++;
    }

    while (j < n2) {
        musicas[k] = direitaVet[j];
        j++;
        k++;
    }
}

//Ordena as músicas pelo título utilizando Merge Sort.
void mergeSort(std::vector<Musica>& musicas, int esquerda, int direita) {
    if (esquerda >= direita) {
        return;
    }

    int meio = esquerda + (direita - esquerda) / 2;

    mergeSort(musicas, esquerda, meio);

    mergeSort(musicas, meio + 1, direita);

    merge(musicas, esquerda, meio, direita);
}