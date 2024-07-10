#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int power(int x, int n){
    if(n == 0) return 1;
    if(n == 1) return x;
    int res = power(x, n / 2);
    res = (res * res) % mod;
    return ((n&1) ? (x * res) % mod : res);
}
int fermat_little_theorm(int r){
    int inverse = power(2, mod - 2);
    int res = (r * inverse) % mod;
    return res;
}
int recursion(int n, int sum){
    if(sum == 0) return 1;
    if(n < 1) return 0;

    int take = 0;
    if(n <= sum) 
        take = recursion(n-1, sum - n);
    int not_take = recursion(n-1, sum);

    return take + not_take;
}
int memoization(int n, int sum, vvi &dp){
    if(sum == 0) return 1;
    if(n < 1) return 0;

    int &ans = dp[n][sum];
    if(ans != -1) return ans;

    ans = 0;
    if(n <= sum) 
        ans += memoization(n-1, sum - n, dp);
    ans += memoization(n-1, sum, dp);
    ans %= mod;

    return ans;
}
int memoization(int n, int sum){
    vvi dp(n + 1, vi(sum + 1, -1));
    return memoization(n, sum, dp);
}
int tabular(int n, int sum){
    vvi dp(n+1, vi(sum+1, 0));
    for(int i=0 ; i<=n ; i++) dp[i][0] = 1;
    for(int i=1 ; i<=n ; i++){
        for(int s=1 ; s<=sum ; s++){
            if(i <= s) 
                dp[i][s] += dp[i-1][s - i];
            dp[i][s] += dp[i-1][s];
            dp[i][s] %= mod;
        }
    }
    return dp[n][sum];
}
int32_t main(){
    fastio();

    int n; cin >> n;
    int sum = n * (n + 1) / 2;
    if(sum&1){
        cout << 0 << endl;
        return 0;
    }
    // cout << fermat_little_theorm(memoization(n, sum / 2)) << endl;
    // cout << fermat_little_theorm(tabular(n, sum / 2)) << endl;
    cout << tabular(n - 1, sum / 2) << endl;
}