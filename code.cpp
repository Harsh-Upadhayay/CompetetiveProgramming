    #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCAS
ll t,T;



void solve(void){
    ll n, q, t;
    bool ans;
    cin >> n >> q;
    unordered_map<ll, ll> rook_c, rook_r;
    while(q--){
        cin >> t;
        ll x, y;
        if(1 == t){
            cin >> x >> y;
            rook_r[(x)]++;
            rook_c[(y)]++;
        }
        else if (2 == t){
            cin >> x >> y;
            rook_r[(x)]--;
            rook_c[(y)]--;
            // if(rook_r[x] == 0)
            //     rook_r.erase(x);
            // if(rook_c[y] == 0)
            //     rook_c.erase(y);
        }
        else {
            ans = false;
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ll rookx = -1, rooky = -1;
            bool flag = true;

            if(rook_r[(x1)] && rook_r[(x2)]){

                auto end = x2, start = x1;

                while(start <= end){

                    if(!(rook_r[(start++)]))
                        flag = false;
                }
                if(flag)
                    ans = true;
            } 
               
            if(!ans && rook_c.count(y1) && rook_c.count(y2)){

                bool flag = false;
                auto end = (y2), start = (y1);

                while(start <= end){

                    if(!(rook_c[(start++)]))
                        flag = true;
                }

                if(!flag)
                    ans = true;
                
            }         
            if(ans)
                cout << "Yes";
            else
                cout << "No";
            
           cout << "\n";

        }

        // cout << "***\n";
        // for(auto x : rook_r)
        //         cout << x << " ";
        // cout << "\n";
        // for(auto x : rook_c)
        //         cout << x << " ";
        // cout << "\n***\n";
    }
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
