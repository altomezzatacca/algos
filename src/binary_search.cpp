#include "bits/stdc++.h"
using namespace std;
vector<int> v;

// cerca il lower bound in un array ordinato

int binary_search(int l, int r, int x){
    while(r - l > 1){
        int m = (l + r) >> 1;
        v[m] <= x ? l = m : r = m;
    }
    return l;
}

int main(){
    int n; cin >> n;
    v.resize(n);
    for(auto &u: v) cin >> u;
    int x; cin >> x;
    int ix = binary_search(0, n, x);
    cout << ix << "\n";
}
