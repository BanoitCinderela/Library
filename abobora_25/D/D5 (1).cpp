#include <bits/stdc++.h>

using namespace std;

int solver(int *frqs, int *frqsl){
    for(int i = 0; i < 26; i++){
        if(frqsl[i] > frqs[i])
            return 0;
    }
    return 1;
}

int main(){
    string s, sl;
    int t;
    int frqs[26] = {};
    cin >> t >> s;
    for (auto x : s)
        frqs[(int)x-97]++;
    while(t--){
        int frqsl[26] = {};
        cin >> sl;
        for (auto x : sl)
            frqsl[(int)x-97]++;
        if(solver(frqs, frqsl)){
            cout << "SIM\n";
        }else{
            cout << "NAO\n";
        }
    }
    return 0;
}