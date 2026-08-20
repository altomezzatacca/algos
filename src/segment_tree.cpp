#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// segment tree iterativo con point update di set e query di somma

struct segtree {

    int sz = 1;
    vector<ll> tree;

    segtree(int n, vector<ll> v) {
        while (sz < n) sz <<= 1;
        tree.resize(2 * sz);
        for (int i = 0; i < n; i++)
            tree[i + sz] = v[i];
        for (int i = n; i < sz; i++)
            tree[i + sz] = 0;
        for (int i = sz - 1; i > 0; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    void update(int ix, ll x) {
        ix += sz;
        tree[ix] = x;
        while (ix >> 1) {
            ix >>= 1;
            tree[ix] = tree[2 * ix] + tree[2 * ix + 1];
        }
    }

    ll query(int l, int r) {
        ll ans = 0;
        l += sz; r += sz;
        while (l < r) {
            if (l & 1) ans += tree[l++];
            if (r & 1) ans += tree[--r];
            l >>= 1, r >>= 1;
        }
        return ans;
    }

};

int main() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto &u: v) cin >> u;
    segtree seg = segtree(n, v);
}
