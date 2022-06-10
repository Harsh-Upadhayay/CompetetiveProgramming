        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, k;     cin >> n >> m >> k;
    string a, b;    cin >> a >> b;

    map<char, ll> ma, mb;

    for(auto x : a)
        ma[x]++;
    for(auto x : b)
        mb[x]++;

    string c = "";
    ll itr = 0;
    rpt(m+n){
        auto x = *ma.begin(), y = *mb.begin();
        bool prev;
        if(x.first > y.first){
            c += x.first;
            ma[x.first]--;
            if(x.second == 0)
                ma.erase(x.first);
        }
        else{
            c += y.first;
            mb[y.first]--;
            if(y.second == 0)
                mb.erase(y.first);
        }

    }

    cout << c;
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


