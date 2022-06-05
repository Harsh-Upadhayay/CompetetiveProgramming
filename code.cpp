        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans;
    ll l, r;
    cin>> l >> r;
    if(l%2){
        rpt(4)
            cout << (l+i) << "8 ";
    }
    else
        if(r == l+3)
            cout << "-1";
        else
            rpt(4)
                cout << (l + 1 + i) << " " ;
    // for(int i = 1; i < n; i++)
    //     cout << i << " " << i+1 << "  " << (i^(i+1)) << "\n";
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


