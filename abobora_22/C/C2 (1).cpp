#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double q, c, l, p;
    if(!(cin >> q >> c >> l >> p)) return 0;

    double tc = ceil(c / q);
    double tl = ceil(l / q);
    double tp = ceil(p / q);

    double T = tc * tl + 2 * tc * tp + 2 * tl * tp;
    double D = T - (c * l + 2 * c * p + 2 * l * p) / (q * q);

    cout << fixed << setprecision(0) << T << " ";
    cout << fixed << setprecision(2) << D << "\n";

    return 0;
}