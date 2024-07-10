#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main(){
    fastio();
    int n; cin >> n;
    vi a(n);
    for(int &x : a) cin >> x;

    int sz = 1;
    for(int i=1 ; i<n ; i++){
        if(a[i] > a[sz - 1]){
            a[sz] = a[i];
            sz++;
        }else{
            int idx = lower_bound(a.begin(), a.begin()+sz, a[i]) - a.begin();
            a[idx] = a[i];
        }
    }
    cout << sz << endl;
}