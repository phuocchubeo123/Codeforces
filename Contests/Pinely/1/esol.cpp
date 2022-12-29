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

const int maxn = 4e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vi> adj(maxn), chi(maxn);
vi vis(maxn), par(maxn), co(maxn);
int color;

void connectedComponents(int u){
    if (co[u] != -1) return;
    co[u] = color;
    for (int v: adj[u]) connectedComponents(v);
}

void solve(){
    int n; cin >> n;
    forn(u, n) adj[u].clear();
    forn(u, n){
        string s; cin >> s;
        forn(v, n) if (s[v] == '1') adj[u].push_back(v);
    }

    color = 0;
    forn(i, n) co[i] = -1;
    forn(i, n){
        if (co[i] != -1) continue;
        color++;
        connectedComponents(i);
    }

    forn(i, n) cout << co[i] << " ";
    cout << "\n";
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