#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int recursion(int amt, vector<int> &coin, int n){
    if(amt < 0) return 0;
    if(amt == 0) return 1;

    int ans = 0;
    for(int x : coin) {
        ans += recursion(amt - x, coin, n);
        ans %= mod;
    }
    return ans;
}
int memoization(int amt, vector<int> &coin, int n, vector<int> &dp){
    if(amt < 0) return 0;
    if(amt == 0) return 1;

    int &ans = dp[amt];
    if(ans != -1) return ans;

    ans = 0;
    for(int x : coin) {
        ans += memoization(amt - x, coin, n, dp);
        ans %= mod;
    }
    return ans;
}
int memoization(int amt, vector<int> &coin, int n){
    vector<int> dp(amt + 1, -1);
    return memoization(amt, coin, n, dp);
}
int tabular(int amt, vector<int> &coin, int n){
    vector<int> dp(amt + 1, 0);
    dp[0] = 1;
    for(int A=1 ; A<=amt ; A++){
        for(int x : coin){
            if(x > A) continue;
            dp[A] += dp[A - x];
            dp[A] %= mod;
        }
    }
    return dp[amt];
}
int32_t main(){
    int n, amt; cin >> n >> amt;
    vector<int> coin(n);
    for(int &x : coin) cin >> x;

    // cout << recursion(amt, coin, n) << endl;
    // cout << memoization(amt, coin, n) << endl;
    cout << tabular(amt, coin, n) << endl;
}