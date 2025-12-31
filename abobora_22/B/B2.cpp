#include <bits/stdc++.h>
using namespace std;

void mostrar_mat(vector<vector<char>> &m, int qtd_lin, int qtd_col){
    for(int i = 0; i < qtd_lin; i++){
        for(int j = 0; j < qtd_col; j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

void saida_mat(vector<vector<char>> &m, int qtd_lin, int qtd_col){
    for(int i = 0; i < qtd_lin; i++){
        for(int j = 0; j < qtd_col; j++){
            cout << m[i][j];
        }
    }
}

char aplicar_regra(vector<vector<char>> &m, int a, int b, int dim_i, int dim_j){
    int qtd_vivo = 0;
    for(int i = a - 1; i <= a + 1; i++){
        for(int j = b - 1; j <= b + 1; j++){
            if(i < 0 || j < 0) continue;
            if(i >= dim_i || j >= dim_j) continue;
            if(i == a && j == b) continue;
            if(m[i][j] == '1') qtd_vivo++;
        }
    }

    if(m[a][b] == '1'){
        if(qtd_vivo < 2) return '0';
        if(qtd_vivo > 3) return '0';
        return '1';
    } else {
        if(qtd_vivo == 3) return '1';
    }
    return '0';
}

void evol(vector<vector<char>> &m, int qtd_lin, int qtd_col, int dim_i, int dim_j){
    vector<vector<char>> aux(qtd_lin, vector<char>(qtd_col));
    for(int i = 0; i < qtd_lin; i++){
        for(int j = 0; j < qtd_col; j++){
            aux[i][j] = aplicar_regra(m, i, j, dim_i, dim_j);
        }
    }
    m = aux;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_ger, qtd_lin, qtd_col;

    while(true){
        if(!(cin >> qtd_ger)) break;
        if(qtd_ger <= 0) break;

        cin >> qtd_lin >> qtd_col;

        vector<vector<char>> m(qtd_lin, vector<char>(qtd_col));

        for(int i = 0; i < qtd_lin; i++){
            for(int j = 0; j < qtd_col; j++){
                cin >> m[i][j];
            }
        }

        for(int i = 0; i < qtd_ger; i++){
            evol(m, qtd_lin, qtd_col, qtd_lin, qtd_col);
        }

        saida_mat(m, qtd_lin, qtd_col);
        cout << "\n";
    }

    return 0;
}