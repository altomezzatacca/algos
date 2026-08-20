#include "bits/stdc++.h"
using namespace std;

// preprocessing utile per query su un albero
// si "appiattisce" su un array di dimensione n
// ogni sottoalbero di un nodo corrisponde a [in[i], out[i]]

struct tree {

    int n;
    vector<int> in, out, parent;
    vector<vector<int>> adj;

    void tour(int node, int &t) {
        in[node] = t;
        for (auto u: adj[node]) {
            if (u != parent[node]) {
                t++;
                parent[u] = node;
                tour(u, t);
            }
        }
        out[node] = t;
    }

    void build() {
        cin >> n;
        in.resize(n);
        out.resize(n);
        parent.resize(n);
        adj.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        parent[0] = -1;
        int t = 0;
        tour(0, t);
    }

};

int main() {
    tree g;
    g.build();
}
