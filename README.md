# Gerenciador de Músicas

Projeto desenvolvido em C++ para leitura de arquivos CSV, ordenação de músicas e comparação de desempenho entre diferentes algoritmos de ordenação e busca.

## Sobre o projeto

Este sistema carrega listas de músicas a partir de arquivos CSV, organiza os dados em memória e executa testes de desempenho com os algoritmos:

- Bubble Sort
- Insertion Sort
- Merge Sort
- Busca Binária

Além disso, o programa gera um arquivo `resultado.csv` com os tempos medidos durante a execução, permitindo a análise posterior dos resultados em planilhas ou gráficos.

## Objetivos

- Praticar manipulação de arquivos em C++
- Aplicar estruturas como `struct` e `vector`
- Implementar algoritmos clássicos de ordenação e busca
- Comparar o desempenho entre diferentes abordagens
- Organizar o projeto em módulos separados
- Gerar dados para análise de performance

## Habilidades demonstradas

- Programação em C++
- Manipulação de arquivos CSV
- Estruturas de dados (`struct` e `vector`)
- Algoritmos de ordenação
- Busca binária
- Medição de desempenho com `chrono`
- Modularização com arquivos `.h` e `.cpp`
- Análise de complexidade de algoritmos

## Funcionalidades

- Leitura de músicas a partir de arquivos CSV
- Armazenamento dos dados em memória
- Ordenação por título
- Busca binária por título
- Medição de tempo de execução
- Geração automática do arquivo `resultado.csv`

## Estrutura do projeto

```text
src/
├── main.cpp
├── musica.h
├── csv.h
├── csv.cpp
├── busca.h
├── busca.cpp
├── ordenacao.h
└── ordenacao.cpp

data/
├── 1000.csv
├── 5000.csv
└── 20000.csv

resultado.csv

## Tecnologias utilizadas

- C++
- STL (`vector`, `string`, `fstream`, `sstream`)
- `chrono` para medição de tempo
- CSV para armazenamento de dados

---

## Como funciona

1. O programa lê os arquivos `1000.csv`, `5000.csv` e `20000.csv`.
2. Os dados são carregados para um vetor de estruturas `Musica`.
3. O vetor original é copiado para testar cada algoritmo de forma justa.
4. Cada ordenação é executada separadamente.
5. O tempo de execução é registrado no console e no arquivo `resultado.csv`.
6. Após a ordenação, são realizadas buscas binárias em títulos específicos.

---

## Formato do CSV

Os arquivos de entrada devem seguir este formato:

```csv
titulo,artista,duracao,album,genero
Shape of You,Ed Sheeran,3.53,Divide,Pop
Blinding Lights,The Weeknd,3.20,After Hours,Pop
Bohemian Rhapsody,Queen,5.55,A Night at the Opera,Rock
```

A ordem dos campos é:

1. `titulo`
2. `artista`
3. `duracao`
4. `album`
5. `genero`

---

## Resultados

Ao final da execução, o arquivo `resultado.csv` é gerado com dados como:

```csv
Arquivo,Algoritmo,Tempo_Segundos
1000.csv,Bubble Sort,0.0231
1000.csv,Insertion Sort,0.0104
1000.csv,Merge Sort,0.0012
1000.csv,Busca Binaria - High,0.000003
```

Esses resultados podem ser usados para criar gráficos comparativos em Excel, Google Sheets ou LibreOffice Calc.

---

## Como executar

1. Compile o projeto.
2. Coloque os arquivos `1000.csv`, `5000.csv` e `20000.csv` na pasta `data/`.
3. Execute o programa.
4. Verifique o console e o arquivo `resultado.csv`.

---

## Observações

- A busca binária só funciona corretamente quando o vetor está ordenado pelo mesmo critério usado na comparação.
- O Merge Sort apresenta melhor desempenho em bases maiores.
- Os arquivos CSV usados no projeto contêm dados fictícios, criados para fins de teste e comparação de algoritmos.
- O projeto foi estruturado em módulos para facilitar a manutenção e reutilização do código.

---

## Autor

Desenvolvido por **Nicole Santarosa** para fins acadêmicos e de portfólio.
