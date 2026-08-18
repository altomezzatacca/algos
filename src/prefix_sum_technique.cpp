#include "bits/stdc++.h"
using namespace std;

// somma prefissa

vector<int> prefix(int n, vector<int> v){
    vector<int> ans(n);
    ans[0] = v[0];
    for(int i = 1; i < n; i++)
        ans[i] = ans[i - 1] + v[i];
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &u: v) cin >> u;
    vector<int> ans = prefix(n, v);
    for(auto u: ans) cout << u << " ";
    cout << "\n";
}
