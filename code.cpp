        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCAS
ll t,T;

void solve(void){
    ll n, s;
    cin >> n >> s;
    vector<ll> go(n), come(n);
    rpt(n)
        cin >> go[i];
    rpt(n)
        cin >> come[i];
    s--;
    if(!(go[s] || come[s]) || !go[0]){
        cout << "NO";
    }
    else if(go[s]){
        cout << "YES";
    }
    else if(come[s]){
        bool flag = false;
        for(int i = s+1; i < n; i++){
            if(go[i] && come[i])
                flag = true;
        }
        cout << (flag?"YES":"NO");
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


