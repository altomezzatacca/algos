#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> adj;
vector<int> in, out, parent;

// preprocessing utile per query su un albero
// si "appiattisce" su un array di dimensione n
// ogni sottoalbero di un nodo corrisponde a [in[i], out[i]]

struct segtree {
    struct node {
        int l, r;
        int x;
    };
    int sz = 1;
    vector<node> v;
    segtree (int n, vector<int> a) {
        while (sz < n) sz <<= 1;
        v.resize(2 * sz);
        for (int i = 0; i < n; i++) {
            v[i + sz].x = a[i];
            v[i + sz].l = i;
            v[i + sz].r = i + 1;
        }
        for (int i = n; i < sz; i++) {
            v[i + sz].x = 0;
            v[i + sz].l = i;
            v[i + sz].r = i + 1;
        }
        for (int i = sz - 1; i > 0; i--) {
            v[i].x = v[2 * i].x + v[2 * i + 1].x;
            v[i].l = v[2 * i].l;
            v[i].r = v[2 * i + 1].r;
        }
    }
};

void euler_tour (int node, int &t) {
    in[node] = t;
    for (auto u: adj[node]) {
        if (u != parent[node]) {
            t++;
            parent[u] = node;
            euler_tour(u, t);
        }
    }
    out[node] = t;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &u: v) cin >> u;

    adj.resize(n), parent.resize(n);
    in.resize(n), out.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    int t = 0;
    euler_tour(0, t);

    vector<int> diff(n + 1); // d[i] = v[i] - v[i - 1]
    for (int i = 0; i < n; i++) {
        diff[in[i]] += v[i];
        diff[out[i] + 1] -= v[i];
    }

    segtree seg = segtree(n + 1, diff); // segtree per update e query più rapidi
}
