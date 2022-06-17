        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n, m, ans;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> lastIdx;
    rpt(n){
        cin >> v[i];
        lastIdx[v[i]] = -1;
    }
    map<ll, double> score;
    lastIdx[v[0]] = 0;
    score[v[0]] = 2;
    for(int i = 1; i < n; i++){
        if(lastIdx[v[i]] == i-1){
            lastIdx[v[i]] = i;
            score[v[i]] = (score.count(v[i]) == 0 ? 2 : (score[v[i]]*2));
        }
        else if(score.count(v[i]) == 0){
            score[v[i]] = 2;
            lastIdx[v[i]] = i;
        }
        else{
            score[v[i]] *= 2;
            score[v[i]] /= pow(2, i-lastIdx[v[i]]-1);
            lastIdx[v[i]] = i;
        }
    }   
    ll curMax = INT_MIN, a;
    for(auto x : score){
        if(x.second > curMax){
            curMax = x.second;
            a = x.first;
        }
        // cout << x.first << " : " << x.second << endl;
    }
    ll r = lastIdx[a]+1, x = 1;
    while(r--){
        if(v[r] == a)
            x *= 2;
        else
            x /= 2;
        if(x == curMax)
            break;
    }
    cout << a+1 << " " << r+1 << " " << lastIdx[a];
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


