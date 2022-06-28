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
    vector<ll> a(n), b(n);
    ll m1 = INT_MIN, m2 = INT_MIN;
    rpt(n){
        cin >> a[i];
    }
    rpt(n){
        cin >> b[i];
        if(b[i] > a[i])
            swap(a[i], b[i]);
    }
    rpt(n){
        m1 = max(a[i], m1);
        m2 = max(b[i], m2);
    }
    cout << (m1*m2);
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


