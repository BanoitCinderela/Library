#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long p;
    cin >> p;

    long long n = p * (p - 1) / 2;
    long long lim = sqrt((long double)n);

    for(long long i = 1; i <= lim; i++){
        if(n % i == 0){
            long long a = i;
            long long b = n / i;
            cout << "(" << a + p << "," << b + p << "," << a + b + p << ")\n";
        }
    }

    return 0;
}