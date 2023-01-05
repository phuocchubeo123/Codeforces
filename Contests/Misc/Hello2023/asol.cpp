#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef complex<double> cd;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, r = 0;
    forn(i, n){
        if (s[i] == 'L') l++;
        else r++;
    }

    // need rightmost L to be righter than leftmost R
    int left_most_R = -1;
    forn(i, n){
        if (s[i] == 'R'){ left_most_R = i; break;}
    }
    int right_most_L = -1; 
    forn(i, n){
        if (s[i] == 'L'){ right_most_L = i;}
    }

    if (left_most_R == -1 || right_most_L == -1){ cout << -1 << "\n"; return;}
    if (left_most_R < right_most_L){ cout << 0 << "\n"; return;}
    forn(i, n-1){
        if (s[i] == 'L' && s[i+1] == 'R'){ cout << i+1 << "\n"; return;}
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}