#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, r, b;
    cin >> n >> r >> b;
    ll f = round(r/(b+1));
    ll t = 1.8;
    cout << round(1.8);
    return;
    while(r || b){
        ll t = f;
        if(r)
            while(t-- && r){
                cout << "R";
                r--;
            }
        if(b){
            cout << "B";
            b--;
        }
    }
   
    cout<<endl;

}

int main() {
    srand(time(0));

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    #ifdef TESTCASE
        cin>>t;
        T=t;
        #else
        t = 1;
    #endif
    while(t--) 
        solve();

    return 0;
}


