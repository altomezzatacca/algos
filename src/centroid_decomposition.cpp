#include "bits/stdc++.h"
using namespace std;

// tecnica per varie query su alberi

struct tree {

    int n;
    int centroid;
    vector<vector<int>> adj;
    vector<int> subtree_size;
    vector<bool> removed;
    vector<int> c_parent;

    int get_sizes (int node, int parent) {
        int sz = 1;
        for (auto u: adj[node])
            if (u != parent && !removed[u])
                sz += get_sizes(u, node);
        return subtree_size[node] = sz;
    }

    int get_centroid (int node, int total_sz, int parent) {
        for (auto u: adj[node])
            if (u != parent && !removed[u])
                if (2 * subtree_size[u] > total_sz)
                    return get_centroid(u, total_sz, node);
        return node;
    }

    void decompose (int node, int p) {
        int sz = get_sizes(node, -1);
        int c = get_centroid(node, sz, -1);
        removed[c] = 1;
        c_parent[c] = p;
        for (auto u: adj[c])
            if (!removed[u])
                decompose(u, c);
        centroid = c;
    }

    tree () {}
    tree (int n, vector<pair<int, int>> edges) : n(n) {
        adj.resize(n);
        subtree_size.resize(n);
        removed.resize(n);
        c_parent.resize(n);
        for (int i = 0; i < n - 1; i++) {
            adj[edges[i].first].emplace_back(edges[i].second);
            adj[edges[i].second].emplace_back(edges[i].first);
        }
        decompose(0, -1);
    }

};

int main() {
    int n; cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i].first >> edges[i].second;
    tree t = tree(n, edges);
}
