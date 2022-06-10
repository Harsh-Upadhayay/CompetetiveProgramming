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

ll compChildren(ll node, ll* children, map<ll, vector<ll>> &tree){
    if(!tree.count(node)){
        children[node] = 0;
        return children[node]+1;
    }

    ll c = 0;
    for(auto x : tree[node])
        c += compChildren(x, children, tree);

    children[node] = c;
    return children[node]+1;
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
    compChildren(1, children, tree);

    ans = 0;
    ll root = 1;
    do{
        
        auto list = tree[root];
        
        if(list.size() == 2){

            if(children[list[0]] > children[list[1]]){
                ans += children[list[0]];
                root = list[1];
            }

            else if(children[list[0]] < children[list[1]]){
                ans += children[list[1]];
                root = list[0];
            }

            else{
                if(height[list[0]] < height[list[1]]){
                    ans += children[list[0]];
                    root = list[1];
                }
                else{
                    ans += children[list[1]];
                    root = list[0];
                }
            }
        }

        else{
            ans += children[list[0]];
            break;
        }

    } while(tree.count(root));

    // rpt(n)
    //     cout << i+1 << " " << children[i+1] << "\n";
    // for(auto x : tree){
    //     cout << x.first << " : ";
    //     for(auto y : x.second)
    //         cout << y << " ";
    //     cout << endl;
    // }

    cout << ans;
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


