        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

priority_queue<pair<ll, ll>> q;

ll fun(unordered_map<ll, vector<ll>> m, ll root){
    
    if(!(m.count(root))){
        q.push(make_pair(1, root));
        return 1;
    }
    
    ll ans = INT_MIN;
    auto list = m[root];
    for(auto x : list){
        ll tmp = fun(m, x);
        ans = max(ans, tmp);
    }

    q.push(make_pair(ans+1, root));
    return ans + 1;
}

void solve(void){
    q = priority_queue<pair<ll, ll>>();
    ll n,  ans, root;
    cin >> n;
    unordered_map<ll, vector<ll>> m;
        
    rpt(n){
        ll x; 
        cin >> x;
        if(x == (i+1)){
            root = x;
            continue;
        }
        auto tmp = m.find(x);
        if(tmp != m.end())
            (*tmp).second.pb(i+1);
        else{
            vector<ll> v;
            v.pb(i+1);
            m[x] = v;
        }
    }

    fun(m, root);

    while(!q.empty()){
        auto x = q.top();
        cout << x.first << " " << x.second << " \n";
        q.pop();
    }
    // for(auto x : m){
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


