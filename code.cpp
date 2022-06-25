        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

map<ll, list<ll>> graph; 
int dist[1000000];
bool visited[1000000] = {false};

void addEdge(
    ll a, ll b){
    graph[a].pb(b);
    graph[b].pb(a);
    return;
}


int dfs(ll x, ll d){
    dist[x] = d;
    visited[x] = true;
    auto list = graph[x];
    
    for(auto node : list)
        if(!visited[x])
            dfs(node, d+1);
}

void solve(void){
    ll n, m, ans;
    cin >> n;
    ll ar[n];
    graph.clear();
    rpt(n)
        cin >> ar[i];

    ll i = 0;
    while(i < n-1){
        ll j = i+1;
        ll mx = INT_MIN;
        while(j < n){
            if(ar[j] < ar[i])
                break;
            if(mx < ar[j]){
                mx = ar[j];
                addEdge(i, j);
            }
            j++;
        }
        i++;
    }
    reverse(ar, ar+n);

    i = 0;
     while(i < n-1){
        ll j = i+1;
        ll mx = INT_MIN;
        while(j < n){
            if(ar[j] < ar[i])
                break;
            if(mx < ar[j]){
                mx = ar[j];
                addEdge(n-1-i, n-1-j);
            }
            j++;
        }
        i++;
    }
    // while(i < n-1){
    //     ll j = i+1;
    //     while(j < n && ar[j] > ar[j-1]){
    //         ll k = j;
    //         while(k != i){
    //             addEdge(graph, n-1- --k, n-1-j);                
    //         }
    //         j++;
    //     }
    //     i = j;
    // }
    
    for(auto x : graph){
        cout << x.first << " : " ;
        for(auto y : x.second)
            cout << y << " ";
        cout << "\n";
    }

    dfs(0, 0);

    cout << dist[n-1];
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


