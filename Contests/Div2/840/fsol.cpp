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
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
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

dsu d(maxn);

int n; // number of nodes
vector<vector<int>> adj(2 * maxn); // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
vi u2, v2;
vi u3, v3;

void NOT_BRIDGE(int u, int v){
    d.unite(u, v);
    u3.push_back(u); 
    v3.push_back(v);
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] <= tin[v])
                NOT_BRIDGE(v, to);
            else{
                u2.push_back(v);
                v2.push_back(to);
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int l;
vector<int> tout;
vector<vector<int>> up;

void dfsLCA(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfsLCA(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(2 * maxn);
    tout.resize(2 * maxn);
    timer = 0;
    l = ceil(log2(2 * maxn));
    up.assign(2 * maxn, vector<int>(l + 1));
    dfsLCA(root, root);
}

int pt[2 * maxn], tot[2 * maxn];
bool vis[2 * maxn];

void dfsTot(int u){
    vis[u] = 1;
    for (int v: adj[u]){
        if (vis[v]) continue;
        tot[v] = pt[v] + tot[u];
        dfsTot(v);
    }
}

void solve(){
    int m; cin >> n >> m;
    vi u(m), v(m);
    forn(i, m){ cin >> u[i] >> v[i]; u[i]--; v[i]--;}
    int q; cin >> q;
    vi a(q), b(q);
    forn(i, q){ cin >> a[i] >> b[i]; a[i]--; b[i]--;}

    forn(i, m){ adj[u[i]].push_back(v[i]); adj[v[i]].push_back(u[i]);}
    find_bridges();

    forn(i, n) adj[i].clear();
    forn(i, n) { u2.push_back(i); v2.push_back(d.get(i) + maxn);}
    forn(i, u2.size()){
        // cout << u2[i] << " " << v2[i] << " " << adj.size() << "\n";
        // continue;
        adj[u2[i]].push_back(v2[i]);
        adj[v2[i]].push_back(u2[i]);
    }

    // forn(i, n){
    //     cout << i << "\n";
    //     for (int j: adj[i]) cout << j << " ";
    //     cout << "\n";
    // }

    preprocess(d.get(0) + maxn);
    forn(i, m) if (d.get(u[i]) == d.get(v[i])) pt[d.get(u[i]) + maxn]++;
    // forn(i, n) cout << pt[i] << " ";
    // cout << "\n";
    memset(vis, n, false);
    tot[d.get(0) + maxn] = pt[d.get(0) + maxn];
    // cout << tot[d.get(0) + maxn] << "\n";
    dfsTot(d.get(0) + maxn);

    // forn(i, n) cout << tot[i] << " ";
    // cout << "\n";

    forn(i, q){
        if (a[i] == b[i]){ cout << 0 << "\n"; continue;}
        // int x = d.get(a[i]), y = d.get(b[i]);
        int x = a[i], y = b[i];
        int z = lca(x, y);
        // cout << x << " " << y << " " << z << "\n";
        if (x == y){ cout << pt[x] << "\n"; continue;}
        if (x == z){ cout << tot[y] - tot[x] - pt[y] << "\n"; continue;}
        if (y == z){ cout << tot[x] - tot[y] - pt[x] << "\n"; continue;}
        cout << tot[x] + tot[y] - 2 * tot[z] - pt[x] - pt[y] + pt[z] << "\n";
    }
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