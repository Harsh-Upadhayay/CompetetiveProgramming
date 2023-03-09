//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define inf ((ll)1e9)
#define MOD ((ll)(1e9 + 7))
#define ll long long int

class Solution {
    void printGraph(vector<pair<ll, ll>> adj[], ll n) {

        for(ll i = 0; i < n; i++) {

            cout << i << " : ";
            for(auto adjN : adj[i])
                cout << adjN.first << "," << adjN.second << "  ";
            cout << "\n";
        }

    }

    void buildGraph(vector<pair<ll, ll>> adj[], 
                    vector<vector<int>> &edges) {
        
        for(auto edge : edges) 
            adj[edge[0]].push_back({edge[1], edge[2]}),
            adj[edge[1]].push_back({edge[0], edge[2]});
                    
    }

    ll shortestPath(vector<pair<ll, ll>> adj[], ll n, ll src, ll dst) {

            // queue<pair<ll, ll>> pq;
            priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;
            vector<pair<ll, ll>> dist(n, {inf, 0});

            dist[src] = {0, 1};
            pq.push({0, src});
            
            while(!pq.empty()) {

                ll curN = pq.top().second,
                    curD = pq.top().first;
                
                // cout << curN << " ";

                pq.pop();

                for(auto itr : adj[curN]) {
                    
                    ll adjN = itr.first,
                        adjD = itr.second;

                    // cout << adjN << " " << adjD << " " << curD << "\n";

                    if(curD + adjD < dist[adjN].first) {
                        
                        dist[adjN].first = curD + adjD,
                        dist[adjN].second = dist[curN].second,
                        pq.push({curD + adjD, adjN});

                    }
                    else if(dist[adjN].first == curD + adjD) {

                        dist[adjN].second = ((dist[adjN].second) % MOD + (dist[curN].second) % MOD) % MOD;
                        // pq.push({curD + adjD, adjN});

                    }
                }

            }
        // for(ll x : dist) cout << x << " ";
        return dist[dst].second;
    }

  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<ll, ll>> adj[n];
        buildGraph(adj, roads);

        // printGraph(adj, n);

        return shortestPath(adj, n, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends