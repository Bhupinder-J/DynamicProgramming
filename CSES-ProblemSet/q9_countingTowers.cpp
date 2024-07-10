#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int recursion(int n, int w){
    if(n == 1) return 1;
    if(w == 1)
        return 4ll*recursion(n-1, 1) + recursion(n-1, 2);
    else 
        return recursion(n-1, 1) + 2ll*recursion(n-1, 2);
}
int memoization(int n, int w, vvi &dp){
    if(n == 1) return 1;

    int &ans = dp[n][w];
    if(ans != -1) return ans;

    if(w == 1) ans = 4ll * memoization(n-1, 1, dp) + memoization(n-1, 2, dp);
    else ans = memoization(n-1, 1, dp) + 2ll * memoization(n-1, 2, dp);
    ans %= mod;

    return ans;
}
int memoization(int n){
    vvi dp(n + 1, vi(3, -1));
    return (memoization(n, 1, dp) + memoization(n, 2, dp)) % mod;
}
int tabular(int n, vvi &dp){
    dp[1][1] = dp[1][2] = 1;
    for(int i=2 ; i<=n ; i++){
        dp[i][1] = (4ll * dp[i-1][1] + dp[i-1][2]) % mod;
        dp[i][2] = (dp[i-1][1] + 2ll * dp[i-1][2]) % mod;
    }
    return (dp[n][1] + dp[n][2]) % mod;
}
int32_t main(){
    fastio();
    vvi dp(1e6 + 1, vi(3, 0));
    tabular(1e6, dp);

    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;

        // WONT WORK !! PRECOMPUTATION REQUIRED 
        // cout << recursion(n, 1) + recursion(n, 2) << endl;
        // cout << memoization(n) << endl;

        cout << (dp[n][1] + dp[n][2]) % mod << endl;
    }
}