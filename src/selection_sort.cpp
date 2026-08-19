#include "bits/stdc++.h"
using namespace std;

// ordina un vettore in O(N^2)

void selection_sort(int n, vector<int> &v) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j])
                swap(v[i], v[j]);
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &u: v) cin >> u;
    selection_sort(n, v);
}
