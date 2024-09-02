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
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();

	int dp[n+1][m+1];
	for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;
	for(int j = 0 ; j <= m ; j++) dp[0][j] = 0;

	for(int i = 1; i <= n ; i++){
		for(int j=1 ; j <= m ; j++){
			if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int sz = dp[n][m];
	string ans(sz, '$');

	int i = n, j = m;
	for(int x = sz-1 ; x >= 0 ; x--){
		if(s[i-1] == t[j-1]) ans[x] = s[i-1], i--, j--;
		else if(dp[i][j] == dp[i-1][j]) i--, x++;
		else j--, x++;
	}
	cout << ans << endl;
}