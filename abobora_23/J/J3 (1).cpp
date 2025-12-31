#include <bits/stdc++.h>

using namespace std;

void leituraGrafo(vector<vector<int>> &G, int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        int u = a - 1, v = b - 1;

        G[u].push_back(v);
        G[v].push_back(u);
    }
}

bool dfs(vector<vector<int>> &G, int s, vector<int> &cor, int c)
{
    cor[s] = c;
    for (auto u : G[s])
    {
        if (cor[u] == -1)
        {
            if (dfs(G, u, cor, 1 - c) == false)
            {
                return false;
            }
        }
        else
        {
            if (cor[u] == c)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Grafo;
    Grafo.assign(n, vector<int>());
    leituraGrafo(Grafo, m);
    vector<bool> visited;
    visited.assign(n, false);
    vector<int> cor;
    cor.assign(n, -1);
    int u = 0;
    if (dfs(Grafo, u, cor, 0))
    {
        cout << "Sim";
    }
    else
    {
        cout << "Nao";
    }
    cout << endl;
    return 0;
}