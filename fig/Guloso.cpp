#include <bits/stdc++>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> problemaDoTroco(int valor, vector<int> moedas) {
    // Ordena as moedas em ordem decrescente (escolha gulosa)
    sort(moedas.begin(), moedas.end(), greater<int>());
    
    vector<int> resultado;
    cout << "Valor do troco: " << valor << endl;
    cout << "Moedas disponiveis: ";
    for (int moeda : moedas) cout << moeda << " ";
    cout << endl << endl;
    // Estrategia gulosa: sempre escolher a maior moeda possivel
    for (int moeda : moedas) {
        while (valor >= moeda) {
            resultado.push_back(moeda);
            valor -= moeda;
            cout << "Escolhendo moeda: " << moeda << 
                    " (restante: " << valor << ")" << endl;
        }
    }
    
    if (valor == 0) {
        cout << "Troco completo!" << endl;
    } else {
        cout << "Nao foi possivel completar o troco!" << endl;
    }
    return resultado;
}

int main() {
    vector<int> moedas = {1, 5, 10, 25, 50};
    int valorTroco = 67;
    
    vector<int> solucao = problemaDoTroco(valorTroco, moedas);
    
    cout << endl << "Solucao gulosa: ";
    for (int moeda : solucao) {
        cout << moeda << " ";
    }
    cout << endl << "Total de moedas: " << solucao.size() << endl;
    return 0;
}