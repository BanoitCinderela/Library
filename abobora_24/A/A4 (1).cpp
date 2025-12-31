#include <bits/stdc++.h>
using namespace std;

int np[4] = {6, 28, 496, 8128};

int solver(int x){
    int ans = 0;
    for(int i = 0; i < 4; i++){
        if(x == np[i]){
            ans = 1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, v;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v;
        if(solver(v))
            cout << "SIM\n";
        else
            cout << "NAO\n";
    }

    return 0;
}