#include "bits/stdc++.h"
using namespace std;

// nei DAG (grafi diretti e aciclici), il topological sorting
// è una permutazione dei nodi tale che per i < j, non esiste un arco da j a i

struct graph {

    int n, m;
    vector<vector<int>> adj;
    vector<int> tops;
    vector<bool> visited;

    void toposort(int node) {
        if (visited[node]) return;
        visited[node] = true;
        for (auto u: adj[node])
            toposort(u);
        tops.emplace_back(node);
    }

    void build() {
        cin >> n >> m;
        adj.resize(n);
        visited.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            adj[a].emplace_back(b);
        }
        toposort(0);
        reverse(begin(tops), end(tops));
    }

};

int main() {
    graph g;
    g.build();
}
