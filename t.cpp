        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

ll compHeight(ll node, ll* height, map<ll, vector<ll>> &tree){
    if(!tree.count(node)){
        height[node] = 1;
        return height[node];
    }

    ll h = INT_MAX;
    for(auto x : tree[node])
        h = min(compHeight(x, height, tree), h);

    height[node] = h+1;
    return h+1;
}

void solve(void){
    ll n, m, ans;
    cin >> n;
    ll height[n+1], children[n+1];
    map<ll, vector<ll>> tree;

    rpt(n-1){
        ll u, v;
        cin >> u >> v;
        if(tree.count(u))
            tree[u].pb(v);
        else{
            vector<ll> ve;
            ve.pb(v);
            tree[u] = ve;
        }
    }
    compHeight(1, height, tree);
    rpt(n)
        cout << i+1 << " " << height[i+1] << "\n";
    // for(auto x : tree){
    //     cout << x.first << " : ";
    //     for(auto y : x.second)
    //         cout << y << " ";
    //     cout << endl;
    // }
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


