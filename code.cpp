        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n,q, d, m, ans;
    cin >> q >> d;
    vector<ll> table;
    rpt(10)
        table.push_back((i+1)*d);
    rpt(q){
        ll qry;
        cin >> qry;
        bool flag = false;
        rpt(10)
            if(table[i] % 10 == qry % 10 && table[i] <= qry)
                flag = true;
        cout << (flag ? "YES":"NO") << "\n";
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


