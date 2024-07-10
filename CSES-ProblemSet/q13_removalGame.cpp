#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int recursion(int i, int j, vi &a){
    if(i > j) return 0;
    if(i == j) return a[i];

    int b1 = a[i] + min(recursion(i+2, j, a), 
                        recursion(i+1, j-1, a));
    int b2 = a[j] + min(recursion(i, j-2, a), 
                        recursion(i+1, j-1, a));

    return max(b1, b2);
}
int memoization(int i, int j, vi &a, vvi& dp){
    if(i > j) return 0;
    if(i == j) return a[i];

    int &ans = dp[i][j];
    if(ans != -1e18) return ans;

    ans = max(ans, a[i] + min(memoization(i+2, j, a, dp), 
                              memoization(i+1, j-1, a, dp)));
    ans = max(ans, a[j] + min(memoization(i, j-2, a, dp), 
                              memoization(i+1, j-1, a, dp)));
    return ans;
}
int memoization(int n, vi &a){
    vvi dp(n, vi(n, -1e18));
    return memoization(0, n-1, a, dp);
}
int tabular(int n, vi &a){
    vvi dp(n + 2, vi(n + 2, 0));
    for(int i = 1; i <= n ; i++) 
        dp[i][i] = a[i - 1];
    for(int i = n-1 ; i>=1 ; i--){
        for(int j=i+1 ; j<=n ; j++){
            int b1 = a[i-1] + min(dp[i+2][j], dp[i+1][j-1]);
            int b2 = a[j-1] + min(dp[i][j-2], dp[i+1][j-1]);
            dp[i][j] = max(b1, b2);
        }
    }
    return dp[1][n];
}
int32_t main(){
    fastio();

    int n; cin >> n;
    vi a(n);
    for(int &x : a) cin >> x;

    // cout << recursion(0, n-1, a) << endl;
    // cout << memoization(n, a) << endl;
    cout << tabular(n, a) << endl;
}