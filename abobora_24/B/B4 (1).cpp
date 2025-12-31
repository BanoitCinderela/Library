#include <bits/stdc++.h>

using namespace std;
vector<int> cor;
vector<int> pi;

void leituraGrafo(vector<vector<double>> &G, int m)
{
    int a, b;
    double c;
    while (m--)
    {
        cin >> a >> b >> c;
        G[a - 1][b - 1] = c;
        G[b - 1][a - 1] = c;
    }
}

int vizinhos(vector<vector<double>> &G)
{

    int n = G.size();
    for (int u = 0; u < n; u++)
    {
        int c = 0;
        for (int v = 0; v < n; v++)
        {
            if (G[u][v] > 0)
            {
                c++;
            }
        }
        if (c % 2 == 1)
        {
            return 0;
        }
    }
    return 1;
}

void dfsvisit(int u, vector<vector<double>> &G)
{
    cor[u] = 1;
    for (auto v : G[u])
    {
        if (cor[v] == 0)
        {
            pi[v] = u;
            dfsvisit(v, G);
        }
    }
    cor[u] = 2;
}
int dfs(vector<vector<double>> &G)
{
    int n = G.size();
    cor.assign(n, 0);
    pi.assign(n, -1);
    int u, c = 0;
    for (u = 0; u < n; u++)
    {
        if (cor[u] == 0)
        {
            c++;
            dfsvisit(u, G);
        }
    }
    if (c == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<double>> Grafo;
    Grafo.assign(n, vector<double>(n, 0));
    leituraGrafo(Grafo, m);
    int ok = 0;
    if (dfs(Grafo))
    {
        ok++;
    }
    if (vizinhos(Grafo))
    {
        ok++;
    }
    if (ok == 2)
    {
        cout << "S" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
    return 0;
}