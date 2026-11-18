#include "bits/stdc++.h"
using namespace std;

// trova le componenti fortemente connesse di un grafo in O(n + m)

struct graph {

    int n, m, scc = 0;
    vector<bool> visited;
    vector<int> order, c, roots;
    vector<vector<int>> adj, radj, cadj;
    vector<vector<int>> components;

    void dfs1 (int node) {
        visited[node] = 1;
        for (auto u: adj[node])
            if (!visited[u])
                dfs1(u);
        order.emplace_back(node);
    }

    void dfs2 (int node) {
        visited[node] = 1;
        for (auto u: radj[node])
            if (!visited[u])
                dfs2(u);
        c.emplace_back(node);
    }

    void kosaraju () {
        for(int i = 0; i < n; i++)
            if (!visited[i])
                dfs1(i);
        visited.assign(n, 0);
        reverse(begin(order), end(order));
        for (auto u: order) {
            if (visited[u]) continue;
            c.clear();
            dfs2(u);
            components.emplace_back(c);
            scc++;
            int root = *begin(c);
            for (auto v: c)
                roots[v] = root;
        }
        for (int u = 0; u < n; u++)
            for (auto v: adj[u])
                if (roots[u] != roots[v])
                    cadj[roots[u]].emplace_back(roots[v]);
    }

    void build () {
        cin >> n >> m;
        adj.resize(n);
        radj.resize(n);
        cadj.resize(n);
        roots.resize(n);
        visited.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
            radj[b].emplace_back(a);
        }
        kosaraju();
    }

};

int main() {
    graph g;
    g.build();
}
