#include <bits/stdc++>
#include <vector>
using namespace std;

int buscaLinear(vector<int> arr, int elemento) {
    cout << "Procurando " << elemento << " no array..." << endl; 
    for (int i = 0; i < arr.size(); i++) {
        cout << "Posicao " << i << ": " << arr[i] << endl;
        
        if (arr[i] == elemento) {
            cout << "Elemento encontrado!" << endl;
            return i;
        }
    }
    cout << "Elemento nao encontrado." << endl;
    return -1;
}
int main() {
    vector<int> numeros = {10, 25, 3, 47, 15, 8, 33};

    cout << "Array: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    
    int elementoBusca = 47;
    int posicao = buscaLinear(numeros, elementoBusca);
    
    if (posicao != -1) {
        cout << "Elemento " << elementoBusca << " esta na posicao " << posicao << endl;
    } else {
        cout << "Elemento " << elementoBusca << " nao foi encontrado" << endl;
    }
    return 0;
}