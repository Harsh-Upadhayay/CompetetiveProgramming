    #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCAS
ll t,T;

void solve(void){
    ll n, q, t;
    cin >> n >> q;
    set<ll> rook_c, rook_r;
    while(q--){
        cin >> t;
        ll x, y;
        if(1 == t){
            cin >> x >> y;
            rook_r.insert(x);
            rook_c.insert(y);
        }
        else if (2 == t){
            cin >> x >> y;
            rook_r.erase(x);
            rook_c.erase(y);
        }
        else {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ll rookx = -1, rooky = -1;

            if(rook_r.upper_bound(x1) != rook_r.end())
                rookx = *(rook_r.upper_bound(x1));
            
            if(rook_c.upper_bound(y1) != rook_c.end())
                rooky = *(rook_c.upper_bound(y1));
            
            cout << rookx << " " << rooky;

            if(
            rooky >= y1 && rooky <= y2
            || 
            rookx >= x1 && rookx <= x2
            )
                cout << "Yes\n";
            else
                cout << "No\n";

        }
    }
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


