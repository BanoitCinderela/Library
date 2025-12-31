#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long md = 1000000007LL;
    long long N, P, R;
    cin >> N >> P >> R;

    long long KC;
    if(P * R + P > N){
        KC = 0;
    }else{
        KC = N % md;
        for(long long i = 1; i < P; i++){
            KC = (KC * (N - P * R - i)) % md;
        }
    }

    cout << KC << "\n";
    return 0;
}