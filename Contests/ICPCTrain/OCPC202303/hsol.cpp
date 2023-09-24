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

const int maxn = 2e6 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<int> prime(maxn, 0);

void setup(){
    for (int i = 2; i < maxn; i++) prime[i] = 1;
    for (int i = 2; i < maxn; i++){
        if (prime[i] == 0) continue;
        for (int j = 2; i * j < maxn; j++){
            prime[i*j] = 0;
        }
    }
}

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

void solve(){
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    ll ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            if (prime[a[i] + a[j]] == 1){
                ans++;
                break;
            } 
        }
    }

    // cout << ans << "\n";

    vector<int> node;
    vector<int> cnt;

    node.push_back(a[0]);
    cnt.push_back(1);

    int pt = 0;

    for (int i = 1; i < n; i++){
        if (a[i] == a[i-1]){
            cnt[pt]++;
        }
        else{
            cnt.push_back(1);
            pt++;
            node.push_back(a[i]);
        }
    }

    Dinic d(n+5, n+2, n+4);
    d.add_edge(n+2, n+3, k);
    for (int i = 0; i < node.size(); i++){
        if (node[i] % 2 == 0){
            d.add_edge(n+3, i, cnt[i]);
        }
        else{
            d.add_edge(i, n+4, cnt[i]);
        }
    }

    for (int i = 0; i < node.size(); i++){
        if (node[i] % 2 == 1) continue;
        for (int j = 0; j < node.size(); j++){
            if (node[j] % 2 == 0) continue;
            if (prime[node[i] + node[j]] == 1) d.add_edge(i, j, d.flow_inf);
            // cout << node[i] << " " << node[j] << "\n";
        }
    }

    // cout << d.edges.size() << "\n";

    // for (auto e: d.edges){
    //     cout << e.u << " " << e.v << " " << e.cap << " " << e.flow << "\n";
    // }

    ll f = d.flow();

    // for (auto e: d.edges){
    //     cout << e.u << " " << e.v << " " << e.cap << " " << e.flow << "\n";
    // }

    if (node[0] != 1){
        if (f >= k) cout << 2*k << "\n";
        else cout << min(k+f, ans) << "\n";
    }
    else{
        FlowEdge e = d.edges[1];
        ll ans2 = (e.cap - e.flow) / 2 * 2;
        k -= ans2 / 2;
        if (f >= k) cout << 2 * k + ans2 << "\n";
        else cout << min(k + f + ans2, ans) << "\n"; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    setup();
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}