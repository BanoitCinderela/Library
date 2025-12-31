#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> pop(N);
    for(int i = 0; i < N; i++){
        cin >> pop[i];
    }

    int has_alerta = 0;
    int crescimento = 0;

    for(int i = 0; i < N; i++){
        if(pop[i] > 200){
            has_alerta = 1;
            cout << "[Pico] " << i + 1 << ": " << pop[i] << " insetos\n";
        }

        if(i >= 6){
            int minId = i - 6;
            int maxId = i - 6;
            for(int j = i - 6; j <= i; j++){
                if(pop[j] > pop[maxId]){
                    maxId = j;
                }else if(pop[j] < pop[minId]){
                    minId = j;
                }
            }

            double diff = (double)(pop[maxId] - pop[minId]) / pop[minId];
            if(diff >= 0.2 && minId < maxId){
                has_alerta = 1;
                cout << "[7 Dias] " << i - 5 << "-" << i + 1 << ": ";
                cout << fixed << setprecision(2) << diff * 100 << "%\n";
            }
        }

        if(i > 0){
            double diff = (double)(pop[i] - pop[i - 1]) / pop[i - 1];
            if(diff >= 0.05 && pop[i] > pop[i - 1]){
                crescimento++;
            }else{
                crescimento = 0;
            }
        }

        if(crescimento >= 3){
            has_alerta = 1;
            cout << "[Crescimento] " << i - crescimento + 1 << "-" << i + 1 << ": maior que >= 5%\n";
        }
    }

    if(has_alerta == 0){
        cout << "Nenhum Alerta\n";
    }

    return 0;
}