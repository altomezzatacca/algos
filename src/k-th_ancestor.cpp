#include "bits/stdc++.h"
using namespace std;

// query in logn grazie a binary lifting

struct tree {

    int n, logn = 20;
    vector<vector<int>> up;

    void blift() {
        up[0][0] = -1;
        for (int i = 1; i < n; i++)
            cin >> up[i][0];
        for (int j = 1; j < logn; j++)
            for (int i = 0; i < n; i++)
                up[i][j] = (up[i][j - 1] == -1 ? -1 : up[up[i][j - 1]][j - 1]);
    }

    void build() {
        cin >> n;
        up.resize(n);
        fill(begin(up), end(up), vector<int> (logn));
        blift();
    }

    int query(int node, int k) {
        for (int j = logn - 1; j >= 0 && node != -1; j--)
            if (k & 1 << j)
                node = up[node][j];
        return node;
    }

};

int main() {
    tree t;
    t.build();
}
