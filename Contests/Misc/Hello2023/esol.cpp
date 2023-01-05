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
    vi deg(n+1);
    rep(i, 1, n){
        cout << "? " << i << " ";
        rep(j, 1, n) cout << ((j == i) ? 0 : 1);
        cout << "\n";
        cout.flush();
        cin >> deg[i];
    }

    vi players;
    rep(i, 1, n) players.push_back(i);
    sort(all(players), [&](int x, int y){
        return (deg[x] > deg[y]);
    });

    vi cm(n+1, 0);
    int mn = deg[players[0]];
    cm[players[0]] = 1;
    rep(i, 1, n-1){
        cout << "? " << players[i] << " ";
        rep(j, 1, n) cout << ((players[i] != j) ? cm[j] : 0);
        cout << "\n";
        cout.flush();
        int q; cin >> q;
        if (q > 0){ rep(j, 1, n) cm[j] = (deg[j] >= deg[players[i]]) ? 1 : 0;}
   }
    cout << "! ";
    rep(i, 1, n) cout << cm[i];
    cout << "\n";
    cout.flush();

    // 1 -> 2 -> 3 -> 4
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
}