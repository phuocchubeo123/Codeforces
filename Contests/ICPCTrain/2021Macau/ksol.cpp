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

const int maxn = 1e5 + 5;
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

int n;
vector<vector<int>> adj(maxn);
vector<bool> visited(maxn);
vector<int> parent(maxn);
int cycle_start, cycle_end;
vector<map<int, int>> hsh_adj(maxn);
vi edges;

bool dfs(int v, int par) { // passing vertex and its parent vertex
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle() {
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);

        forn(i, cycle.size()-1){
            edges.push_back(hsh_adj[cycle[i]][cycle[i+1]]);
        }
    }
}

void solve(){
    int m;
    cin >> n >> m;
    vi u(m), v(m);
    dsu d(n);
    forn(i, m){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }

    bool flag = false;
    forn(i, m){
        // d.unite(u[i], v[i]);
        cout.flush();
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
        hsh_adj[u[i]][v[i]] = i+1;
        hsh_adj[v[i]][u[i]] = i+1;
        // cout << i+1 << " " << u[i] + 1 << " " << v[i] + 1 << "\n";
        if (d.unite(u[i], v[i]) == false){
            find_cycle();
            flag = true;
            break;
        }
    }

    if (!flag){
        cout << -1 << "\n";
    }
    else{
        sort(all(edges));
        forn(i, edges.size()){
            cout << edges[i] << ((i == edges.size()-1) ? "" : " ");
        }
        cout << "\n";
    }

    forn(i, n) adj[i].clear();
    edges.clear();
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