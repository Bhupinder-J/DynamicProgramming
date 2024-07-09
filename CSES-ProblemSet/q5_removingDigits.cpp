#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

bool is_present(int n, int k){
    while(n){
        if(n%10 == k) return true;
        n /= 10;
    }
    return false;
}
int recursion(int n){
    if(n == 0) return 0;

    int mini = 1e9;
    for(int i=1 ; i<10 ; i++){
        if(!is_present(n, i)) continue;
        mini = min(mini, 1 + recursion(n - i));
    }
    return mini;
}
int memoization(int n, vector<int> &dp){
    if(n == 0) return 0;

    int &ans = dp[n];
    if(ans != -1) return ans;

    ans = 1e9;
    for(int i=1 ; i<10 ; i++){
        if(!is_present(n, i)) continue;
        ans = min(ans, 1 + memoization(n - i, dp));
    }
    return ans;
}
int memoization(int n){
    vector<int> dp(n + 1, -1);
    return memoization(n, dp);
}
int tabular(int n){
    vector<int> dp(n+1, 0);
    for(int i=1 ; i<=n ; i++){
        dp[i] = 1e9;
        for(int d=0 ; d<10 ; d++){
            if(!is_present(i, d)) continue;
            dp[i] = min(dp[i], 1 + dp[i - d]);
        }
    }
    return dp[n];
}
int32_t main(){
    int n; cin >> n;
    // cout << recursion(n) << endl;
    // cout << memoization(n) << endl;
    cout << tabular(n) << endl;
}