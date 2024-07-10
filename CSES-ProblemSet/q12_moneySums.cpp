#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

void print(int n, int sum, vvi &dp) {
    int count = 0;
    for (int s = 1; s <= sum; s++) {
        for (int i = 0; i < n; i++) {
            if (dp[i][s] != 1) continue;
            count++;
            break;
        }
    }
    cout << count << endl;
    for (int s = 1; s <= sum; s++) {
        for (int i = 0; i < n; i++){
            if (dp[i][s] != 1) continue;
            cout << s << " ";
            break;
        }
    }
    cout << endl;
}
bool recursion(int i, int amt, vi &c) {
    if (amt == 0) return true;
    if (i < 0) return false;
    bool take = false;
    if (c[i] <= amt)
        take = recursion(i - 1, amt - c[i], c);
    bool not_take = recursion(i - 1, amt, c);
    return take || not_take;
}
bool solve(int i, int amt, vi &c, vvi &dp) {
    if (amt == 0) return true;
    if (i < 0) return false;
    int &ans = dp[i][amt];
    if (ans != -1)
        return ans;
    ans = 0;
    if (c[i] <= amt)
        ans |= solve(i - 1, amt - c[i], c, dp);
    ans |= solve(i - 1, amt, c, dp);
    return ans;
}
void memoization(int n, vi &c){
    int sum = accumulate(c.begin(), c.end(), 0ll);
    vvi dp(n, vi(sum + 1, -1));
    for (int i = 1; i <= sum; i++)
        solve(n - 1, i, c, dp);
    print(n, sum, dp);
}
void tabular(int n, vi &c){
    int sum = accumulate(c.begin(), c.end(), 0ll);
    vvi dp(n, vi(sum + 1, 0));
    dp[0][c[0]] = 1;
    for(int i=0 ; i<n ; i++) dp[i][0] = 1;
    for(int i=1 ; i<n ; i++){
        for(int amt = 1 ; amt <= sum ; amt++){
            if(c[i] <= amt) 
                dp[i][amt] |= dp[i-1][amt - c[i]];
            dp[i][amt] |= dp[i-1][amt];
        }
    }
    print(n, sum, dp);
}
int32_t main(){
    fastio();

    int n;cin >> n;
    vi c(n);
    for (int &x : c) cin >> x;

    // memoization(n, c);
    tabular(n, c);
}
