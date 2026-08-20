#include "bits/stdc++.h"
using namespace std;
int n, sqrt_n;
vector<int> leaf, sq;

// tecnica per query e update in O(sqrt(n))

void update(int ix, int x) {
    leaf[ix] = x;
    ix = ix / sqrt_n * sqrt_n;
    sq[ix] = leaf[ix];
    for (int i = ix; i < min(n, ix + sqrt_n); i++)
        sq[ix] = gcd(sq[ix], leaf[i]);
}

int range_gcd(int l, int r) {
    int ans = 0;
    int i = l;
    while (i <= r) {
        if (i % sqrt_n == 0 && i + sqrt_n - 1 <= r)
            ans = gcd(ans, sq[i]), i += sqrt_n;
        else
            ans = gcd(ans, leaf[i]), i++;
    }
    return ans;
}

void build() {
    for (auto &u: leaf) cin >> u;
    for (int i = 0; i < n; i += sqrt_n)
        update(i, leaf[i]);
}

int main() {
    cin >> n;
    sqrt_n = sqrt(n) + 1;
    leaf.resize(n);
    sq.resize(n + sqrt_n);
    build();
}
