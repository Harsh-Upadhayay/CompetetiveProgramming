        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans;
    cin >> n;
    bool o_flag = false, e_flag = false;
    unordered_set<ll> s;
    rpt(n){
        ll x;
        cin >> x;
        s.insert(x);
        if(x == 0 || x == 2)
            o_flag = true;
        if(x == 1)
            e_flag = true;
    }
    if(!(o_flag | e_flag) || o_flag^e_flag){
        // if(e_flag)
            for(auto x : s)
                if(s.count(x-1)){
                    cout << "NO\n";
                    return;
                }

        cout << "YES";
    }
    else
        cout << "NO";
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


