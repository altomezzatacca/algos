#include "bits/stdc++.h"
using namespace std;

// posso ottenere un certo valore come somma di elementi di un insieme?

bool ss(int n, int s, vector<int> v){
    vector<vector<bool>> dp(n + 1, vector<bool> (s + 1));
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= s; j++){
            if(v[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - v[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][s];
}

int main(){
    int n, s; cin >> n >> s;
    vector<int> v(n);
    for(auto &u: v) cin >> u;
    bool ans = ss(n, s, v);
    cout << (ans ? "YES" : "NO") << "\n";
}
