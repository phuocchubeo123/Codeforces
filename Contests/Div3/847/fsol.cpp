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
vi par(maxn), vis(maxn);

void dfs(int u){
    vis[u] = 1;
    for (int v: adj[u]){
        if (vis[v] == 1) continue;
        chi[u].push_back(v);
        par[v] = u;
        dfs(v);
    }
}

void solve(){
    int n; cin >> n;
    vi c(n); forn(i, n) cin >> c[i];
    vi u(n), v(n);
    forn(i, n-1){
        cin >> u[i] >> v[i];
    }

    forn(i, n-1){
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }

    par.assign(n+1, 0);
    vis.assign(n+1, 0);
    dfs(1);

    // rep(i, 1, n) cout << par[i] << " ";
    // cout << "\n";

    int ans = n;
    vi best(n+1, n);
    rep(i, 0, n-1){
        int cur = c[i];
        int val = 0;
        // cout << c[i] << ":\n";
        while (cur != 0 && val <= ans){
            // cout << cur << " " << val << "\n";
            ans = min(ans, best[cur] + val);
            best[cur] = min(best[cur], val);
            cur = par[cur];
            val++;
        }
        if (i > 0) cout << ans << " ";
    }

    cout << "\n";
    rep(i, 1, n) adj[i].clear();
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