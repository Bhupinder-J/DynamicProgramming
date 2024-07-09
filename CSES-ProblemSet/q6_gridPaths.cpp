#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>

int recursion(int i, int j, vs &g){
    if(i == 0 and j == 0) return 1;
    if(g[i][j] == '*') return 0;

    int a1 = 0, a2 = 0;
    if(i) a1 = recursion(i-1, j, g);
    if(j) a2 = recursion(i, j-1, g);
    return a1 + a2;
}
int memoization(int i, int j, vs &g, vvi &dp){
    if(i == 0 and j == 0) 
        return g[i][j] != '*';
    if(g[i][j] == '*') return 0;

    int &ans = dp[i][j];
    if(ans != -1) return ans;

    ans = 0;
    if(i) ans += memoization(i-1, j, g, dp);
    if(j) ans += memoization(i, j-1, g, dp);
    ans %= mod;

    return ans;
}
int memoization(int n, vs &g){
    vvi dp(n, vi(n, -1));
    return memoization(n-1, n-1, g, dp);
}
int tabular(int n, vs &g){
    vvi dp(n, vi(n, 0));
    dp[0][0] = (g[0][0] != '*');

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i == 0 and j == 0) continue;
            if(i) dp[i][j] += dp[i-1][j];
            if(j) dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;

            if(g[i][j] == '*') dp[i][j] = 0;
        }
    }
    return dp[n-1][n-1];
}   
int32_t main(){
    int n; cin >> n;
    vs g(n);
    for(string &s : g) cin >> s;

    // cout << recursion(n-1, n-1, g) << endl;
    // cout << memoization(n, g) << endl;
    cout << tabular(n, g) << endl;
}