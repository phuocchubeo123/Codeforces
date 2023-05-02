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
vector<vector<int>> adj_rev(maxn);
vi adj(maxn);
vector<bool> used(maxn);
vector<int> order, component;
vi cyc(maxn);

void dfs1(int v) {
    used[v] = true;
    int u = adj[v];
    if (u != -1)
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    // cout << v << " ";
    used[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

void stronglyConnectedCC(){
    order.clear();
    used.assign(n+1, false);
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);
    used.assign(n+1, false);
    reverse(order.begin(), order.end());
    for (auto v : order){
        if (!used[v]) {
            dfs2 (v);
            if (component.size() > 1) for (int x: component) cyc[x] = 1;
            component.clear();
        }
    }
}

vi vis(maxn);
vi cnt(maxn);
vi to_cyc(maxn);
void dfs(int u, int isc){
    vis[u] = 1;
    to_cyc[u] = isc;
    for (int v: adj_rev[u]){
        if (vis[v] == 0) dfs(v, isc);
        cnt[u] += cnt[v] + 1;
    }
}

vi a(maxn);
vi cyc_size(maxn);
vi visii(maxn);

void solve(){
    // 0 6 1 5
    cin >> n;
    rep(i, 1, n) cin >> a[i];

    rep(i, 1, n) cyc[i] = 0; 
    rep(i, 1, n){
        if (a[i] + i > n || a[i] + i < 1){
            continue;
        }
        else if (a[i] == 0) cyc[i] = 1;
        else{
            adj[i] = a[i] + i;
            adj_rev[a[i]+i].push_back(i);
        }
    }

    stronglyConnectedCC();  

    // rep(i, 1, n) cout << cyc[i] << " ";
    // cout << "\n";

    rep(i, 1, n) vis[i] = 0;
    rep(i, 1, n) cnt[i] = 0;
    int cycles = 0;
    // rep(i, 1, n) if (cyc[i] == 1) cycles++;

    to_cyc.assign(n+1, 0);
    rep(i, 1, n){ cyc_size[i] = 0; visii[i] = 0;}

    rep(i, 1, n){
        if (cyc[i] == 1 && visii[i] == 0){
            vi cc;
            int cur = i;
            int c = 0;
            while (true){
                cc.push_back(cur);
                for (int x: adj_rev[cur]) if (cyc[x] == 0){ dfs(x, 1); c += cnt[x] + 1;}
                cur = cur + a[cur];
                if (cur == i) break;
            }
            for (int x: cc){
                cnt[x] = c + cc.size() - 1; 
                cyc_size[x] = cc.size() + c;
                visii[x] = 1;
                to_cyc[x] = 1;
            }
            cycles += cc.size() + c;
            // for (int x: cc) cout << x << " ";
        }
    }
    rep(i, 1, n){
        if (vis[i] == 0 && cyc[i] == 0){
            dfs(i, 0);
        }
    }


    // rep(i, 1, n) cout << cnt[i] << " ";
    // cout << "\n";

    // rep(i, 1, n) if (a[i] == 0) cnt[i]++;
    // cout << cycles << "\n";

    int cur = 1;
    vi visi(n+1, 0);
    ll ans = 1ll * (2 * n + 1) * n;

    bool flag = false;
    while (true){
        if (cur < 1 || cur > n) break;
        if (visi[cur] == 1){ flag = true; break;}
        visi[cur] = 1;
        if (cyc[cur] == 0){
            ans -= 1ll * cycles;

            if (to_cyc[cur] == 0){
                ans -= 1ll;
                ans -= 1ll * cnt[cur];
            }
        }
        else{
            ans -= 1ll * (cycles - cyc_size[cur]);
            ans -= 1ll * cnt[cur];
            ans -= 1ll;
        }

        cur = cur + a[cur];
    }

    // rep(i, 1, n) cout << visi[i] << " ";
    // cout << "\n";
    // cout << ans << " ";

    if (flag){
        rep(i, 1, n){
            if (visi[i] == 0) ans -= 1ll * (2 * n + 1);
        }
    }
    // rep(i, 1, n) cout << cnt[i] << " ";
    // cout << "\n";

    cout << ans << "\n";

    rep(i, 1, n){ adj[i] = -1; adj_rev[i].clear();}
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