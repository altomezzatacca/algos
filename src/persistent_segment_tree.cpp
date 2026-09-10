#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// struttura dati per tenere traccia di più versioni
// di un array e farci query sopra

struct segtree {

    struct node {
        node *l, *r;
        ll sum, lazy;
        node(ll x) : l(nullptr), r(nullptr), sum(x), lazy(0) {}
        node(node *l, node *r) : l(l), r(r), sum(0), lazy(0) {
            if (l) sum += l -> sum;
            if (r) sum += r -> sum;
        }
    };

    int v, curv = 0;
    vector<node*> versions;

    node *build (const vector<ll>& a, int nl, int nr) {
        if (nr - nl == 1)
            return new node(a[nl]);
        int nm = (nl + nr) >> 1;
        return new node(build(a, nl, nm), build(a, nm, nr));
    }

    segtree (vector<ll> a) {
        v = a.size();
        versions.emplace_back(build(a, 0, v));
    }

    node *pr_update (node *n, int nl, int nr, ll x) {
        node *nn = new node(*n);
        nn -> sum += x * (nr - nl);
        nn -> lazy += x;
        return nn;
    }

    pair<node*, node*> propagate (node *n, int nl, int nr) {
        int nm = (nl + nr) >> 1;
        node *l = n -> l;
        node *r = n -> r;
        if (n -> lazy != 0) {
            l = pr_update(n -> l, nl, nm, n -> lazy);
            r = pr_update(n -> r, nm, nr, n -> lazy);
        }
        return {l, r};
    }

    node *update (node *n, int nl, int nr, int ql, int qr, ll x) {
        if (qr <= nl || nr <= ql) return n;
        if (ql <= nl && nr <= qr) return pr_update(n, nl, nr, x);
        int nm = (nl + nr) >> 1;
        auto [l, r] = propagate(n, nl, nr);
        node *nwl = update(l, nl, nm, ql, qr, x);
        node *nwr = update(r, nm, nr, ql, qr, x);
        return new node(nwl, nwr);
    }

    void update (int l, int r, ll x) {
        versions.emplace_back(update(versions[curv++], 0, v, l, r, x));
    }

    node *rollback (node *cur, node *old, int nl, int nr, int ql, int qr) {
        if (qr <= nl || nr <= ql) return cur;
        if (ql <= nl && nr <= qr) return old;
        int nm = (nl + nr) >> 1;
        auto [curl, curr] = propagate(cur, nl, nr);
        auto [oldl, oldr] = propagate(old, nl, nr);
        node *l = rollback(curl, oldl, nl, nm, ql, qr);
        node *r = rollback(curr, oldr, nm, nr, ql, qr);
        return new node(l, r);
    }

    void rollback (int l, int r, int ver) {
        versions.emplace_back(rollback(versions[curv++], versions[ver], 0, v, l, r));
    }

    ll query (node *n, int nl, int nr, int ql, int qr, ll lazy) {
        if (qr <= nl || nr <= ql) return 0;
        if (ql <= nl && nr <= qr) return n -> sum + lazy * (nr - nl);
        int nm = (nl + nr) >> 1;
        return query(n -> l, nl, nm, ql, qr, lazy + n -> lazy) + query(n -> r, nm, nr, ql, qr, lazy + n -> lazy);
    }

    ll query (int l, int r) {
        return query(versions[curv], 0, v, l, r, 0);
    }

};

int main() {
    int n; cin >> n;
    vector<ll> v(n);
    for (auto &u: v) cin >> u;
    segtree seg(v);
}
