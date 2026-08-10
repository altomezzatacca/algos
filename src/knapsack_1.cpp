#include "bits/stdc++.h"
using namespace std;

// calcola il valore massimo che non supera peso w
// complessità: O(N * W)

int knapsack(int n, int ww, vector<pair<int, int>> items){
    vector<vector<int>> dp(n + 1, vector<int> (ww + 1));
    for(int i = 0; i < n; i++){
        auto [w, v] = items[i];
        for(int j = 0; j <= ww; j++){
            if(w <= j)
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w] + v);
            else
                dp[i + 1][j] = dp[i][j];
        }
    }
    return dp[n][ww];
}

int main(){
    int n, w; cin >> n >> w;
    vector<pair<int, int>> items(n);
    for(auto &[w, v]: items) cin >> w >> v;
    int ans = knapsack(n, w, items);
    cout << ans << "\n";
}
