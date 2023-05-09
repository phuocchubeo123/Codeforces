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

const int maxn = 5e5 + 5;
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

map<ll, int> encode;
void makeUnique(vi &a){
    sort(all(a));
    auto it = unique(all(a));
    a.resize(distance(a.begin(), it));

    forn(i, a.size()){
        encode[a[i]] = i;
    }
}

vi a(maxn), b(maxn), c(maxn);

void solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, m){
        cin >> a[i] >> b[i] >> c[i];
    }

    int q; cin >> q;
    vi u(q), v(q);
    forn(i, q){
        cin >> u[i] >> v[i];
    }

    dsu dd(n+1);
    rep(i, 1, m) dd.unite(a[i], b[i]);
    rep(i, 1, n-1) if (dd.get(i) != dd.get(i+1)){
        cout << -1 << "\n";
        return;
    }

    vi tasks;
    rep(i, 1, m) tasks.push_back(i);
    sort(all(tasks), [](int x, int y){
        return (c[x] < c[y]);
    });

    // for (int x: tasks) cout << x << " ";
    // cout << "\n";

    vi alr(m+1, 0);

    dsu d(n+1);
    forn(i, q){
        alr[u[i]] = 1;
        alr[v[i]] = 1;
        d.unite(a[u[i]], b[u[i]]);
        d.unite(a[v[i]], b[v[i]]);
    }

    // rep(i, 1, n) cout << d.get(i) << " ";
    // cout << "\n";
    // rep(i, 1, m) cout << alr[i] << " ";
    // cout << "\n";

    vi init;

    ll cst = 0;
    for (int i: tasks){
        if (alr[i] == 0){
            if (d.get(a[i]) == d.get(b[i])) continue;
            // cout << i << " " << a[i] << " " << b[i] << "\n";
            d.unite(a[i], b[i]);
            init.push_back(i);
            cst += 1ll * c[i];
        }
    }

    // cout << "plain cost: " << cst << "\n";

    dsu d1(n+1);
    for (int i: init){
        d1.unite(a[i], b[i]);
    }

    vi nodes;
    rep(i, 1, n) nodes.push_back(d1.get(i));
    makeUnique(nodes);

    vvi adj(nodes.size(), vi(nodes.size(), 1005));
    rep(i, 1, m){
        int node1 = encode[d1.get(a[i])];
        int node2 = encode[d1.get(b[i])];
        adj[node1][node2] = min(adj[node1][node2], c[i]);
        adj[node2][node1] = min(adj[node2][node1], c[i]);
    }

    int sz = nodes.size();
    vector<pair<pair<int, int>, int>> edges;
    forn(i, sz){
        rep(j, i+1, sz-1){
            if (adj[i][j] < 1005) edges.push_back({{i, j}, adj[i][j]});
        }
    }

    sort(all(edges), [](pair<pair<int, int>, int> X, pair<pair<int, int>, int> Y){
        return X.second < Y.second;
    });

    ll ans = 1e9;

    for (int mask = 0; mask < (1 << q); mask++){
        ll cst2 = cst;
        dsu d2(sz);
        set<int> used;
        for (int bit = 0; bit < q; bit++){
            int curr;
            if ((mask >> bit) & 1) curr = u[bit];
            else curr = v[bit];
            used.insert(curr);
        }

        for (int curr: used){
            cst2 += 1ll * c[curr];
            int node1 = encode[d1.get(a[curr])];
            int node2 = encode[d1.get(b[curr])];
            d2.unite(node1, node2);
        }

        for (auto edge: edges){
            int node1 = edge.first.first;
            int node2 = edge.first.second;
            int cost = edge.second;
            if (d2.get(node1) != d2.get(node2)){
                cst2 += 1ll * cost;
            }
            d2.unite(node1, node2);
        }

        ans = min(ans, cst2);
    }

    cout << ans << "\n";
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