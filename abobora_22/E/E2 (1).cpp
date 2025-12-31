#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n_nodes, n_threads;
    cin >> n_nodes >> n_threads;

    vector<int> result(n_nodes, 0);
    int pc = 0;

    while(n_threads-- > 0){
        result[pc]++;
        pc = (pc + 1) % n_nodes;
    }

    for(int i = 0; i < n_nodes - 1; i++){
        cout << result[i] << " ";
    }
    cout << result[n_nodes - 1] << "\n";

    return 0;
}