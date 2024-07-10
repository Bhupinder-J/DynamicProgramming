#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
string s, t;

int recursion(int i, int j){
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;

    if(s[i] == t[j]) return recursion(i-1, j-1);
    return 1 + min(recursion(i-1, j), 
               min(recursion(i-1, j-1), 
                   recursion(i, j-1)));
}
int memoization(int i, int j, vvi &dp){
    if(i < 0) return j+1;
    if(j < 0) return i+1;

    int &ans = dp[i][j];
    if(ans != -1) return ans;

    if(s[i] == t[j]) ans = memoization(i-1, j-1, dp);
    else{
        ans = 1 + min(memoization(i-1, j, dp), 
                  min(memoization(i, j-1, dp), 
                      memoization(i-1, j-1, dp)));
    }
    return ans;
}
int memoization(int n, int m){
    vvi dp(n, vi(m, -1));
    return memoization(n-1, m-1, dp);
}
int tabular(int n, int m){
    vvi dp(n + 1, vi(m + 1, 0));
    for(int i=0 ; i<=n ; i++) dp[i][0] = i;
    for(int j=0 ; j<=m ; j++) dp[0][j] = j;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min(dp[i-1][j], 
                               min(dp[i][j-1], 
                                   dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}
int32_t main(){
    cin >> s >> t;
    int n = s.size(), m = t.size();

    // cout << recursion(n-1, m-1) << endl;
    // cout << memoization(n, m) << endl;
    cout << tabular(n, m) << endl;
}