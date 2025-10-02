📚 Trabalho de Estrutura de Dados — Ordenação de Arquivos
📖 Descrição

Este projeto foi desenvolvido como parte da disciplina Estrutura de Dados.
O objetivo é implementar e analisar algoritmos de ordenação aplicados a arquivos de texto contendo listas grandes de palavras.

Foram utilizados 3 arquivos de entrada com diferentes tamanhos:

📂 nomes_100k.txt → 100.000 palavras

📂 nomes_250k.txt → 250.000 palavras

📂 nomes_500k.txt → 500.000 palavras

O programa realiza a leitura dos arquivos, aplica os algoritmos de ordenação, e gera arquivos de saída com as palavras ordenadas.

⚙️ Funcionalidades

Remoção de caracteres inválidos (números e símbolos).

Conversão de todas as palavras para minúsculas.

Ordenação das palavras utilizando algoritmos clássicos e avançados.

Exportação dos resultados em arquivos .txt.

Medição de tempo de execução para comparação entre algoritmos.

🧩 Algoritmos de Ordenação Implementados

Bubble Sort

Insertion Sort

Selection Sort

Merge Sort

Quick Sort

Heap Sort

Shell Sort


Foram escolhidos algoritmos de complexidade O(n²) e O(n log n) para comparação de desempenho em diferentes tamanhos de entrada.

🚀 Como Compilar e Executar
Compilação
g++ -o ordenacao main.cpp

Execução
./ordenacao nomes_100k.txt
./ordenacao nomes_250k.txt
./ordenacao nomes_500k.txt


O programa gera arquivos de saída:

nomes_100k_ordenado.txt

nomes_250k_ordenado.txt

nomes_500k_ordenado.txt

📊 Análise de Desempenho

Durante a execução, o programa exibe o tempo de execução de cada algoritmo de ordenação para permitir a análise comparativa.

👨‍💻 Colaboradores

Este projeto foi desenvolvido em grupo para a disciplina de Estrutura de Dados:

@Gustasssdev

@DiogoRangel11

@Cieliocas

📝 Licença

Este projeto é de uso acadêmico e foi desenvolvido para fins educacionais.
