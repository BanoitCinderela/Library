#include <iostream>
#include <vector>
using namespace std;

int M; 

bool deveVirAntes(int num1, int num2) {
    int resto1 = ((num1 % M) + M) % M;
    int resto2 = ((num2 % M) + M) % M;
    if (resto1 != resto2) {
        return resto1 < resto2;
    }

    bool eh_par1 = (num1 % 2 == 0);
    bool eh_par2 = (num2 % 2 == 0);

    if (eh_par1 && eh_par2) {
        return num1 > num2;
    }

    if (!eh_par1 && !eh_par2) {
        return num1 < num2;
    }
    
    return !eh_par1; 
}

void mesclar(vector<int>& sequencia, int inicio, int meio, int fim) {
    int tamanho_esquerda = meio - inicio + 1;
    int tamanho_direita = fim - meio;
    vector<int> esquerda(tamanho_esquerda);
    vector<int> direita(tamanho_direita);
    for (int i = 0; i < tamanho_esquerda; i++) {
        esquerda[i] = sequencia[inicio + i];
    }
    for (int i = 0; i < tamanho_direita; i++) {
        direita[i] = sequencia[meio + 1 + i];
    }

    int i = 0, j = 0, k = inicio;
    while (i < tamanho_esquerda && j < tamanho_direita) {
        if (deveVirAntes(esquerda[i], direita[j])) {
            sequencia[k] = esquerda[i];
            i++;
        } else {
            sequencia[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanho_esquerda) {
        sequencia[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanho_direita) {
        sequencia[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& sequencia, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(sequencia, inicio, meio);
        mergeSort(sequencia, meio + 1, fim);
        mesclar(sequencia, inicio, meio, fim);
    }
}

int main() {
    int N;
    
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
 
        vector<int> sequencia(N);
        for (int i = 0; i < N; i++) {
            cin >> sequencia[i];
        }
  
        mergeSort(sequencia, 0, N - 1);

        cout << N << " " << M << endl;
        for (int i = 0; i < N; i++) {
            cout << sequencia[i] << endl;
        }
    }
    cout << "0 0" << endl;
    
    return 0;
}