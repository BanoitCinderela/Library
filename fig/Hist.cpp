#include <bits/stdc++>
#include <vector>
using namespace std;

int main() {
    // Vendas do dia (IDs dos produtos)
    vector<int> vendas = {1,3,2,1,4,1,5,3,2,1,3,4,1,2,3};
    vector<int> hist(6, 0);  // produtos 1-5
    // Contabilizar vendas
    for(int id : vendas)
        hist[id]++;
    // Relatorio visual
    cout << "=== VENDAS DO DIA ===\n";
    for(int i = 1; i <= 5; i++) {
        cout << "Produto " << i << ": ";
        for(int j = 0; j < hist[i]; j++) cout << "*";
        cout << " (" << hist[i] << ")\n";
    }
    // Produto campeao
    int maisVendido = 1;
    for(int i = 2; i <= 5; i++)
        if(hist[i] > hist[maisVendido])
            maisVendido = i;
    
    cout << "\n*** Mais vendido: Produto " << maisVendido;
    return 0;
}