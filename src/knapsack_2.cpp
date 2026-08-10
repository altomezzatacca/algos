#include "bits/stdc++.h"
using namespace std;
constexpr static int inf = 1e9;

// calcola il valore massimo che non supera peso w
// complessità: O(N * \sum V)

int knapsack(int n, int ww, vector<pair<int, int>> items){
    int sum = 0;
    for(auto [w, v]: items) sum += v;
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, inf));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        auto [w, v] = items[i];
        for(int j = 0; j <= sum; j++){
            if(v <= j)
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v] + w);
            else
                dp[i + 1][j] = dp[i][j];
        }
    }
    for(int i = sum; i >= 0; i--)
        if(dp[n][i] <= ww)
            return i;
    assert(false);
}

int main(){
    int n, w; cin >> n >> w;
    vector<pair<int, int>> items(n);
    for(auto &[w, v]: items) cin >> w >> v;
    int ans = knapsack(n, w, items);
    cout << ans << "\n";
}
