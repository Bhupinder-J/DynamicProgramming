#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>

#define int long long
using namespace std;

const int N = 1e5 + 1;
const int M = 1e9 + 7;

int n, m;
vector<string> g;

int32_t main(){
    cin >> n >> m;
    g = vector<string>(n);
    for(auto &s : g) cin >> s;

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0 ; i<n ; i++){
        if(g[i][0] == '#') break;
        dp[i][0] = 1;
    }
    for(int j=0 ; j<m ; j++){
        if(g[0][j] == '#') break;
        dp[0][j] = 1;
    }
    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j<m ; j++){
            if(g[i][j] == '#') continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= M;
        }
    }
    cout << dp[n-1][m-1] << endl;
}