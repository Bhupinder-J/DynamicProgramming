#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<unordered_set>
#include<unordered_map>

#define int long long
using namespace std;

const int nx = 1e5 + 1;
const int mod = 1e9 + 7;

int32_t main(){
    int n, W; cin >> n >> W;
    vector<vector<int>> info(n, vector<int>(2, 0));
    int sum = 0;
    for(auto &v : info){
        cin >> v[0] >> v[1];
        sum += v[1];
    }
    vector<vector<int>> dp(sum + 1, vector<int>(n, 1e9));
    dp[0][0] = 0;
    dp[info[0][1]][0] = info[0][0];

    for(int i=1 ; i<n ; i++){
        for(int v=0 ; v<=sum ; v++){
            dp[v][i] = dp[v][i-1];
        }
        for(int v=0 ; v<=sum ; v++){
            if(dp[v][i-1] == 1e9)
                continue;
            dp[v + info[i][1]][i] = min(info[i][0] + dp[v][i-1], 
                                                dp[v + info[i][1]][i]);
        }
    }
    for(int i = sum ; i>=0 ; i--){
        if(dp[i][n-1] > W)
            continue;
        cout << i << endl;
        return 0;
    }
}