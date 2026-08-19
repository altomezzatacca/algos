#include "bits/stdc++.h"
using namespace std;

// assumendo grafi diretti

struct unweighted_graph {

    int n, m;
    vector<vector<int>> adj;

    void build() {
        cin >> n >> m;
        adj.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
        }
    }

};

struct weighted_graph {

    int n, m;
    vector<vector<pair<int, int>>> adj;

    void build() {
        cin >> n >> m;
        adj.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b, x; cin >> a >> b >> x;
            adj[a].emplace_back(b, x);
        }
    }

};

struct tree {

    int n;
    vector<int> parent;

    void build() {
        cin >> n;
        parent.resize(n);
        parent[0] = -1;
        for (int i = 1; i < n; i++)
            cin >> parent[i];
    }

};

int main() {
    unweighted_graph g;
    g.build();
    tree t;
    t.build();
}
