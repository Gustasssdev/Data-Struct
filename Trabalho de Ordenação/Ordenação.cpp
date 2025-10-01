#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <cctype>

using namespace std;

// Função para limpar nome (remove números e caracteres estranhos)
string limparNome(const string &nome) {
    string limpo;
    for (char c : nome) {
        if (isalpha(static_cast<unsigned char>(c)) || isspace(static_cast<unsigned char>(c))) {
            limpo += static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
    }
    while (!limpo.empty() && isspace(limpo.front())) limpo.erase(limpo.begin());
    while (!limpo.empty() && isspace(limpo.back())) limpo.pop_back();
    return limpo;
}

// Bubble Sort
void bubbleSort(vector<string> &lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                swap(lista[j], lista[j + 1]);
                trocou = true;
            }
        }
        if (!trocou) break;
    }
}

// Insertion Sort
void insertionSort(vector<string> &lista) {
    int n = lista.size();
    for (int i = 1; i < n; i++) {
        string chave = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > chave) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = chave;
    }
}

// Selection Sort
void selectionSort(vector<string> &lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) swap(lista[i], lista[minIndex]);
    }
}

// Função para medir o tempo de ordenação
void medirTempo(void (*ordenar)(vector<string>&), vector<string> &nomes, const string &nomeAlgoritmo) {
    auto inicio = chrono::high_resolution_clock::now();
    ordenar(nomes);
    auto fim = chrono::high_resolution_clock::now();

    auto duracao = chrono::duration_cast<chrono::milliseconds>(fim - inicio);
    long long total_ms = duracao.count();

    long long horas = total_ms / (1000 * 60 * 60);
    total_ms %= (1000 * 60 * 60);
    long long minutos = total_ms / (1000 * 60);
    total_ms %= (1000 * 60);
    long long segundos = total_ms / 1000;
    long long milissegundos = total_ms % 1000;

    cout << "Tempo gasto pelo " << nomeAlgoritmo << ": "
         << horas << "h "
         << minutos << "m "
         << segundos << "s "
         << milissegundos << "ms" << endl;
}

int main() {
    cout << "Escolha o algoritmo de ordenação:\n";
    cout << "1 - Bubble Sort\n2 - Insertion Sort\n3 - Selection Sort\n";
    int escolhaAlg;
    cin >> escolhaAlg;

    string arquivo;
    cout << "Digite o nome do arquivo a ser ordenado (ex: nomes100k.txt): ";
    cin >> arquivo;

    ifstream entrada(arquivo);
    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo " << arquivo << endl;
        return 1;
    }

    vector<string> nomes;
    string linha;
    while (getline(entrada, linha)) {
        string nome = limparNome(linha);
        if (!nome.empty()) nomes.push_back(nome);
    }
    entrada.close();

    cout << "Quantidade de nomes lidos: " << nomes.size() << endl;

    // Executar o algoritmo escolhido
    switch (escolhaAlg) {
        case 1:
            medirTempo(bubbleSort, nomes, "Bubble Sort");
            break;
        case 2:
            medirTempo(insertionSort, nomes, "Insertion Sort");
            break;
        case 3:
            medirTempo(selectionSort, nomes, "Selection Sort");
            break;
        default:
            cout << "Escolha inválida!" << endl;
            return 1;
    }

    // Salvar arquivo ordenado
    ofstream saida("nomes_ordenados.txt");
    for (const auto &nome : nomes) {
        saida << nome << "\n";
    }
    saida.close();
    cout << "Ordenação concluída! Resultado salvo em nomes_ordenados.txt" << endl;

    return 0;
}
