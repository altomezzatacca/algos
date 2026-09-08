#include "bits/stdc++.h"
using namespace std;

// per ogni nodo di un albero calcola la somma delle distanze da tutti gli altri nodi
// invece di N dfs per un totale di O(N^2) aggiorna in O(1) nella seconda dfs aggiornando la radice

struct tree {

    int n;
    vector<int> sz, ans;
    vector<vector<int>> adj;

    tree(){}
    tree(int n, vector<pair<int, int>> edges): n(n){
        adj.resize(n);
        sz.resize(n);
        ans.resize(n);
        for (auto e: edges) {
            adj[e.first].emplace_back(e.second);
            adj[e.second].emplace_back(e.first);
        }
        dfs1(0, -1, 0);
        dfs2(0, -1);
    }

    int dfs1 (int u, int p, int d) {
        sz[u] = 1;
        ans[0] += d;
        for (auto v: adj[u]) {
            if (v == p) continue;
            sz[u] += dfs1(v, u, d + 1);
        }
        return sz[u];
    }

    void dfs2 (int u, int p) {
        for (auto v: adj[u]) {
            if (v == p) continue;
            ans[v] = ans[u] - sz[v] + (n - sz[v]);
            dfs2(v, u);
        }
    }

};

int main() {
    int n; cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i].first >> edges[i].second;
    tree t = tree(n, edges);
    for (auto u: t.ans) cout << u << " ";
    cout << "\n";
}
