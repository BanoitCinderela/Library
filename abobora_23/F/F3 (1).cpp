#include <bits/stdc++.h>
using namespace std;

double dist_l2(const pair<double,double> &v1, const pair<double,double> &v2){
    double dx = v1.first - v2.first;
    double dy = v1.second - v2.second;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h_max;
    cin >> h_max;

    int n_vertices;
    cin >> n_vertices;

    vector<pair<double,double>> V(n_vertices);
    for(int i = 0; i < n_vertices; i++){
        cin >> V[i].first >> V[i].second;
    }

    double total = 0.0;
    for(int i = 1; i < n_vertices - 1; i++){
        double ei = dist_l2(V[i], V[i + 1]);
        double ej = dist_l2(V[i + 1], V[0]);
        total += (ei + ej);
    }
    total += dist_l2(V[0], V[1]);

    long long resultado = (long long)ceil(h_max * total);
    cout << resultado << "\n";

    return 0;
}