#include <bits/stdc++>
#include <vector>
using namespace std;

class BuscaBinaria {
private:
    static int comparacoes;

public:
    static int buscarRecursivo(vector<int>& arr, int elemento, int inicio, int fim) {
        cout << "Buscando " << elemento << " no intervalo [" << inicio << ".." << fim << "]" << endl;
        
        if (inicio > fim) {
            cout << "Elemento nao encontrado - intervalo vazio" << endl;
            return -1;
        }
        // DIVIDIR: calcula o ponto medio
        int meio = inicio + (fim - inicio) / 2;
        comparacoes++;
        cout << "Comparando com posicao " << meio << " (valor: " << arr[meio] << ")" << endl;
        // Caso base: elemento encontrado
        if (arr[meio] == elemento) {
            cout << "Elemento encontrado na posicao " << meio << "!" << endl;
            return meio;
        }
        // CONQUISTAR: busca recursivamente na metade relevante
        if (elemento < arr[meio]) {
            cout << "Elemento menor - buscando na metade esquerda" << endl;
            return buscarRecursivo(arr, elemento, inicio, meio - 1);
        } else {
            cout << "Elemento maior - buscando na metade direita" << endl;
            return buscarRecursivo(arr, elemento, meio + 1, fim);
        }
    }
    static int buscar(vector<int>& arr, int elemento) {
        cout << "=== BUSCA BINARIA - DIVISAO E CONQUISTA ===" << endl;
        cout << "Array ordenado: ";
        for (int num : arr) cout << num << " ";
        cout << endl;
        cout << "Buscando elemento: " << elemento << endl << endl;
        comparacoes = 0;
        int resultado = buscarRecursivo(arr, elemento, 0, arr.size() - 1);
        cout << endl << "Total de comparacoes: " << comparacoes << endl;
        cout << "Complexidade teorica: O(log " << arr.size() << ") = " 
             << "O(" << (int)(log2(arr.size()) + 1) << ")" << endl;
        return resultado;
    }
};
int BuscaBinaria::comparacoes = 0;
int main() {
    vector<int> numeros = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    int elemento = 13;
    int posicao = BuscaBinaria::buscar(numeros, elemento);
    if (posicao != -1) {
        cout << "Resultado: elemento " << elemento 
             << " esta na posicao " << posicao << endl;
    } else {
        cout << "Resultado: elemento " << elemento 
             << " nao foi encontrado" << endl;
    }
    return 0;
}