#pragma once

#include <vector>
#include "musica.h"

//Ordena as músicas pelo título utilizando Bubble Sort.
void bubbleSort(std::vector<Musica>& musicas);

// Ordena as músicas pelo título utilizando Insertion Sort.
void insertionSort(std::vector<Musica>& musicas);

// Ordena as músicas pelo título utilizando Merge Sort.
void mergeSort(std::vector<Musica>& musicas, int esquerda, int direita);