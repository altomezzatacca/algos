#include "bits/stdc++.h"
using namespace std;

// somma massima di un sottoarray (sottosequenza contigua)

int mss(int n, vector<int> v){
    int best = 0, cur = 0;
    for(int i = 0; i < n; i++){
        cur = max(v[i], cur + v[i]);
        best = max(best, cur);
    }
    return best;
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &u: v) cin >> u;
    int ans = mss(n, v);
    cout << ans << "\n";
}
