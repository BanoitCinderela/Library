#include <bits/stdc++.h>
using namespace std;

int leitura(){
    int num;
    cin >> num;
    return num;
}

void zerar(int n, vector<int> &vet){
    for(int i = 0; i < n; i++){
        vet[i] = 0;
    }
}

void ler_vetor(int m, vector<int> &vet){
    for(int i = 0; i < m; i++){
        int x = leitura();
        vet[x - 1]++;
    }
}

int total(int n, vector<int> &vet){
    int c = 0;
    for(int i = 0; i < n; i++){
        if(vet[i] == 0){
            c++;
        }
    }
    return c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = leitura();
    int m = leitura();

    vector<int> vet(n);
    zerar(n, vet);
    ler_vetor(m, vet);

    cout << total(n, vet) << "\n";

    return 0;
}