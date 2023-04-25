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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct dsu{
    vi p;

    dsu(){}
    dsu(int n){p.resize(n); forn(i, n) p[i] = i;}

    int get(int u){
        return (u == p[u]) ? u : (p[u] = get(p[u]));
    }
    bool unite(int u, int v){
        u = get(u); v = get(v);
        if (u != v){ p[u] = v; return true;}
        return false;
    }
};

vector<vi> adj(maxn);
vector<bool> vis(maxn);
vi pos(maxn);
vector<vi> can(maxn);

void dfs(int u){
    // cout << u << " " << ;
    vis[u] = true;
    for (int v: adj[u]){
        if (vis[v]) continue;
        if (can[v][0] == pos[u]) pos[v] = can[v][1];
        else pos[v] = can[v][0];
        dfs(v);
    }
}

void solve(){
    int n; cin >> n;
    vi p(n+1); rep(i, 1, n) cin >> p[i];
    int mn = 1;
    vector<pair<int, int>> nums;
    rep(i, 1, n) nums.push_back({p[i], i});
    sort(all(nums));
    vi a(n+1);
    forn(i, n) a[i] = nums[i].first;
    vi cnt(n+1, 2);
    rep(i, 1, n) cnt[p[i]]--;

    vi b;
    rep(i, 1, n){
        while (cnt[i] > 0){ b.push_back(i); cnt[i]--;}
    }

    if (b.size() > n){ cout << "NO\n"; return;}
    forn(i, n) if (a[i] < b[i]){ cout << "NO\n"; return;}

    vi c(n+1), d(n+1);
    forn(i, n){
        c[nums[i].second] = a[i]; 
        d[nums[i].second] = b[i];
    }

    rep(i, 1, n){
        adj[i].clear(); vis[i] = false; pos[i] = -1; can[i].clear();
    }

    rep(i, 1, n){
        adj[c[i]].push_back(d[i]);
        adj[d[i]].push_back(c[i]);
        can[c[i]].push_back(i);
        can[d[i]].push_back(i);
    }

    // rep(i, 1, n) cout << can[i][0] << " " << can[i][1] << "\n";

    rep(i, 1, n){
        if (vis[i]) continue;
        if (can[i][0] == can[i][1]){ pos[i] = can[i][0]; continue;}
        pos[i] = can[i][0];
        dfs(i);
    }
    // cout << "\n";

    // rep(i, 1, n) cout << pos[i] << " ";

    rep(i, 1, n){
        if (c[pos[i]] != i){
            int tmp = c[pos[i]];
            c[pos[i]] = d[pos[i]];
            d[pos[i]] = tmp;
        }
    }

    cout << "YES\n";
    rep(i, 1, n) cout << c[i] << " ";
    cout << "\n";
    rep(i, 1, n) cout << d[i] << " ";
    cout << "\n";

}

using namespace std::chrono;

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