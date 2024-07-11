#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int get_idx(int val, vvi &info){
    int hi = sz(info) - 1, lo = 0;
    while(hi - lo > 1){
        int mid = ((hi + lo) >> 1);
        if(info[mid][0] > val) hi = mid;
        else lo = mid + 1;
    }
    if(info[lo][0] > val) return lo;
    if(info[hi][0] > val) return hi;
    return hi + 1;
}
int recursion(int i, vvi &info){
    if(i >= sz(info)) return 0;
    
    int idx = get_idx(info[i][1], info);
    int take = info[i][2] + recursion(idx, info);

    int not_take = recursion(i + 1, info);
    return max(take, not_take);
}
int memoization(int i, vvi &info, vi &dp){
    if(i >= sz(info)) return 0;

    int &ans = dp[i];
    if(ans != -1) return ans;

    ans = 0;
    int idx = get_idx(info[i][1], info);
    ans = max(ans, info[i][2] + memoization(idx, info, dp));
    ans = max(ans, memoization(i + 1, info, dp));

    return ans;
}
int memoization(int n, vvi &info){
    vi dp(n, -1);
    return memoization(0, info, dp);
}
int tabular(int n, vvi &info){
    vi dp(n + 1, 0);
    dp[n-1] = info[n-1][2];
    for(int i=n-2 ; i>=0 ; i--){
        int idx = get_idx(info[i][1], info);
        dp[i] = max(dp[i], info[i][2] + dp[idx]);
        dp[i] = max(dp[i], dp[i + 1]);
    }
    return dp[0];
}
int32_t main(){
    fastio();
    int n; cin >> n;
    vvi info(n, vi(3));
    for(auto &v : info){
        for(auto &x : v) cin >> x;
    }
    sort(info.begin(), info.end());
    // cout << recursion(0, info) << endl;
    // cout << memoization(n, info) << endl;
    cout << tabular(n, info) << endl;
}