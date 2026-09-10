#include "bits/stdc++.h"
using namespace std;

// calcola in O(N) l'elemento successivo strettamente maggiore per ogni indice
// facilmente adattabile a previous e smaller

vector<int> nge (int n, vector<int> v) {
    stack<pair<int, int>> s;
    vector<int> nxt(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first <= v[i])
            s.pop();
        if (s.empty())
            nxt[i] = n;
        else
            nxt[i] = s.top().second;
        s.emplace(v[i], i);
    }
    return nxt;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &u: v) cin >> u;
    vector<int> nxt = nge(n, v);
}
