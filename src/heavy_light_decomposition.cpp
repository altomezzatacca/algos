#include "bits/stdc++.h"
using namespace std;

// tecnica per rispondere a query su path in O(log^2 N)

struct tree {

    int n;
    vector<int> parent, depth, heavy, head, pos;
    vector<vector<int>> adj;

    int dfs(int node) { // calcolo e returno la size del sottoalbero, node incluso
        int sz = 1, best = 0;
        for (auto u: adj[node]) {
            if (u == parent[node]) continue;
            parent[u] = node;
            depth[u] = depth[node] + 1;
            int sz_u = dfs(u);
            sz += sz_u;
            if (sz_u > best)
                best = sz_u, heavy[node] = u;
        }
        return sz;
    }

    void decompose(int node, int hd, int &cur_pos) {
        head[node] = hd;
        pos[node] = cur_pos++;
        if (heavy[node] != -1)
            decompose(heavy[node], hd, cur_pos);
        for (auto u: adj[node])
            if (u != parent[node] && u != heavy[node])
                decompose(u, u, cur_pos);
    }

    void build() {
        cin >> n;
        parent.assign(n, -1);
        depth.resize(n);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        adj.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        dfs(0);
        int cur_pos = 0;
        decompose(0, 0, cur_pos);
    }

};

int main() {
    tree t;
    t.build();
}
