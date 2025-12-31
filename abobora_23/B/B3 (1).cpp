#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string, pair<double, double>> A, pair<string, pair<double, double>> B){
    if(A.second.second == B.second.second)
        return A.second.first > B.second.first;
    return A.second.second < B.second.second;
}

int main(){
    vector<pair<string, pair<double, double>>> estrelas;
    string estrela;
    double dist, mag;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> estrela >> dist >> mag;
        estrelas.push_back({estrela, {dist, mag}});
    }
    sort(estrelas.begin(), estrelas.end(), compare);
    for(auto x : estrelas){
        cout << x.first << endl;
    }
    return 0;
}