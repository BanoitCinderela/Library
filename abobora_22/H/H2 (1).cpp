#include <bits/stdc++.h>
using namespace std;

char conv_Letra(int p){
    if(p == 0) return 'N';
    if(p == 1) return 'L';
    if(p == 2) return 'S';
    if(p == 3) return 'O';
    exit(0);
}

int conv_Num(char dir_ini){
    if(dir_ini == 'N') return 0;
    if(dir_ini == 'L') return 1;
    if(dir_ini == 'S') return 2;
    if(dir_ini == 'O') return 3;
    exit(0);
}

char calc_dir(const string &c, int qtd_com, char dir_ini){
    int qtd_D = 0, qtd_E = 0;

    for(int i = 0; i < qtd_com; i++){
        if(c[i] == 'D') qtd_D++;
        if(c[i] == 'E') qtd_E++;
    }

    int vlr = qtd_D - qtd_E;
    int vlr_ini = conv_Num(dir_ini);
    int tmp = (vlr_ini + vlr) % 4;

    if(tmp >= 0) return conv_Letra(tmp);
    return conv_Letra(4 + tmp);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_com;
    char dir_ini;

    while(true){
        if(!(cin >> qtd_com)) break;
        if(qtd_com <= 0) break;

        cin >> dir_ini;

        string c;
        c.reserve(qtd_com);
        for(int i = 0; i < qtd_com; i++){
            char x;
            cin >> x;
            c.push_back(x);
        }

        cout << calc_dir(c, qtd_com, dir_ini) << "\n";
    }

    return 0;
}