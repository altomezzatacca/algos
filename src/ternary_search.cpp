#include "bits/stdc++.h"
using namespace std;
vector<int> v;

// cerca il minimo/massimo in un array unimodale

int ternary_search_min(int l, int r){
    while(r - l > 1){
        if(r - l < 3){
            int min_ix = l;
            for(int i = l; i < r; i++)
                if(v[i] < v[min_ix])
                    min_ix = i;
            return min_ix;
        }
        int delta = (r - l) / 3;
        int m1 = l + delta, m2 = r - delta;
        v[m1] > v[m2] ? l = m1 : r = m2;
    }
    return l;
}

int ternary_search_max(int l, int r){
    while(r - l > 1){
        if(r - l < 3){
            int max_ix = l;
            for(int i = l; i < r; i++)
                if(v[i] > v[max_ix])
                    max_ix = i;
            return max_ix;
        }
        int delta = (r - l) / 3;
        int m1 = l + delta, m2 = r - delta;
        v[m1] > v[m2] ? r = m2 : l = m1;
    }
    return l;
}

int main(){
    int n; cin >> n;
    v.resize(n);
    for(auto &u: v) cin >> u;
    int ix = ternary_search_max(0, n);
    cout << ix;
}
