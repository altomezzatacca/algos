#include "bits/stdc++.h"
using namespace std;

// calcolare rapidamente il numero di componenti connesse

struct dsu {

    int n, cc;
    vector<int> parent, sz;

    dsu(int nn) {
        n = nn;
        cc = n;
        parent.resize(n);
        sz.resize(n);
        iota(begin(parent), end(parent), 0);
        fill(begin(sz), end(sz), 1);
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        parent[b] = a;
        cc--;
    }

};

int main() {
    int n; cin >> n;
    dsu d = dsu(n);
}
