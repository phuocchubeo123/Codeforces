#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vvi adj(maxn);
vvi chi(maxn);
vi par(maxn), dep(maxn);
vector<bool> vis(maxn);

void dfs(int u){
    for (int v: adj[u]){
        if (par[u] == v) continue;
        par[v] = u;
        chi[u].push_back(v);
        dfs(v);
    }
}

void findDep(int u){
    for (int v: chi[u]){
        findDep(v);
        dep[u] = max(dep[u], dep[v] + 1);
    }
}

void solve(){
    int n; cin >> n;
    vi u(n), v(n);
    forn(i, n-1){
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }

    rep(i, 1, n) par[i] = -1;
    rep(i, 1, n) vis[i] = false;
    dfs(1);

    rep(i, 1, n) dep[i] = 0;
    findDep(1);

    // rep(i, 1, n) cout << dep[i] << " ";
    // cout << "\n";

    ll x = 1;
    forn(i, n-1) (x *= 2) %= MOD;
    ll ans = 0;
    rep(i, 1, n) (ans += 1ll * (dep[i] + 1) * x) %= MOD;
    cout << ans << "\n";

    rep(i, 1, n) adj[i].clear();
    rep(i, 1, n) chi[i].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}