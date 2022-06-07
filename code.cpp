        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, ans = 0, k;
    cin >> n >> k;
    vector<ll> v;
    multimap<ll, ll> m;

    rpt(n){
        ll x;
        cin >> x;
        v.pb(x);
        // t.pb(x);
        m.insert(make_pair(x,i));
    }

    sort(v.begin(), v.end());
    // sort(t.begin(), t.end());

    // for(auto x : m)
    //     cout << (x.first) << " ";

    rpt(n){
        auto itr = m.find(v[i]);
        
        if(itr == m.end())
            continue;
        if(itr->second != i)
            continue;

        m.erase(itr);

        ll x = v[i];
        auto y = m.end();
        y--;
        ll t = y->first;
        t = (x + t);
        t /= k;
        t *= k;
        ll d = t-x;

        itr = m.find(d);
        if(itr == m.end())
            itr = m.upper_bound(d);

        ll temp = itr->first;
        temp += x;
        temp /= k;
        ans += temp;
        // cout << temp << " ";
        m.erase(itr);


    }

    cout << ans;
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


