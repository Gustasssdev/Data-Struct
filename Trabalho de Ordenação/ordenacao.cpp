#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <cctype>
#include <algorithm>

using namespace std;

// ---------------------- Funções de Suporte ----------------------

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

// ---------------------- Algoritmos de Ordenação ----------------------

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

// Shell Sort
void shellSort(vector<string> &lista) {
    int n = lista.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            string temp = lista[i];
            int j;
            for (j = i; j >= gap && lista[j - gap] > temp; j -= gap) {
                lista[j] = lista[j - gap];
            }
            lista[j] = temp;
        }
    }
}

// Heapify (suporte ao Heap Sort)
void heapify(vector<string> &lista, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && lista[l] > lista[largest]) largest = l;
    if (r < n && lista[r] > lista[largest]) largest = r;

    if (largest != i) {
        swap(lista[i], lista[largest]);
        heapify(lista, n, largest);
    }
}

// Heap Sort
void heapSort(vector<string> &lista) {
    int n = lista.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(lista, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(lista[0], lista[i]);
        heapify(lista, i, 0);
    }
}

// Merge (suporte ao Merge Sort)
void merge(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<string>& lista, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(lista, left, mid);
    mergeSort(lista, mid + 1, right);
    merge(lista, left, mid, right);
}
void mergeSortWrapper(vector<string>& lista) {
    if (!lista.empty()) mergeSort(lista, 0, lista.size() - 1);
}

// Partition (suporte ao Quick Sort)
int partition(vector<string>& arr, int low, int high) {
    string pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<string>& lista, int low, int high) {
    if (low < high) {
        int pi = partition(lista, low, high);
        quickSort(lista, low, pi - 1);
        quickSort(lista, pi + 1, high);
    }
}
void quickSortWrapper(vector<string>& lista) {
    if (!lista.empty()) quickSort(lista, 0, lista.size() - 1);
}

// ---------------------- Programa Principal ----------------------
int main() {
    cout << "Escolha o algoritmo de ordenacao:\n";
    cout << "1 - Bubble Sort\n"
         << "2 - Insertion Sort\n"
         << "3 - Selection Sort\n"
         << "4 - Shell Sort\n"
         << "5 - Heap Sort\n"
         << "6 - Merge Sort\n"
         << "7 - Quick Sort\n";
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

    switch (escolhaAlg) {
        case 1: medirTempo(bubbleSort, nomes, "Bubble Sort"); break;
        case 2: medirTempo(insertionSort, nomes, "Insertion Sort"); break;
        case 3: medirTempo(selectionSort, nomes, "Selection Sort"); break;
        case 4: medirTempo(shellSort, nomes, "Shell Sort"); break;
        case 5: medirTempo(heapSort, nomes, "Heap Sort"); break;
        case 6: medirTempo(mergeSortWrapper, nomes, "Merge Sort"); break;
        case 7: medirTempo(quickSortWrapper, nomes, "Quick Sort"); break;
        default:
            cout << "Escolha invalida!" << endl;
            return 1;
    }

    ofstream saida("nomes_ordenados.txt");
    for (const auto &nome : nomes) {
        saida << nome << "\n";
    }
    saida.close();
    cout << "Ordenacao concluida! Resultado salvo em nomes_ordenados.txt" << endl;

    return 0;
}
