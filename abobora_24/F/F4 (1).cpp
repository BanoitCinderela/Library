#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float total_teia, comprimento;
    const float pi = 3.14f;

    while(cin >> total_teia >> comprimento){
        float area = (comprimento * comprimento) / (4.0f * pi);
        if(total_teia <= area)
            cout << "NAO\n";
        else
            cout << "SIM\n";
    }

    return 0;
}
