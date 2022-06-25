        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

map<ll, list<ll>> graph; 
// map<ll, ll> dist;
// map<ll, bool> visited;

void addEdge(
    ll a, ll b){
    graph[a].pb(b);
    graph[b].pb(a);
    return;
}

bool BFS( ll src, ll dest, ll v)
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;
 
    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];
    ll dist[v];
    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }
 
    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
 
    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (auto x : graph[u]) {
            if (visited[x] == false) {
                visited[x] = true;
                dist[x] = dist[u] + 1;
                queue.push_back(x);
 
                // We stop BFS when we find
                // destination.
                if (x == dest)
                    return dist[v-1];
            }
        }
    }
    return false;
}
// int dfs(ll x, ll d){
//     dist[x] = d;
//     visited[x] = true;
//     auto list = graph[x];
    
//     for(auto node : list)
//         if(!visited[node])
//             dfs(node, d+1);
// }

void solve(void){
    ll n, m, ans;
    cin >> n;
    ll ar[n];
    graph.clear();
    // dist.clear();
    // visited.clear();
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

    cout << BFS(0, n-1, n);

    // cout << dist[n-1];
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


