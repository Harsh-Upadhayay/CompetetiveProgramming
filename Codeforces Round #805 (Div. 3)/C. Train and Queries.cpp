#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define u unsigned
#define pb push_back
#define rpt(n) for(int i = 0; i < n; i++)

void solve(void);

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    // cout << t;
    while(t--) 
        solve();
    return 0;
}

void solve() {
    ll n; cin >> n;
    cout << n;
}

void solvee(){
    ll n, xInit;
    cin>>xInit>>n;
    
    ll curPos = xInit;
    rpt(n){
        ll jumps = i+1;
        if(curPos % 2)
            curPos += jumps;
        else 
            curPos -= jumps;
    }
    cout<<curPos;
    cout<<"\n";
}
