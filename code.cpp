        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

#define PRIMES 1000001

bitset<PRIMES+1> isPrime;

void setSieve(){

    for(int i = 2; i <= PRIMES; i++)
        isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i <= PRIMES; i++)
        if(isPrime[i])
            for(int j = i * i; j <= PRIMES; j += i)
                isPrime[j] = false;
    
}

void solve(void){
    ll n, m, ans;
    setSieve();
    cout << isPrime[43];
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


