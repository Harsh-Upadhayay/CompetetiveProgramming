        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

bool isPalindrom(string &s){
    for(int i = 0; i < s.size()/2; i++)
        if(s[i] != s[s.size()-i-1])
            return false;
    return true;
}

string add(string &s, ll x){
    ll min = stoi(s.substr(3, 2)) + x;
    ll hr = min/60;
    min %= 60;
    hr += stoi(s.substr(0, 2)) % 24;
    string h = to_string(hr), m = to_string(min);
    cout << h;
    // s = "";
    // s += h;
    // s += ":";
    // s += m;
    return s;
}

void solve(void){
    ll n, m, ans = 0;
    string s;
    cin >> s;
    ll intv;
    cin >> intv;
    string curr = s;
    do{
        curr = add(curr, intv);
        curr = add(curr, intv);
        ans += isPalindrom(curr);
    } while(curr != s);
    // cout << ans;
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


