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
vector<bool> in_cycle(maxn);

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

vvi components;

void stronglyConnectedCC(){
    in_cycle.assign(n, false);
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    reverse(order.begin(), order.end());
    for (auto v : order){
        if (!used[v]) {
            dfs2 (v);
            if (component.size() > 1){
                for (int x: component){ in_cycle[x] = true;}
                components.push_back(component);
            }
            component.clear();
        }
    }
}

vi a(maxn);
vi ans(maxn);
map<int, int> anss;
vector<bool> vis(maxn);
map<int, int> alr;
void dfs3(int u){
    if (vis[u]) return;
    vis[u] = true;
    ans[u] = 1;
    for (int v: adj_rev[u]){
        if (!vis[v]) dfs3(v);
        ans[u] += ans[v];
    }
}

void dfs4(int u){
    if (vis[u]) return;
    bool flag = false;
    if (alr[a[u+1]] == 0){
        anss[a[u+1]] += ans[u];
        alr[a[u+1]] = 1;
        flag = true;
    }

    for (int v: adj_rev[u]){
        if (!vis[v]) dfs4(v);
    }

    if (flag) alr[a[u+1]] = 0;
}

void solve(){
    cin >> n;
    rep(i, 1, n) cin >> a[i];

    rep(i, 1, n){
        if (a[i] + i > n || a[i] + i < 1) continue;
        int u = i, v = a[i] + i;
        u--; v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    stronglyConnectedCC();

    // for (vi component: components){
    //     for (int x: component) cout << x << " ";
    //     cout << "\n";
    // }

    ans.assign(n, 0);
    vis.assign(n, false);
    forn(i, n) if (!in_cycle[i]) dfs3(i);

    for (vi component: components){
        int to = 0;
        for (int u: component){
            for (int v: adj_rev[u]){
                if (!in_cycle[v]) to += ans[v];
            }
        }
        for (int u: component){
            ans[u] = component.size() + to;
        }
    }

    vis.assign(n, false);
    for (vi component: components){
        for (int u: component){
            if (alr[a[u+1]] == 1) continue;
            alr[a[u+1]] = 1;
            anss[a[u+1]] += ans[u];
        }
        for (int u: component){
            for (int v: adj_rev[u]){
                if (!in_cycle[v]) dfs4(v);
            }
        }

        for (int u: component) alr[a[u+1]] = 0;
    }

    forn(i, n){
        if (in_cycle[i]) continue; 
        if (adj[i].size() > 0) continue;
        dfs4(i);
    }

    ll answer = 0;
    for (int i = -200000; i <= 200000; i++){
        // if (anss[i] > 0) cout << i << " " << anss[i] << "\n";
        answer += 1ll * anss[i];
    }
    cout << answer << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}