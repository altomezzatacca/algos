#include "bits/stdc++.h"
using namespace std;

// sottosequenza comune più lunga tra due stringhe

string lcs(int n, int m, string s, string t){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(s[i - 1] == t[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    function<string(int, int)> st = [&](int i, int j) -> string {
        if(i == 0 || j == 0) return "";
        if(dp[i][j] == dp[i][j - 1]) return st(i, j - 1);
        if(dp[i][j] == dp[i - 1][j]) return st(i - 1, j);
        return st(i - 1, j - 1) + s[i - 1];
    };
    string ans = st(n, m);
    return ans;
}

int main(){
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    string ans = lcs(n, m, s, t);
    cout << ans << "\n";
}
