#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> p;
    p.push_back({0, 0});
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    int m = p.size();
    vector<vector<long long>> d(m, vector<long long>(m));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            d[i][j] = llabs(p[i].first - p[j].first) + llabs(p[i].second - p[j].second);
        }
    }

    int maxmask = 1 << m;
    const long long INF = LLONG_MAX / 4;
    vector<vector<long long>> dp(maxmask, vector<long long>(m, INF));

    dp[1][0] = 0;

    for(int mask = 0; mask < maxmask; mask++){
        for(int u = 0; u < m; u++){
            if(dp[mask][u] == INF) continue;
            for(int v = 0; v < m; v++){
                if(mask & (1 << v)) continue;
                int new_mask = mask | (1 << v);
                dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + d[u][v]);
            }
        }
    }

    int full = maxmask - 1;
    long long ans = INF;
    for(int i = 1; i < m; i++){
        if(dp[full][i] != INF){
            ans = min(ans, dp[full][i] + d[i][0]);
        }
    }

    cout << ans << "\n";
    return 0;
}