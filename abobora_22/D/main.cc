#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int lis(vi &a, int n){
    vi d(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                d[i] = max(d[i], d[j]+1);
            }
        }
    }
    int ans;
    for(int i = 0; i < n; i++){
        ans = max(ans, d[i]);
    }
    return ans;
}

int main(){
    int n, ans, t;
    cin >> t;
    while(t--){
        cin >> n;
        vi a(n, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ans = lis(a, n);
        cout << ans << endl;
    }
    return 0;
}