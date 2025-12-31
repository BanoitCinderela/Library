#include <bits/stdc++>
#include <vector>
using namespace std;

class NRainhas {
private:
    int n;
    vector<int> tabuleiro;
    int solucoes;
    int tentativas;
public:
    NRainhas(int tamanho) : n(tamanho), tabuleiro(tamanho, -1), solucoes(0), tentativas(0) {}
    bool ehSeguro(int linha, int coluna) {
        tentativas++;
        
        for (int i = 0; i < linha; i++) {
            // Verifica coluna
            if (tabuleiro[i] == coluna) {
                return false;
            }
            // Verifica diagonal principal
            if (tabuleiro[i] - i == coluna - linha) {
                return false;
            }
            // Verifica diagonal secundaria
            if (tabuleiro[i] + i == coluna + linha) {
                return false;
            }
        }
        return true;
    }

    void resolverNRainhas(int linha) {
        if (linha == n) {
            solucoes++;
            cout << "Solucao " << solucoes << ": ";
            for (int i = 0; i < n; i++) {
                cout << tabuleiro[i] << " ";
            }
            cout << endl;
            return;
        }
        for (int coluna = 0; coluna < n; coluna++) {
            if (ehSeguro(linha, coluna)) {  // PODA: verifica viabilidade
                tabuleiro[linha] = coluna;  // Fazer escolha
                resolverNRainhas(linha + 1);  // Recursao
                tabuleiro[linha] = -1;      // BACKTRACK: desfazer escolha
            }
        }
    }
    
    void resolver() {
        cout << "Resolvendo problema das " << n << " rainhas..." << endl;
        resolverNRainhas(0);
        cout << "Total de solucoes: " << solucoes << endl;
        cout << "Tentativas realizadas: " << tentativas << endl;
    }
};
int main() {
    int tamanho = 4;
    NRainhas problema(tamanho);
    problema.resolver();
    return 0;
}