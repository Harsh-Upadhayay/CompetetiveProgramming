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
    bool prev;
    rpt(m+n){
        auto x = *ma.begin(), y = *mb.begin();
        if(x.first > y.first){

            if(prev == 0 && itr == k){
                itr = 0;
                c += y.first;
                mb[y.first]--;
                if(mb[y.first] == 0)
                    mb.erase(y.first);
                prev = 1;
                itr++;
                continue;
            }
            else{
                c += x.first;
                ma[x.first]--;
                if(ma[x.first] == 0)
                    ma.erase(x.first);
                prev = 0;
                itr++;
            }
        }
        else{
            if(prev == 1 && itr == k){
                itr = 0;
                c += x.first;
                ma[x.first]--;
                if(ma[x.first] == 0)
                    ma.erase(x.first);
                prev = 0;
                itr++;
            }
            else{
                c += y.first;
                mb[y.first]--;
                if(mb[y.first] == 0)
                    mb.erase(y.first);
                prev = 1;
                itr++;
            }
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


