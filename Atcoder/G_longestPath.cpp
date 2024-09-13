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
vector<int> adj[N];
vector<int> len(N);

void dfs(int cv){
    int mx = 0;
    for(int v : adj[cv]){
        if(len[v] == 0) dfs(v);
        mx = max(mx, 1 + len[v]);
    }
    len[cv] = mx;
}
int32_t main(){
    cin >> n >> m;
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 0;
    for(int i=1 ; i<=n ; i++){
        if(len[i] == 0) dfs(i);
        ans = max(ans, len[i]);
    }
    cout << ans << endl;
}