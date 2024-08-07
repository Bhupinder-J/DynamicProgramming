#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> h(n);
    for(int &x : h) cin >> x;

    int dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for(int i=2 ; i<n ; i++){
        dp[i] = 1e9;
        for(int x=1 ; x <= k and i-x >= 0 ; x++){
            int cur = abs(h[i] - h[i-x]) + dp[i-x];
            dp[i] = min(dp[i], cur);
        }
    }
    cout << dp[n-1] << endl;
}