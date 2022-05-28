        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

bool isSorted(vector<ll> v){
    for(int i = 1; i < v.size(); i++)
        if(v[i] < v[i-1])
            return false;
    return true;
}

void solve(void){
    ll n;
    cin >> n;
    vector<ll> v(n);
    rpt(n)
        cin >> v[i];

    for(int i = (n%2); i < n; i += 2)
        if(v[i] > v[i+1])
            swap(v[i], v[i+1]);


    if(isSorted(v))
        cout << "YES";
    else
        cout << "NO";

    cout << endl;
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


