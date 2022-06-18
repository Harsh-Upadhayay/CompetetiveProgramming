        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

map<ll, ll> visited, Distance;

void dfs(map<ll, list<ll>> tree, ll node, ll dist = 0){
    if(visited[node])
        return;
    visited[node] = 1;
    Distance[node] = dist;

    for(auto child : tree[node]){
        dfs(tree, child, dist+1);
    } 
}

void solve(void){
    visited.clear();
    Distance.clear();
    ll n, m, ans;
    cin >> n;
    map<ll, list<ll>> tree;

    rpt(n-1){
        ll u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(tree, 1);

    for(auto x : Distance)
        cout << x.first << " : " << x.second << endl;
    cout << endl;

    for(auto x : tree){
        cout << x.first << " : ";
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


