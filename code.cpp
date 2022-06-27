        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

#define PRIMES 100001

bitset<PRIMES+1> isPrime;
vector<ll> primes;
map<ll, ll> freq;

void setSieve(){

    for(int i = 2; i <= PRIMES; i++)
        isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i <= PRIMES; i++)
        if(isPrime[i])
            for(int j = i * i; j <= PRIMES; j += i)
                isPrime[j] = false;

    primes.pb(2);
    for(int i = 2; i <= PRIMES; i++)
        if(isPrime[i] && isPrime[i + 2])
            primes.pb(i);
    
}


void solve(void){
    ll n;
    cin >> n;
    vector<list<ll>> tree(n+1);
    rpt(n-1){
        ll u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        cout << i << " : ";
        for(auto x : tree[i])
            cout << x << " ";
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

    ll n, m, ans;
    setSieve();

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


