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
        if(!maxE)
            return -1;
        a = a^maxE;
        ll tpm = _solve(a, b, n); 
        return (tpm == -1 ? -1 : 1 + tpm);
    }
    

    // cout << (flag? count : -1);

    cout<<endl;

}
ll __solve(ll a, ll b, ll n){
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
        // return 0;
        count = 0;
    }
    else if(_x <= n){
        // return 1;
        count = 1;
    }
    else{
        ll tx = log2(_x), tn = log2(n);
        if(tn < tx)
            count = -1;
        else
            count = 2;
    }
    return count;
    // cout << count;
}
void solve(){
    ll n, m, a, b;
    cin >> a >> b >> n;   
    ll i = a, j = b, k = n;
    // for(int i = 1; i <= a; i++)
    //     for(int j = 1; j <= b; j++)
    //         for(int k = 1; k <= n; k++)
    //             if(__solve(i, j, k) != _solve(i, j , k))
                cout << i << " " << j << " " << k << " : " << _solve(i, j, k)  << "   " << __solve(i, j, k) << endl;

    
    cout << "\n";
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


