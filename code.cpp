        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCAS
ll t,T;

bool lucky(ll x){
    while(x){
        ll t = x%10;
        x = x/10;
        if(t == 4 || t == 7)
            continue;
        else
            return false;
    }
    return true;
}

void solve(void){
    ll n, m, ans;
    cin >> n;
    if(lucky(n) || !(n%4) || !(n%7)){
        cout << "YES\n";
        return;
    }

    for(int i = 2; i < n; i++)
        if(!(n%i) && lucky(i)){
            cout << "YES\n";
            return;
        }
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


