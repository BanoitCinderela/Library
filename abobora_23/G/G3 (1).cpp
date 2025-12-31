#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<double> &array, vector<double> &p, vector<double> &v){
    int n = array.size();
    for(int step = 1; step < n; step++){
        double key = array[step];
        double key_1 = p[step];
        double key_2 = v[step];
        int j = step - 1;

        while(j >= 0 && key < array[j]){
            array[j + 1] = array[j];
            p[j + 1] = p[j];
            v[j + 1] = v[j];
            j--;
        }

        array[j + 1] = key;
        p[j + 1] = key_1;
        v[j + 1] = key_2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int quant;
    cin >> quant;

    double capacidade;
    cin >> capacidade;

    vector<double> p(quant), v(quant), razao(quant), inc(quant, 0.0);

    for(int i = 0; i < quant; i++){
        double x, y;
        cin >> x >> y;
        p[i] = x;
        v[i] = y;
        razao[i] = y / x;
    }

    insertionSort(razao, p, v);

    double total = 0.0;
    for(int i = quant - 1; i >= 0; i--){
        if(p[i] <= capacidade){
            inc[i] = 1.0;
            capacidade -= p[i];
        }else{
            inc[i] = capacidade / p[i];
            capacidade = 0.0;
        }
        total += inc[i] * v[i];
    }

    double soma_v = 0.0;
    for(double val : v) soma_v += val;

    cout << fixed << setprecision(2) << (soma_v - total) << "\n";

    return 0;
}