#include <bits/stdc++.h>
using namespace std;

struct No{
    int dado;
    No *p1, *p2, *p3, *p4;
};

No* criar_no(int dado){
    No* novo = new No;
    novo->dado = dado;
    novo->p1 = nullptr;
    novo->p2 = nullptr;
    novo->p3 = nullptr;
    novo->p4 = nullptr;
    return novo;
}

int extrair_dois_ultimos_digitos(int vlr){
    return vlr % 100;
}

void inserir(No* &r, int dado){
    if(r == nullptr){
        r = criar_no(dado);
        return;
    }

    int vlr = extrair_dois_ultimos_digitos(r->dado * dado);

    if(vlr < 25){
        inserir(r->p1, dado);
        return;
    }
    if(vlr < 50){
        inserir(r->p2, dado);
        return;
    }
    if(vlr < 75){
        inserir(r->p3, dado);
        return;
    }
    inserir(r->p4, dado);
}

void mostrar_nivel(No* r, int nivel){
    if(r == nullptr) return;

    if(nivel == 0){
        cout << r->dado << " ";
    }else{
        mostrar_nivel(r->p1, nivel - 1);
        mostrar_nivel(r->p2, nivel - 1);
        mostrar_nivel(r->p3, nivel - 1);
        mostrar_nivel(r->p4, nivel - 1);
    }
}

void destruir_arvore(No* &r){
    if(r != nullptr){
        destruir_arvore(r->p1);
        destruir_arvore(r->p2);
        destruir_arvore(r->p3);
        destruir_arvore(r->p4);
        delete r;
        r = nullptr;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    No* r = nullptr;
    int dado, qtd, nivel;

    if(!(cin >> nivel)) return 0;

    while(true){
        if(!(cin >> qtd)) break;

        for(int i = 0; i < qtd; i++){
            cin >> dado;
            inserir(r, dado);
        }

        mostrar_nivel(r, nivel);
        cout << "#";

        destruir_arvore(r);

        if(!(cin >> nivel)) break;
    }

    return 0;
}