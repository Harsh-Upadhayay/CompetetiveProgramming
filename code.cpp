        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

void solve(void){
    int n, x;
    cin >> n >> x;
    int y = (n - (n%2))/2;
    if(n == 1 && x == 1)
        cout << "a";
    else if(y == x){
        int i = 0;
        while(i < x)
            cout << (char)(i++ + 'a');
        if(n % 2)
            cout << (char)(i + 'a');
        while(i-- > 0)
            cout << (char)(i + 'a');
    }
    else
        cout << "-1";
    
    cout << "\n";
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


