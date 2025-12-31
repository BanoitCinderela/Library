#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    unsigned long long fib[61];
    
    fib[0] = 0;
    
    fib[1] = 1;
    
    for(int i = 2; i <= 60; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << "Fib(" << N << ") = " << fib[N] << endl;
    }
    
    return 0;
}