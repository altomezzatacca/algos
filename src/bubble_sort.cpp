#include "bits/stdc++.h"
using namespace std;

// ordina un vettore in O(N^2)

void bubble_sort(int n, vector<int> &v) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &u: v) cin >> u;
    bubble_sort(n, v);
}
