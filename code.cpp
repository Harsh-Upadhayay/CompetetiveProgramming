        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    // ll n;
    // cin >>n ;
    // for(int i = 2; i < n; i += 2)
    //     cout << setw(2) << i << " " << bitset<8>(i) << "\n";
    ll n, o = 0, m = INT_MIN;
    vector<pair<ll, ll>> ans;
    cin >> n;
    vector<ll> v(n);
    rpt(n){
        cin >> v[i];
    }
    ll l = 0, r = 0, prev = v[0];
    for(int i = 1; i < n; i++){

        if(!(prev&v[i])){
            r++;
            prev += i;
        }
        else{
            prev = prev&v[i];
            cout << prev;

            ans.pb(make_pair(l, r));
            l = r = i;
        }
    }
    cout << ans.size() << "\n";
    for(auto x : ans)
        cout << x.first << " " << x.second << "\n";
    // cout << m;
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


