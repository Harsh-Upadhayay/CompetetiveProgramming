        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

#define PRIMES 200001

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

    for(int i = 2; i <= PRIMES; i++)
        if(isPrime[i])
            primes.pb(i);
    
}

void setFreq(){
    // cout << primes.size();
    for(int i = 0; i < primes.size(); i++)
        if(primes[i] < 100001)
            for(int j = 0; j < primes.size(); j++)
                if(isPrime[primes[j]+primes[i]]){
                    // cout << x << primes[i];
                    // freq[primes[j]]++;
                    freq[primes[i]]++;
                }
    for(auto x : freq)
        cout << x.first << " " << x.second << "\n";
}

void solve(void){
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
    setFreq();

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


