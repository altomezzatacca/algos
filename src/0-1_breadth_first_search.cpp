#include "bits/stdc++.h"
using namespace std;
constexpr static int inf = 1e9;

// come una bfs ma supporta archi sia di peso 0 che di peso 1

struct graph {

    int n, m, src;
    vector<int> dist;
    vector<vector<pair<int, int>>> adj;

    void bfs() {
        deque<int> q;
        q.emplace_front(src);
        for (int i = 0; i < n; i++)
            dist[i] = inf;
        dist[src] = 0;
        while (!q.empty()) {
            auto u = q.front(); q.pop_front();
            for (auto [v, x]: adj[u]) {
                if (dist[v] > dist[u] + x) {
                    if (x == 0) {
                        dist[v] = dist[u];
                        q.emplace_front(v);
                    } else {
                        dist[v] = dist[u] + 1;
                        q.emplace_back(v);
                    }
                }
            }
        }
    }

    void build() {
        cin >> n >> m >> src;
        adj.resize(n);
        dist.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b, x; cin >> a >> b >> x;
            adj[a].emplace_back(b, x);
            adj[b].emplace_back(a, x);
        }
        bfs();
    }

};

int main() {
    graph g;
    g.build();
}
