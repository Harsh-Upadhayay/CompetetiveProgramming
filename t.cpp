        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

ll BitsSetTable256[100001];
set<ll> nums;

void initialize()
{
 
    ll x = 2;
    BitsSetTable256[0] = 0;
    for (ll i = 0; i < 100001; i++)
    {
        BitsSetTable256[i] = (i & 1) +
        BitsSetTable256[i / 2];
        if(x < 100001)
            nums.insert(x - 1);
        x *= 2;
    }
}

ll setBits(ll n)
{
    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24]);
}

vector<ll> ans;
ll fun(ll sum, ll n){
    if(1 == n){
        ans.pb(sum);
        return sum;
    }
    ll x = sum/n, a, b;

    auto itr_a = nums.lower_bound(x), itr_b = nums.upper_bound(x);
    
    if(itr_a != nums.end())
        a = *itr_a;
    else
        a = 1;

    if(itr_b != nums.end())
        b = *itr_b;
    else
        b = 65535;

    ll _a = x-a;
    ll _b = b-x;

    if( _a == _b)
        x = b;
    else if(_a > _b)
        x = b;
    else
        x = a;


    if(sum - x > 0){
        ans.pb(x);
        return fun(sum - x, n-1);
    }
    else{
        ans.pb(sum);
        return sum;
    }
    
}

void solve(void){
    ans.clear();
    ll n, x;
    cin >> n >> x;
    fun(x, n);
    for(auto x : ans)
        cout << x << " ";
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
    initialize();
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


