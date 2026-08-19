#include "bits/stdc++.h"
using namespace std;

// ordina un vettore in O(N log N)

void merge(vector<int> &v, int l, int m, int r) {
    int x = m - l + 1,
        y = r - m;
    vector<int> a(x), b(y);
    for (int i = 0; i < x; i++)
        a[i] = v[i + l];
    for (int i = 0; i < y; i++)
        b[i] = v[i + m + 1];
    int i = l, i_a = 0, i_b = 0;
    while (i_a < x && i_b < y) {
        if (a[i_a] <= b[i_b])
            v[i++] = a[i_a++];
        else
            v[i++] = b[i_b++];
    }
    while (i_a < x)
        v[i++] = a[i_a++];
    while (i_b < y)
        v[i++] = b[i_b++];
}

void merge_sort(vector<int> &v, int l, int r) {
    if (l == r) return;
    int m = (l + r) >> 1;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    merge(v, l, m, r);
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &u: v) cin >> u;
    merge_sort(v, 0, n - 1);
}
