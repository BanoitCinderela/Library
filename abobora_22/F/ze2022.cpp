#include <bits/stdc++.h>

using namespace std;

void leituraGrafo(vector<vector<int>> &G, int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        int u = a - 1;
        int v = b - 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void apaga_aresta(vector<vector<int>> &G, int u, int v)
{
    G[u].erase(find(G[u].begin(), G[u].end(), v));
    G[v].erase(find(G[v].begin(), G[v].end(), u));
}

void MostrarArestas(vector<vector<int>> &G, int n)
{
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (auto v : G[u])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

void dfs(vector<vector<int>> &G, int u, vector<bool> &visited, vector<int> &pi)
{
    if (visited[u])
    {
        return;
    }
    visited[u] = true;
    for (auto v : G[u])
    {
        if (!(visited[v]))
        {
            pi[v] = u;
            dfs(G, v, visited, pi);
        }
    }
}

bool dfs_principal(vector<vector<int>> &G, int n)
{
    vector<bool> visited;
    vector<int> pi;
    visited.assign(n, false);
    pi.assign(n, -2);
    int bairros = 0;
    for (int u = 0; u < n; u++)
    {
        if (!(visited[u]))
        {
            bairros++;
            if (bairros > 1)
            {
                return true;
            }
            pi[u] = -1;
            dfs(G, u, visited, pi);
        }
    }
    return false;
}

bool pontes(vector<vector<int>> &G, int n)
{
    int u, v;
    vector<vector<int>> Grafo;
    Grafo = G;
    for (int u = 0; u < n; u++)
    {
        for (auto v : Grafo[u])
        {
            apaga_aresta(Grafo, u, v);
            if (dfs_principal(Grafo, n))
            {
                return true;
            }
            Grafo = G;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> Grafo;
    int n, m;
    cin >> n >> m;
    Grafo.assign(n, vector<int>());
    leituraGrafo(Grafo, m);
    if (pontes(Grafo, n))
    {
        cout << "S" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
    return 0;
}