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
    cin >> n;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];
    vector<ll> l;
    ll lsb = 1;
    \
    rpt(29){
        
        for(int j = 0; j < n; j++)
            if(v[j]&lsb)
                l.push_back(j);

        if(l.size() > 1)
            break;
        else
            l.clear();
        
        lsb = lsb * 2;
    }
    cout << "1 ";
    vector<ll> r;
    r.pb(1);
    rpt(l.size()-1)
        r.pb(l[i]+1);
    for(int i = 0; i < l.size(); i++)
        cout << r[i] << " " << l[i] << " \n";

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


