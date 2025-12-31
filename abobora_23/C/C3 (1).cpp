#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    unordered_map<char, int> abobora_cnt;
    abobora_cnt['a'] = 2;
    abobora_cnt['b'] = 2;
    abobora_cnt['o'] = 2;
    abobora_cnt['r'] = 1;

    int remove_cost = 3;
    int substitution_cost = 5;

    long long cost = 0;

    for(auto &p : abobora_cnt){
        char x = p.first;
        int need = p.second;
        int cnt = 0;
        for(char y : s){
            if(y == x) cnt++;
        }
        if(cnt < need){
            cost += (long long)substitution_cost * (need - cnt);
        }
    }

    cost += (long long)remove_cost * ((int)s.size() - 7);

    cout << cost << "\n";

    return 0;
}