        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, a, b;
    cin >> a >> b >> n;

    string sa = bitset<31>(a).to_string();
    string sb = bitset<31>(b).to_string();
    string sn = bitset<31>(n).to_string();
    string ans = "00000000000000000000000000000000";
    // cout << sa[30];

    for(int i = 0; i < 31; i++)
        if(sa[i] == sb[i])
            ans[i] = sa[i] == 0;
        else
            ans[i] = sa[i] != 0; 

    cout << sa << " " << sb << ": " << ans;

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


