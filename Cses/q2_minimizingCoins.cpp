#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int recursion(int amt, vector<int> &coin, int n){
    if(amt < 0) return -1;
    if(amt == 0) return 0;

    int ans = 1e9;
    for(int c : coin){
        int min_coin = recursion(amt - c, coin, n);
        if(min_coin == -1) continue;
        ans = min(ans, 1 + min_coin);
    }
    if(ans == 1e9) ans = -1;
    return ans;
}
int memoization(int amt, vector<int> &coin, int n, vector<int> &dp){
    if(amt < 0) return -1;
    if(amt == 0) return 0;

    int &ans = dp[amt];
    if(ans != -2) return dp[amt];

    ans = 1e9;
    for(int c : coin){
        int min_coin = memoization(amt - c, coin, n, dp);
        if(min_coin == -1) continue;
        ans = min(ans, 1 + min_coin);
    }
    if(ans == 1e9) ans = -1;
    return ans;
}
int memoization(int amt, vector<int> &coin, int n){
    vector<int> dp(amt + 1, -2);
    return memoization(amt, coin, n, dp);
}
int tabular(int amt, vector<int> &coin, int n){
    vector<int> dp(amt + 1, 1e9);
    dp[0] = 0;
    for(int A=1 ; A<=amt ; A++){
        for(int i=0 ; i<n ; i++){
            int min_coin = -1;
            if(A >= coin[i])
                min_coin = dp[A - coin[i]];
            if(min_coin == -1) continue;
            dp[A] = min(dp[A], 1 + min_coin);
        }
        if(dp[A] == 1e9) dp[A] = -1;
    }
    return dp[amt];
}
int32_t main(){
    int n, x; cin >> n >> x;
    vector<int> coin(n);
    for(int &x : coin) cin >> x;

    // cout << recursion(x, coin, n) << endl;
    // cout << memoization(x, coin, n) << endl;
    cout << tabular(x, coin, n) << endl;
}