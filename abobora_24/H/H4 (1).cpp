#include <bits/stdc++.h>
using namespace std;

struct No{
    string nome;
    No *prox;
};

struct Desc{
    int qtd;
    No *ini, *fim;
};

void inserir(Desc *d, const string &nome){
    No *novo = new No;
    novo->nome = nome;
    novo->prox = nullptr;

    if(d->ini == nullptr){
        d->ini = novo;
        d->fim = novo;
        novo->prox = novo;
    }else{
        novo->prox = d->ini;
        d->fim->prox = novo;
        d->fim = novo;
    }
    d->qtd++;
}

void mostrar(Desc *d){
    if(d->ini != nullptr){
        No *p;
        for(p = d->ini; p->prox != d->ini; p = p->prox){
            cout << p->nome << " ";
        }
        cout << p->nome;
    }
}

int remover_ultimo(Desc *d){
    if(d->ini == nullptr) return 0;

    if(d->ini == d->fim){
        delete d->fim;
        d->ini = nullptr;
        d->fim = nullptr;
    }else{
        No *p;
        for(p = d->ini; p->prox != d->fim; p = p->prox);
        p->prox = d->ini;
        delete d->fim;
        d->fim = p;
    }
    d->qtd--;
    return 1;
}

void processar_listas(Desc *d, Desc *r, int x){
    if(d->ini != nullptr){
        No *p = d->ini, *q = nullptr;

        d->ini = nullptr;
        d->fim = nullptr;

        while(p->prox != p){
            for(int i = 0; i < x % d->qtd; i++, p = p->prox){
                q = p;
            }

            q->prox = p->prox;

            if(r->ini == nullptr){
                r->ini = p;
                r->fim = p;
                p->prox = p;
            }else{
                r->fim->prox = p;
                r->fim = p;
                p->prox = r->ini;
            }

            r->qtd++;
            d->qtd--;
            p = q->prox;
        }

        r->fim->prox = p;
        r->fim = p;
        p->prox = r->ini;

        r->qtd++;
        d->qtd--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Desc d, r;
    d.ini = nullptr;
    d.fim = nullptr;
    d.qtd = 0;
    r.ini = nullptr;
    r.fim = nullptr;
    r.qtd = 0;

    string nome;
    while(cin >> nome){
        inserir(&d, nome);
    }

    int x = atoi(d.fim->nome.c_str());
    remover_ultimo(&d);

    processar_listas(&d, &r, x);
    mostrar(&r);

    while(remover_ultimo(&r));

    return 0;
}