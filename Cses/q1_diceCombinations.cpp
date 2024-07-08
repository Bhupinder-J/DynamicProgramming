#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int recursion(int sum){
    if(sum < 0) return 0;
    if(sum == 0) return 1;

    int ans = 0;
    for(int i=1 ; i<7 ; i++){
        ans += recursion(sum - i);
        ans %= mod;
    }
    return ans;
}
int memoization(int sum, vector<int> &dp){
    if(sum < 0) return 0;
    if(sum == 0) return 1;

    int &ans = dp[sum];
    if(ans != -1) return ans;

    ans = 0;
    for(int i=1 ; i<7 ; i++){
        ans += memoization(sum - i, dp);
        ans %= mod;
    }
    return ans;
}
int memoization(int n){
    vector<int> dp(n + 1, -1);
    return memoization(n, dp);
}
int tabular(int sum){
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for(int i=1 ; i<=sum ; i++){
        for(int j=1 ; j<7 and i-j >= 0 ; j++){
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }
    return dp[sum];
}
int32_t main(){
    int n; cin >> n;
    // cout << recursion(n) << endl;
    // cout << memoization(n) << endl;
    cout << tabular(n) << endl;
}