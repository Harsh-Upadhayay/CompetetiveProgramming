        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

useA(char p, string &c, map<char, ll> &m){
    c += p;
    m[p]--;
    if(m[p] == 0)
        m.erase(p);

}


void solve(void){
    ll n, m, k;     cin >> n >> m >> k;
    string a, b;    cin >> a >> b;

    map<char, ll> ma, mb;

    for(auto x : a)
        ma[x]++;
    for(auto x : b)
        mb[x]++;

    string c = "";
    ll itra = 0, itrb = 0;
    bool prev = 0;
    
    rpt(m+n){
        auto x = *ma.begin(), y = *mb.begin();
        
        if(x.first < y.first){
            if(itra == k){
                useA(y.first, c, mb);
                itrb++;
                itra = 0;
            }
            else{
                useA(x.first, c, ma);
                itra++;
                itrb = 0;
            }
        }
        else{
            if(itrb == k){
                useA(x.first, c, ma);
                itra++;
                itrb = 0;
            }
            else{
                useA(y.first, c, mb);
                itrb++;
                itra = 0;
            }
        }

        if(ma.empty() || mb.empty())
            break;
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


