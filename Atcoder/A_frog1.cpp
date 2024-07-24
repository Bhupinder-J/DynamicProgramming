#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> h(n);
	for(int &x : h) cin >> x;

	int sz_1 = abs(h[n-1] - h[n-2]);
	int sz_2 = 0;

	for(int i = n-3 ; i>=0 ; i--){
		int cur = min(abs(h[i] - h[i+1]) + sz_1, 
					  abs(h[i] - h[i+2]) + sz_2);
		sz_2 = sz_1;
		sz_1 = cur;
	}
	cout << sz_1 << endl;


	// SPACE O(n)
	
	// vector<int> dp(n, 0);
	// dp[n-2] = abs(h[n-1] - h[n-2]);

	// for(int i=n-3 ; i>=0 ; i--){
	// 	dp[i] = min(abs(h[i] - h[i+1]) + dp[i+1], 
	// 				abs(h[i] - h[i+2]) + dp[i+2]);
	// }
	// cout << dp[0] << endl;
}
