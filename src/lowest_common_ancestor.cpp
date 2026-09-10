#include "bits/stdc++.h"
using namespace std;

// utilizza il k-th ancestor per rispondere in O(log N)

struct tree {

    int n, logn = 20;
    vector<vector<int>> up;
    vector<vector<int>> adj;
    vector<int> depth;

    void dfs(int node, int d) {
        depth[node] = d;
        for (auto u: adj[node])
            dfs(u, d + 1);
    }

    void blift() {
        up[0][0] = -1;
        for (int i = 1; i < n; i++)
            cin >> up[i][0], adj[up[i][0]].emplace_back(i);
        for (int j = 1; j < logn; j++)
            for (int i = 0; i < n; i++)
                up[i][j] = (up[i][j - 1] == -1 ? -1 : up[up[i][j - 1]][j - 1]);
    }

    void build() {
        cin >> n;
        up.resize(n);
        fill(begin(up), end(up), vector<int> (logn));
        blift();
        dfs(0, 0);
    }

    int kthanc(int node, int k) {
        for (int j = logn - 1; j >= 0 && node != -1; j--)
            if (k & 1 << j)
                node = up[node][j];
        return node;
    }

    int query(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int delta = depth[a] - depth[b];
        a = kthanc(a, delta);
        if (a == b) return a;
        for (int j = logn - 1; j >= 0; j--)
            if (up[a][j] != up[b][j])
                a = up[a][j], b = up[b][j];
        return up[a][0];
    }

};

int main() {
    tree t;
    t.build();
}
