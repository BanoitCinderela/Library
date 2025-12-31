#include <bits/stdc++.h>

using namespace std;

#define TAM 2001
int campo[TAM][TAM];
unsigned long dp[TAM][TAM];

void solver(int n, int m){
    dp[0][0] = campo[0][0];
    for(int i = 1; i < n; i++)
        dp[i][0] = dp[i-1][0]+campo[i][0];
    for(int j = 1; j < m; j++)
        dp[0][j] = dp[0][j-1]+campo[0][j];
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            dp[i][j] = max(dp[i-1][j]+campo[i][j], dp[i][j-1]+campo[i][j]);
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> campo[i][j];
        }
    }
    solver(n, m);
    cout << dp[n-1][m-1] << "\n";
    return 0;
}