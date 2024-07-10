#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n, m;
vector<int> a(1e5 + 1);

int memoization(int i, int c, vvi &dp){
    if(i == 0) return (c == a[0] || a[0] == 0);
    if(a[i] and c != a[i]) return 0;

    int &ans = dp[i][c];
    if(ans != -1) return ans;

    ans = 0;
    for(int j=max(1ll, c-1); j<=min(m, c+1); j++){
        ans += memoization(i-1, j, dp);
        ans %= mod;
    }
    return ans;
}
int memoization(){
    vvi dp(n, vi(m + 1, -1));
    int ans = 0;
    for(int c = 1 ; c <= m ; c++){
        ans += memoization(n-1, c, dp);
        ans %= mod;
    }
    return ans;
}
int tabular(){
    vi cur(m + 1, 0), prev(m + 1, 0);
    for(int j=1 ; j<=m ; j++)
        prev[j] = (j == a[0] or a[0] == 0);
    for(int i=1 ; i<n ; i++){
        for(int c=1 ; c<=m ; c++){
            if(a[i] and a[i] != c){
                cur[c] = 0;
                continue;
            }
            cur[c] = 0;
            for(int j=max(1ll, c-1); j<=min(m, c+1); j++){
                cur[c] += prev[j];
                cur[c] %= mod;
            }
        }
        prev = cur;
    }
    int ans = 0;
    for(int c=1 ; c<=m ; c++){
        ans += prev[c];
        ans %= mod;
    }
    return ans;
}
int32_t main(){
    fastio();
    cin >> n >> m;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];

    // cout << memoization() << endl;
    cout << tabular() << endl;
}