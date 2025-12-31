#include <bits/stdc++.h>


int main() {

    int N;
    std::cin >> N;
    int X[1000];
    int menor;
    int posicao;

    for(int i = 0; i < N; i++) {

        std::cin >> X[i];
    }

    menor = X[0];
    posicao = 0;

    for(int i = 1; i < N; i++) {

        if(X[i] < menor) {
            menor = X[i];
            posicao = i;
        }
    }
    std::cout << "Menor valor: " << menor << std::endl;
    std::cout << "Posicao: " << posicao << std::endl;
    return 0;
}