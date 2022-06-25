        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void addEdge(
    map<ll, list<ll>> &graph,
    ll a, ll b){
    graph[a].pb(b);
    graph[b].pb(a);
    return;
}

void solve(void){
    ll n, m, ans;
    cin >> n;
    ll ar[n];

    map<ll, list<ll>> graph;

    rpt(n)
        cin >> ar[i];

    ll i = 0;
    while(i < n-1){
        ll j = i+1;
        while(ar[j] > ar[j-1]){
            ll k = j;
            while(k != i){
                addEdge(graph, --k, j);                
            }
            j++;
        }
        i = j;
    }
    for(auto x : graph){
        cout << x.first << " : " ;
        for(auto y : x.second)
            cout << y << " ";
        cout << "\n";
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


