#include <iostream>
#include <vector>
#include <cstring>

#define int long long
using namespace std;

const int nx = 1e5+1;
int w[100], v[100];
int dp[100][100001];

int32_t main(){
	int n, W; cin >> n >> W;
	for(int i=0 ; i<n ; i++)
		cin >> w[i] >> v[i];
	for(int wt=w[0] ; wt <= W ; wt++)
		dp[0][wt] = v[0];
	for(int i=1 ; i<n ; i++){
		for(int wt=1 ; wt <= W ; wt++){
			if(w[i] <= wt) dp[i][wt] = v[i] + dp[i-1][wt - w[i]];
			dp[i][wt] = max(dp[i][wt], dp[i-1][wt]);
		}
	}
	cout << dp[n-1][W] << endl;
}