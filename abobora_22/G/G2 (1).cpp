#include <bits/stdc++.h>
using namespace std;

long long comb(long long n, long long p){
    p = min(p, n - p);
    if(p < 0) return 0;
    if(p == 0) return 1;
    long long res = n;
    for(long long i = 1; i < p; i++){
        res = res * (n - i) / (i + 1);
    }
    return res;
}

long long comb_mod(long long n, long long p, long long m){
    p = min(p, n - p);
    if(p < 0) return 0;
    if(p == 0) return 1;
    long long res = n % m;
    for(long long i = 1; i < p; i++){
        res = (res * (n - i) / (i + 1)) % m;
    }
    return res;
}

long long kaplansky(long long n, long long p, long long r){
    return comb(n - (p - 1) * r, p);
}

long long kaplansky_mod(long long n, long long p, long long r, long long m){
    return comb_mod(n - (p - 1) * r, p, m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, p, r;
    cin >> n >> p >> r;

    cout << kaplansky_mod(n, p, r - 1, 100000007LL) << "\n";

    return 0;
}