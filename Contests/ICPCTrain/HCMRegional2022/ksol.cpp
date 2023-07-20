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

vvi adj(maxn);
vi vis(maxn, 0);
vi cnt(maxn, 0);
vi par(maxn, 0);
vvi chi(maxn);
vi par2(maxn, 0);
vector<set<int>> chi2(maxn);
vector<set<int>> can(maxn);
vector<int> dad(maxn, 0);
vi upd(maxn, 0);
vi ans(maxn, 0);

void find_par(int u){
    for (int v: adj[u]){
        if (par[u] == v) continue;
        par[v] = u;
        chi[u].push_back(v);
        find_par(v);
    }
}

void find_ans(int u){
    for (int v: chi[u]){
        ans[u] += ans[v];
    }
    int mx = 0;
    for (int v: chi2[u]){
        mx = 
    }
}

void solve(){
    int n; cin >> n;
    int k; cin >> k;
    vector<ll> a(n+1);
    rep(i, 1, n) cin >> a[i];
    forn(i, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_par(1);

    // cnt

    vector<pair<int, int>> b;
    rep(i, 1, n) b.push_back({a[i], i});
    sort(all(b));
    vi c;
    for (auto p: b) c.push_back(p.second);

    ll l = 0, r = 2e9+5;
    while (l < r){
        ll m = (l + r) / 2;
        rep(i, 1, n) par2[i] = par[i];
        rep(i, 1, n) chi2[i].clear();
        rep(i, 1, n) can[i].clear();
        rep(i, 1, n){
            for (int x: chi[i]) chi2[i].insert(x);
        }
        for (int x: c){
            queue<int> q;
            for (int y: chi2[x]) q.push(y);
            while (!q.empty()){
                int u = q.front();
                q.pop();
                if (a[x] + a[u] > m){
                    chi2[par2[u]].erase(u);
                    for (int v: chi2[u]){
                        q.push(v);
                    }
                    continue;
                }

                chi2[x].insert(u);
                if (par2[u] != 0){
                    chi2[par2[u]].erase(u);
                    chi2[par2[u]].insert(x);
                    upd[x] = 1;
                }
                par2[u] = x;
            }
        }

        find_ans(1);
    }
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