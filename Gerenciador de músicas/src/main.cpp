#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "busca.h"
#include "csv.h"
#include "ordenacao.h"

int main() {
	//Lista de arquivos CSV a serem processados.
    std::vector<std::string> arquivos = {"1000.csv", "5000.csv", "20000.csv"};

	//Lista de chaves de busca para cada arquivo.
    std::vector<std::vector<std::string>> buscas = {{"During sell", "Shoulder great just", "Require", "Meet at any", "Activity ago"}, {"Long board", "Four gas", "Way general", "Cup", "Beat media"}, {"Start very", "High", "Same we", "Different", "Friend"}};

	//Criar o arquivo de relatório CSV para armazenar os resultados.
    std::ofstream relatorio("resultados.csv");

    if (!relatorio) {
        std::cerr << "Erro ao criar o arquivo resultados.csv\n";
        return 1;
    }

	//Escrever o cabeçalho do relatório CSV.
    relatorio << "Arquivo,Algoritmo,Tempo_Segundos\n";

    std::cout << std::fixed << std::setprecision(6);
    
	//Processar cada arquivo CSV, carregar as músicas, ordenar e realizar buscas, enquanto mede o tempo gasto para cada operação.
    for (size_t i = 0; i < arquivos.size(); i++) {
        std::cout << "Arquivo: " << arquivos[i] << std::endl;

        auto inicio = std::chrono::high_resolution_clock::now();
        std::vector<Musica> musicas = carregarMusicas(arquivos[i]);
        auto fim = std::chrono::high_resolution_clock::now();

        double tempoCarregamento = std::chrono::duration<double>(fim - inicio).count();

        std::cout << "Musicas carregadas: " << musicas.size() << std::endl;
        std::cout << "Tempo de carregamento: " << tempoCarregamento << " s\n";

        relatorio << arquivos[i] << ",Carregamento," << tempoCarregamento << '\n';

        if (musicas.empty()) {
            std::cout << "Nenhuma musica encontrada.\n";
            std::cout << "--------------------------------------------------\n";
            continue;
        }

        std::vector<Musica> musicasBubble = musicas;
        std::vector<Musica> musicasInsertion = musicas;
        std::vector<Musica> musicasMerge = musicas;

        inicio = std::chrono::high_resolution_clock::now();
        bubbleSort(musicasBubble);
        fim = std::chrono::high_resolution_clock::now();

        double tempoBubble = std::chrono::duration<double>(fim - inicio).count();

        std::cout << "Tempo Bubble Sort: " << tempoBubble << " s\n";

        relatorio << arquivos[i] << ",Bubble Sort," << tempoBubble << '\n';

        inicio = std::chrono::high_resolution_clock::now();
        insertionSort(musicasInsertion);
        fim = std::chrono::high_resolution_clock::now();

        double tempoInsertion = std::chrono::duration<double>(fim - inicio).count();

        std::cout << "Tempo Insertion Sort: " << tempoInsertion << " s\n";

        relatorio << arquivos[i] << ",Insertion Sort," << tempoInsertion << '\n';

        inicio = std::chrono::high_resolution_clock::now();
        mergeSort(musicasMerge, 0, static_cast<int>(musicasMerge.size()) - 1);
        fim = std::chrono::high_resolution_clock::now();

        double tempoMerge = std::chrono::duration<double>(fim - inicio).count();

        std::cout << "Tempo Merge Sort: " << tempoMerge << " s\n";

        relatorio << arquivos[i] << ",Merge Sort," << tempoMerge << '\n';

        std::cout << "Buscas na lista ordenada por Merge Sort:\n";

		//Realizar buscas binárias para cada chave de busca na lista ordenada por Merge Sort, medir o tempo gasto para cada busca e registrar os resultados no relatório CSV.
        for (const auto& chave : buscas[i]) {
            inicio = std::chrono::high_resolution_clock::now();
            int indice = buscaBinaria(musicasMerge, chave);
            fim = std::chrono::high_resolution_clock::now();

            double tempoBusca = std::chrono::duration<double>(fim - inicio).count();

            std::cout << "  " << chave << ": " << (indice != -1 ? "encontrada" : "nao encontrada") << " em " << tempoBusca << " s\n";

            relatorio << arquivos[i] << ",Busca Binaria - " << chave << "," << tempoBusca << '\n';
        }

        std::cout << "--------------------------------------------------\n";
    }

    std::cout << "Relatorio salvo em resultados.csv\n";

    return 0;
}