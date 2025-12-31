#include <iostream>
#include <vector>
using namespace std
int main() {
    int n, min_pos = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int min_value = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min_value) {
            min_value = arr[i];
            min_pos = i;
        }
    }
    cout << "Menor valor: " << min_value << "\nPosicao: " << min_pos << endl;
    return 0;
}