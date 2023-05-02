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

int n;
vector<vector<int>> adj(maxn), adj_rev(maxn);
vector<bool> used(maxn);
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

void stronglyConnectedCC(){
    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    reverse(order.begin(), order.end());
    for (auto v : order){
        if (!used[v]) {
            dfs2 (v);
            // processing next component
            component.clear();
        }
    }
}

vector<int> roots(maxn, 0);
vector<int> root_nodes;
vector<vector<int>> adj_scc(maxn);

void condensedGraph(){
    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    reverse(order.begin(), order.end());
    // cout << "toposort: ";
    // for (int x: order) cout << x+1 << " ";
    // cout << "\n";
    for (auto v : order){
        if (!used[v]) {
            dfs2(v);
            // for (int uu: component) cout << uu+1 << " ";
            // cout << "\n";
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);
            component.clear();
        }
    }
    for (int v = 0; v < n; v++){
        for (auto u : adj[v]) {
            int root_v = roots[v], root_u = roots[u];
            if (root_u != root_v) 
                adj_scc[root_v].push_back(root_u);
        }
    }
}

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

vector<bool> visited(maxn);
vector<int> orderTopoSort;

void dfsTopoSort(int v) {
    visited[v] = true;
    for (int u : adj_scc[v]) {
        if (!visited[u])
            dfsTopoSort(u);
    }
    orderTopoSort.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    orderTopoSort.clear();
    for (int u: root_nodes)
        if (!visited[u]) 
            dfsTopoSort(u);
    reverse(orderTopoSort.begin(), orderTopoSort.end());
}

vector<bool> vis(maxn);
int goal, have;
void check(int u){
    have++;
    vis[u] = true;
    for (int v: adj_scc[u]){
        if (vis[v]) continue;
        check(v);
    }
}

void solve(){
    cin >> n;
    int m; cin >> m;
    map<int, vi> edges;
    vi u(m), v(m), w(m);
    set<int> weights;
    forn(i, m){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
        edges[w[i]].push_back(i);
        weights.insert(w[i]);
    }

    dsu d(n);
    forn(i, m) d.unite(u[i], v[i]);
    forn(i, n) if (d.get(i) != d.get(1)){ cout << -1 << "\n"; return;}

    vi wts;
    for (int x: weights) wts.push_back(x);
    if (wts[0] != 0){
        reverse(all(wts));
        wts.push_back(0);
        reverse(all(wts));
    }

    int l = 0, r = wts.size() - 1;
    while (l < r){
        int mid = (l + r) / 2;
        forn(i, m){
            adj[u[i]].push_back(v[i]);
            adj_rev[v[i]].push_back(u[i]);
        }
        for (int x: wts){
            if (x > wts[mid]) continue;
            for (int i: edges[x]){
                adj[v[i]].push_back(u[i]);
                adj_rev[u[i]].push_back(v[i]);
            }
        }

        // cout << "wt: " << wts[mid] << "\n";
        // forn(i, n){
        //     cout << i+1 << ": ";
        //     for (int x: adj[i]) cout << x+1 << " ";
        //     cout << "\n";
        // }

        condensedGraph();

        // cout << "condensed graph:\n";
        // for (int uu: root_nodes){
        //     cout << uu+1 << ": ";
        //     for (int vv: adj_scc[uu]) cout << vv+1 << " ";
        //     cout << "\n";
        // }

        topological_sort();
        int x = orderTopoSort[0];
        vis.assign(n, false);
        goal = orderTopoSort.size();
        have = 0;
        check(x);
        // cout << "have: " << have << "\n";
        if (have == goal) r = mid;
        else l = mid + 1;

        order.clear();
        forn(i, n) adj[i].clear();
        forn(i, n) adj_rev[i].clear();
        forn(i, n) adj_scc[i].clear();
        root_nodes.clear();
        orderTopoSort.clear();
    }

    cout << wts[l] << "\n";
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