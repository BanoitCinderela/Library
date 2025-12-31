#include <bits/stdc++>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Fibonacci {
public:
    // Versao recursiva ingenua - O(2^n)
    static long long fibRecursivo(int n) {
        if (n <= 1) return n;
        return fibRecursivo(n - 1) + fibRecursivo(n - 2);
    }
    // Top-down com memoizacao - O(n)
    static long long fibMemoizado(int n, unordered_map<int, long long>& memo) {
        if (n <= 1) return n;
        
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        memo[n] = fibMemoizado(n - 1, memo) + fibMemoizado(n - 2, memo);
        return memo[n];
    }
    // Bottom-up com tabulacao - O(n)
    static long long fibTabulacao(int n) {
        if (n <= 1) return n;
        
        vector<long long> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        
        cout << "Construindo tabela DP:" << endl;
        cout << "dp[0] = " << dp[0] << endl;
        cout << "dp[1] = " << dp[1] << endl;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << "dp[" << i << "] = dp[" << (i-1) << "] + dp[" << (i-2) 
                 << "] = " << dp[i] << endl;
        }
        return dp[n];
    }
    // Otimizacao de espaco - O(1) espaco
    static long long fibOtimizado(int n) {
        if (n <= 1) return n;
        
        long long anterior = 0;
        long long atual = 1;
        
        cout << "Calculando com espaco otimizado:" << endl;