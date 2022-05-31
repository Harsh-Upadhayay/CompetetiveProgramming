#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    ll n;
    rpt(16){
    	for(int j = 0; j < 8; j++){
    		ll t =i;
    		cout << "4 " << j << "\n";
    		vector<ll> v;
    		while(t){
    			v.pb(t%2);
    			t /= 2;
    		}
    		reverse(v.begin(), v.end());
    		for(auto x : v)
    			cout << x;
    		cout << "\n";
    	}
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


