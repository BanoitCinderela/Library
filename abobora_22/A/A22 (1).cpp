#include <bits/stdc++.h>
using namespace std;

int ler() {
    int num;
    cin >> num;
    return num;
}

void vetor(int n, vector<int> &vet) {
    for (int i = 0; i < n; i++) {
        vet[i] = ler();
    }
}

void escrever(int n, const vector<int> &vet) {
    for (int i = 0; i < n; i++) {
        cout << vet[i] << " ";
    }
    cout << "\n";
}

void troca(int &x, int &y) {
    int aux = x;
    x = y;
    y = aux;
}

void ordena(int n, vector<int> &vet) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i; j < n; j++) {
            if (vet[j] < vet[menor]) {
                menor = j;
            }
        }
        troca(vet[menor], vet[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = ler();
    vector<int> vet(n);

    vetor(n, vet);
    ordena(n, vet);
    escrever(n, vet);

    return 0;
}