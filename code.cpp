        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;


ll _solve(ll a, ll b, ll n){
    
    string sa = bitset<31>(a).to_string();
    string sb = bitset<31>(b).to_string();
    string sn = bitset<31>(n).to_string();
    string ans = "0000000000000000000000000000000";
    // cout << sa[30];

    for(int i = 0; i < 31; i++)
        if(sa[i] == sb[i])
            if(sa[i] == 0)
                ans[i] = '1';
            else
                ans[i] = '0';
        else
            if(sa[i] != 0)
                ans[i] = '1';
            else
                ans[i] = '0'; 

    // cout << sa << " " << sb << ": " << ans;
    ll _x = stoi(ans, nullptr, 2); 

    bool flag = true;
    ll count = 0;
    if(a == b){
        return 0;
        // count = 0;
    }
    else if(_x <= n){
        return 1;
        // count = 1;
    }
    else{
        ll maxE = 0, tn = n+1;
        while(tn--){
            maxE = max(maxE, _x & tn);
        }
        a = a^maxE;
        return (1 + _solve(a, b, n));
    }
    

    // cout << (flag? count : -1);

    cout<<endl;

}
void solve(){
    ll n, m, a, b;
    cin >> a >> b >> n;
    cout << _solve(a, b, n);
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


