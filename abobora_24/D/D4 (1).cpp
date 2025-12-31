#include <bits/stdc++.h>
using namespace std;

#define NMAX 10001
#define MMAX 10001

int abobora[NMAX];
int dp[NMAX][MMAX];

int solver(int n, int sum){
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < abobora[i - 1]) {
                dp[i][j] = dp[i - 1][j]; 
            }else{
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - abobora[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int p, n;
    int x;
    cin >> n >> p;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        abobora[i] = x;
    }
    if (solver(n, p))
        printf("SIM\n");
    else
        printf("NAO\n");
    return 0;
}