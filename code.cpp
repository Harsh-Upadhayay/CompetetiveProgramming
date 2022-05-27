        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

ll find(ll v[], ll n, ll key){
    ll l = 0, r = n-1;
    while(l <= r){
        ll mid = l + (r-l)/2;
        if(v[mid] == key)
            return mid;
        else if(v[mid] < key)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

void solve(void){
    ll n, q;
    cin >> n >> q;
    ll ar[n], preSum[n] = {0};
    rpt(n)
        cin >> ar[i];
    sort(ar, ar+n);
    preSum[0] = ar[0];
    for(int i = 1; i < n; i++)
        preSum[i] = ar[i] + preSum[i-1];
    set<ll> s;
    rpt(n)
        s.insert(preSum[i]); 
    rpt(q){
        ll qry;
        cin >> qry;
        if(find(ar, n, qry) != -1)
            cout << (find(ar, n, qry) + 1);
        else{
            auto tmp = (s.upper_bound(qry));
            if(tmp == s.end())
                cout << "-1";
            else
                cout << (find(ar, n, *tmp) + 1);
        }
        cout << "\n";
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


