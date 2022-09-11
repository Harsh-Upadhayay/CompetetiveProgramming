/*  */
#include<bits/stdc++.h>
using namespace std;

#ifdef DarkLord
    #include "debug.h"
#else
    #define debug(x...) 
    class Timer{};
#endif

/*_________________________________________________________________________________________________________________________________________*/

#define ll                      long long int
#define ull                     unsigned ll
#define ld                      long double
#define p(x, y)                 pair<x, y> 
#define pb                      push_back
#define fi                      first
#define se                      second
#define lb                      lower_bound
#define ub                      upper_bound
#define vll                     vector<ll>
#define ninf                    ((ll)((-1)*1e18+5))
#define inf                     ((ll)(1e18+5))
#define MOD                     ((ll)(1e9+7))
#define nmin(v)                 *min_element(all(v))
#define nmax(v)                 *max_element(all(v))
#define rpt(i, begin, end)      for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(x)                  (x).begin(), (x).end() 
#define yes                     cout << "YES";
#define no                      cout << "NO";
#define nl                      cout << "\n";
#define kill(x)                 {cout << x << "\n"; return; }
// #define TESTCASE
#define SIEVE_SIZE                ((ll)(1e5))
/*_________________________________________________________________________________________________________________________________________*/

template<class T>
T inline max(T a, T b, T c, T d = ninf, T e = ninf);
template<class T>
T inline min(T a, T b, T c, T d = inf, T e = inf);
template<class T>
void inline print(vector<T> v);
template<class T>
void inline print(vector<vector<T>> v);

bitset<SIEVE_SIZE> isComposit;
void setSieve();

set<ll> allPrimes;
void storePrimes();
/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

void init(){

    return;
}

set<pair<int, int>> queens;

bool place(vector<string> &board, int r, int c) {

    for(auto pos : queens) 
        if( pos.first  == r ||
            pos.second == c || 
            abs(pos.first  - r)  ==
            abs(pos.second - c)
          )
        return false;

    queens.insert({r, c});
    board[r][c] = 'X';
    return true;
}

void remove(vector<string> &board, int r, int c) {

    board[r][c] = '.';
    queens.erase({r, c});

}

void nqueen(vector<string> &board, int r = 0) {

    if(r == board.size()) {
        print(board); nl; return;
    }

    for(int i = 0; i < board.size(); i++) {
        if(place(board, r, i)) 
            nqueen(board, r + 1);

        remove(board, r, i);
    }
}

void solve(void){
    ll n; cin >> n;

    vector<string> board(n, string(n, '.'));

    nqueen(board);

    nl;
}

class Solution {
    set<pair<int, int>> queens;
    vector<vector<string>> possible_states;
    
    bool place(vector<string> &board, int r, int c) {

        for(auto pos : queens) 
            if( pos.first  == r ||
                pos.second == c || 
                abs(pos.first  - r)  ==
                abs(pos.second - c)
              )
            return false;

        queens.insert({r, c});
        board[r][c] = 'Q';
        return true;
    }

    void remove(vector<string> &board, int r, int c) {

        board[r][c] = '.';
        queens.erase({r, c});

    }

    void nqueen(vector<string> &board, int r = 0) {

        if(r == board.size()) {
            possible_states.push_back(board);
            return;
        }

        for(int i = 0; i < board.size(); i++) {
            if(place(board, r, i)) 
                nqueen(board, r + 1);

            remove(board, r, i);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        
        possible_states.clear();
        vector<string> board(n, string(n, '.'));
        nqueen(board);
        return possible_states;
    }
};

/*_________________________________________________________________________________________________________________________________________*/
/*_________________________________________________________________________________________________________________________________________*/

int main() {
    Timer _;
    srand(time(0));
    #ifdef DarkLord
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("err.txt","w",stderr);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    init();

    ll t = 1;

    #ifdef TESTCASE
        cin >> t;
    #endif
    Solution s;
    while(t--) {
        auto x = s.solveNQueens(4);
        cout << x.size();
    }

    return 0;
}

/*_________________________________________________________________________________________________________________________________________*/

template<class T>
T inline max(T a, T b, T c, T d, T e){
    return max(max(max(a, b), max(c, d)), e);
}

template<class T>
T inline min(T a, T b, T c, T d, T e){
    return min(min(min(a, b), min(c, d)), e);
}

template<class T>
void inline print(vector<T> v){
    for(auto x : v)
        cout << x << " \n";
}

template<class T>
void inline print(vector<vector<T>> v){
    for(auto x : v){
        for(auto y : x)
            cout << y << " ";
        nl;
    }
}

void setSieve(){
    isComposit[0] = isComposit[1] = 1;
    for(long long i = 2; i*i <= SIEVE_SIZE; i++)
        if(isComposit[i] == 0)
            for(long long j = i*i; j <= SIEVE_SIZE; j += i)
                isComposit[j] = 1;

}

void storePrimes(){
    if(isComposit[2])
        setSieve();
    for(ll i = 2; i < SIEVE_SIZE; i++)
        if(!isComposit[i])
            allPrimes.insert(i);
}

/*_________________________________________________________________________________________________________________________________________*/
