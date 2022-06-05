        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCAS
ll t,T;

ll  ans = 1, height = 1;

void fun(map<ll, vector<ll>> &tree, ll x, ll height){
    if(!tree.count(x)){
        ans = max(ans, height);
        return;
    }
    
    ans = max(ans, height);
    for(auto y : tree[x])
        fun(tree, y, height+1);
}

void solve(void){
    ll n;
    cin >> n;
    map<ll, vector<ll>> tree;
    vector<ll> roots;
    rpt(n){
        ll x;
        cin >> x;
        if(-1 == x){
            roots.pb(i+1);
            continue;
        }
        if(tree.count(x))
            tree[x].pb(i+1);
        else{
            vector<ll> v;
            v.pb(i+1);
            tree[x] = v;
        }

    }


    for(auto x : roots){
        fun(tree, x, 1);
    }
    cout << ans;

    // for(auto x : tree){
    //     cout << x.first << " : ";
    //     for(auto y : x.second)
    //         cout << y << " ";
    //     cout << "\n";
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


