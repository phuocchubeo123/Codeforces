#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
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
    ll l, r, x; cin >> l >> r >> x;
    ll a, b; cin >> a >> b;
    if (a == b){ cout << 0 << "\n"; return;}
    if (abs(b - a) >= x){ cout << 1 << "\n"; return;}
    if (a+x > r && a-x < l){ cout << -1 << "\n"; return;}
    if (b+x > r && b-x < l){ cout << -1 << "\n"; return;}
    if (l + x > r){ cout << -1 << "\n"; return;}
    if (a+x > r){
        if (b-x < l){ cout << 3 << "\n"; return;}
        cout << 2 << "\n"; return;
    }
    if (a-x < l){
        if (b+x > r){ cout << 3 << "\n"; return;}
        cout << 2 << "\n"; return;
    }
    cout << 2 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    // cout << T << "\n";
    while(T--){
        // cout << T << "\n";
        solve();
    }
}