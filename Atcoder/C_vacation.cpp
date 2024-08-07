#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int nx = 1e5;
int v[nx][3], dp[nx][3];

int32_t main(){
    int n; cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for(int i=1 ; i<n ; i++){
        for(int c=0 ; c<3 ; c++){
            for(int p=0 ; p<3 ; p++){
                if(p == c) continue;
                dp[i][c] = max(dp[i][c], 
                               v[i][c] + dp[i-1][p]);
            }
        }
    }
    cout << *max_element(dp[n-1], dp[n-1] + 3) << endl;
}