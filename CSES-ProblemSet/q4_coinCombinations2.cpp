#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int recursion(int amt, vector<int> &coin, int i){
    if(amt == 0) return 1;
    if(i < 0 or amt < 0) return 0;
    return (recursion(amt, coin, i-1) + recursion(amt - coin[i], coin, i)) % mod;
}
int memoization(int amt, vector<int> &coin, int i, vector<vector<int>> &dp){
    if(amt == 0) return 1;
    if(i < 0 or amt < 0) return 0;

    int &ans = dp[i][amt];
    if(ans != -1) return ans;

    ans = memoization(amt, coin, i-1, dp);
    ans += memoization(amt - coin[i], coin, i, dp);
    return ans % mod;
}
int memoization(int amt, vector<int> &coin, int n){
    vector<vector<int>> dp(n, vector<int> (amt + 1, -1));
    return memoization(amt, coin, n-1, dp);
}
int tabular(int amt, vector<int> &coin, int n){
    vector<int> dp(amt + 1, 0);
    dp[0] = 1;
    for(int i=1 ; i<=n ; i++){
        for(int A=1 ; A<=amt ; A++){
            if(coin[i-1] <= A)
                dp[A] += dp[A - coin[i-1]];
            dp[A] %= mod;
        }
    }
    return dp[amt];
}
int32_t main(){
    int n, amt; cin >> n >> amt;
    vector<int> coin(n);
    for(int &x : coin) cin >> x;

    // cout << recursion(amt, coin, n - 1) << endl;
    // cout << memoization(amt, coin, n) << endl;
    cout << tabular(amt, coin, n) << endl;
}