#include <bits/stdc++.h>
using namespace std;

double encontronafinal(long long n){
    long long k = 0;
    while((1LL << (k + 1)) <= n) k++;

    long long extra = n - (1LL << k);
    long long a;

    if(extra <= (1LL << (k - 1))){
        a = 2LL * ((1LL << (k - 1)) + extra) * (1LL << (k - 1));
    }else{
        extra -= (1LL << (k - 1));
        a = 2LL * (1LL << k) * ((1LL << (k - 1)) + extra);
    }

    long long b = n * (n - 1);
    return 100.0 * (double)a / (double)b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    double sol = encontronafinal(n);
    cout << fixed << setprecision(3) << sol << "\n";

    return 0;
}