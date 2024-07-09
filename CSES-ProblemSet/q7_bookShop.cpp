#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>

int recursion(int i, int P, vi &price, vi&pages){
    if(i < 0) return 0;
    int take = 0;
    if(price[i] <= P) 
        take = pages[i] + recursion(i-1, P - price[i], price, pages);
    int not_take = recursion(i-1, P, price, pages);
    return max(take, not_take);
}
int memoization(int i, int P, vi &price, vi &pages, vvi &dp){
    if(i < 0) return 0;

    int &ans = dp[i][P];
    if(ans != -1) return ans;

    int take = 0;
    if(price[i] <= P) 
        take = pages[i] + memoization(i-1, P - price[i], price, pages, dp);
    int not_take = memoization(i-1, P, price, pages, dp);

    return ans = max(take, not_take);
}
int memoization(int n, int P, vi &price, vi &pages){
    vvi dp(n, vi(P+1, -1));
    return memoization(n-1, P, price, pages, dp);
}
int tabular(int n, int P, vi &price, vi &pages){
    vvi dp(2, vi(P+1, 0));
    for(int p=1 ; p <= P ; p++) 
        dp[0][p] = (price[0] <= p ? pages[0] : 0);

    for(int i=1 ; i<n ; i++){
        for(int p=1 ; p<=P ; p++){
            int take = 0;
            if(price[i] <= p) 
                take = pages[i] + dp[0][p - price[i]];
            int not_take = dp[0][p];
            dp[1][p] = max(take, not_take);
        }
        dp[0] = dp[1];
    }
    return dp[1][P];
}
int32_t main(){
    int n, P; cin >> n >> P;
    vector<int> price(n), pages(n);
    for(int &x : price) cin >> x;
    for(int &x : pages) cin >> x;

    // cout << recursion(n-1, P, price, pages) << endl;
    // cout << memoization(n, P, price, pages) << endl;
    cout << tabular(n, P, price, pages) << endl;
}