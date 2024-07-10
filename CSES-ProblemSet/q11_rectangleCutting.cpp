#include <bits/stdc++.h>
using namespace std;

// #define int long long    
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int recursion(int n, int m){
    if(n == m) return 0;

    int mini = 1e9;
    for(int i=1 ; i<=n/2 ; i++){
        mini = min(mini, 1 + recursion(n - i, m) + recursion(i, m));
    }
    for(int i=1 ; i<=m/2 ; i++){
        mini = min(mini, 1 + recursion(n, m - i) + recursion(n, i));
    }

    return mini;
}
int memoization(int n, int m, vvi& dp){
    if(n == m) return 0;

    int &ans = dp[n][m];
    if(ans != -1) return ans;

    ans = 1e9;
    for(int i=1 ; i <= n/2 ; i++){
        ans = min(ans, 1 + memoization(n - i, m, dp) + memoization(i, m, dp));
    }
    for(int i=1 ; i <= m/2 ; i++){
        ans = min(ans, 1 + memoization(n, m - i, dp) + memoization(n, i, dp));
    }
    return ans;
}
int memoization(int n, int m){
    vvi dp(n+1, vi(m+1, -1));
    return memoization(n, m, dp);
}
int tabular(int n, int m){
    vvi dp(n+1, vi(m+1, 0));
    for(int i=1 ; i<=n ; i++) dp[i][1] = i-1;
    for(int j=1 ; j<=m ; j++) dp[1][j] = j-1;

    for(int i=2 ; i<=n ; i++){
        for(int j=2 ; j<=m ; j++){
            if(i == j) continue;
            dp[i][j] = 1e9;
            for(int x=1 ; x <= i/2 ; x++) 
                dp[i][j] = min(dp[i][j], 1 + dp[x][j] + dp[i-x][j]);
            for(int x=1 ; x <= j/2 ; x++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][x] + dp[i][j-x]);
        }
    }
    return dp[n][m];
}
int32_t main(){
    fastio();
    int n, m; cin >> n >> m;

    // cout << recursion(n, m) << endl;
    // cout << memoization(n, m) << endl;
    cout << tabular(n, m) << endl;
}