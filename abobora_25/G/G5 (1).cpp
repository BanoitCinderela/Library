#include <bits/stdc++.h>
using namespace std;

void evoluir(string &ret, int qtd){
    int tam_ret = ret.size();
    string aux(tam_ret, '0');

    char regra[2][2][2] = {
        { { '1', '0' }, { '0', '1' } },
        { { '0', '0' }, { '0', '1' } }
    };

    for(int total = 0; total < qtd; total++){
        aux[0] = regra[ret[tam_ret - 1] - '0'][ret[0] - '0'][ret[1] - '0'];

        for(int i = 1; i < tam_ret - 1; i++){
            aux[i] = regra[ret[i - 1] - '0'][ret[i] - '0'][ret[i + 1] - '0'];
        }

        aux[tam_ret - 1] = regra[ret[tam_ret - 2] - '0'][ret[tam_ret - 1] - '0'][ret[0] - '0'];

        ret = aux;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_evolucao;
    string reticulado;

    while(cin >> qtd_evolucao){
        cin >> reticulado;
        evoluir(reticulado, qtd_evolucao);
        cout << reticulado << "\n";
    }

    return 0;
}