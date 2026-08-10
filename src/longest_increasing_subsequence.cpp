#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

// lunghezza della più lunga sottosequenza crescente

int lis(int n, vector<int> v){
    vector<int> a;
    a.emplace_back(v[0]);
    for(int i = 1; i < n; i++){
        if(v[i] > a.back())
            a.emplace_back(v[i]);
        else {
            int ix = lower_bound(begin(a), end(a), v[i]) - begin(a);
            a[ix] = v[i];
        }
    }
    return a.size();
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &u: v) cin >> u;
    int ans = lis(n, v);
    cout << ans << "\n";
}
