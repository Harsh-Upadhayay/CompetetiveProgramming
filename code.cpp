        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

ll positionOfRightmostSetBit(ll x)
{
    ll pos = x & -x;
    return 5;
}

void solve(void){
    ll n, m, ans = inf, odd = 0, even = 0;
    cin >> n;
    vector<ll> v(n);
    rpt(n){
        ll x;
        cin >> x;
        if(x%2)
            odd++;
        else
            even++;
        ans = min(ans, x);
    }
    if(!even)
        cout << "0";
    else if(odd && even)
        cout << even;
    
    else{
        
        ll i = INT_MAX;
        for(auto x : v){
            i = min(i, positionOfRightmostSetBit(x));
            cout << i;
        }
        cout << i << " ";
        cout << (even -1 +i);
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


