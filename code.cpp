        #include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rpt(n) for(ll i = 0; i < n; i++)

#define inf INT_MAX

#define TESTCASE
ll t,T;

bool vowel(char ch){
    return (ch == 'a' or ch == 'o' or ch == 'u' or ch == 'i' or ch == 'e');
}

bool cons(char ch){
    return !vowel(ch);
}

void solve(void){
    ll n, m, ans;
    string s;
    cin >> s;
    bool flag = true;
    for(int i = 0; i < s.size()-1; i++)
        if(cons(s[i]) && s[i] != 'n'){
            if(!vowel(s[i+1])){
                cout << i;
                flag = false;
            }
        }

    cout << (flag  ? "YES":"NO");
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


