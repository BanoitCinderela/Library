#include <bits/stdc++>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {3, -1, 4, 1, -5, 2, 6};
    int n = arr.size();
    
    // Construir prefix sum, max e min
    vector<int> prefix(n+1, 0), maxPref(n+1, INT_MIN), minPref(n+1, INT_MAX);
    maxPref[0] = minPref[0] = 0;
    
    for(int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + arr[i];
        maxPref[i+1] = max(maxPref[i], arr[i]);
        minPref[i+1] = min(minPref[i], arr[i]);
    }
    
    // Funcao lambda para soma de intervalo
    auto somaIntervalo = [&](int i, int j) {
        return prefix[j+1] - prefix[i];
    };
    
    // Demonstracao
    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    
    cout << "\n\nExemplos de uso:\n";
    cout << "Soma [0,2]: " << somaIntervalo(0, 2) << "\n";
    cout << "Soma [1,4]: " << somaIntervalo(1, 4) << "\n";
    cout << "Max ate pos 3: " << maxPref[4] << "\n";
    cout << "Min ate pos 3: " << minPref[4] << "\n";
    
    // Encontrar subarray de soma maxima
    int maxSoma = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            maxSoma = max(maxSoma, somaIntervalo(i, j));
    
    cout << "Subarray soma maxima: " << maxSoma << "\n";
    return 0;
}