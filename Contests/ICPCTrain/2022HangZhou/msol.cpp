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

vector<vector<pair<int, ll>>> adj(maxn), chi(maxn);
vi par(maxn, -1), dis(maxn, 0);
vector<ll> cst(maxn, 0), sz(maxn, 0), sm(maxn, 0);
int k;
ll dm1, dm2;

void rt(int u){
    for (pii p: adj[u]){
        int v = p.first;
        ll c = p.second;
        if (par[u] == v) continue;
        chi[u].push_back({v, c});
        par[v] = u;
        rt(v);
    }
}

void find_sz(int u){
    if (dis[u] == 1) sz[u] = 1;
    for (pii p: chi[u]){
        int v = p.first;
        find_sz(v);
        sz[u] += sz[v];
    }
}

void find_cst(int u){
    for (pii p: chi[u]){
        int v = p.first;
        ll c = p.second;
        cst[v] = cst[u] + c;
        find_cst(v);
    }
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

void find_sm(int u){
    for (pii p: chi[u]){
        int v = p.first;
        ll c = p.second;
        sm[v] = sm[u] - sz[v] * c + (k - sz[v]) * c;
        find_sm(v);
    }
}

vector<int> hav(maxn, 0);

void find_hav(int u){
    for (pii p: chi[u]){
        int v = p.first;
        find_hav(v);
        if (hav[v] == 1) hav[u] = 1;
    }
    if (dis[u] == 1) hav[u] = 1;
}

vector<ll> a1(maxn, 0), b1(maxn, 0);

void find_ab1(int u){
    for (pii p: chi[u]){
        int v = p.first;
        ll c = p.second;
        find_ab1(v);
        if (hav[v] == 1) a1[u] = a1[v] + c;
    }

    if (dis[u]) a1[u] = 0;

    for (pii p: chi[u]){
        int v = p.first;
        ll c = p.second;
        b1[u] = gcd(b1[u], b1[v], dm1, dm2);
        if (hav[v] == 1) b1[u] = gcd(b1[u], abs(a1[u] - (a1[v] + c)), dm1, dm2);
    }
}



vector<ll> a2(maxn, 0), b2(maxn, 0);

void find_ab2(int u){
    if (dis[u] == 1){
        b2[u] = gcd(b2[u], a2[u], dm1, dm2);        
        a2[u] = 0;
    }
    
    // cout << u << " " << b2[u] << "\n";
    for(pii p: chi[u]){
        int v = p.first;
        ll c = p.second;
        a2[v] = a2[u] + c;
        b2[v] = gcd(b2[v], b2[u], dm1, dm2);
    }

    // for (pii p: chi[u]){
    //     int v = p.first;
    //     cout << b2[v] << " ";
    // }
    // cout << "\n";

    vector<ll> c1(chi[u].size()), d1(chi[u].size());
    ll C = 0, D = 0;

    forn(i, chi[u].size()){
        pii p = chi[u][i];
        int v = p.first;
        ll c = p.second;
        C = gcd(C, b1[v], dm1, dm2);
        c1[i] = C;
    }

    per(i, chi[u].size() - 1, 0){
        pii p = chi[u][i];
        int v = p.first;
        ll c = p.second;
        D = gcd(D, b1[v], dm1, dm2);
        d1[i] = D;
    }

    // cout << u << ":\n";
    // for (int x: c1) cout << x << " ";
    // cout << "\n";
    // for (int x: d1) cout << x << " ";
    // cout << "\n";

    forn(i, chi[u].size()){
        pii p = chi[u][i];
        int v = p.first;
        ll c = p.second;
        if (i < chi[u].size() - 1){
            b2[v] = gcd(b2[v], d1[i+1], dm1, dm2);
        }
        if (i > 0){
            b2[v] = gcd(b2[v], c1[i-1], dm1, dm2);
        }
    }

    vector<ll> c2(chi[u].size()), d2(chi[u].size());
    C = 0, D = 0;

    forn(i, chi[u].size()){
        pii p = chi[u][i];
        int v = p.first;
        ll c = p.second;
        if (hav[v] == 1) C = gcd(C, abs(a2[u] - (a1[v]+c)), dm1, dm2);
        c2[i] = C;
    }

    per(i, chi[u].size() - 1, 0){
        pii p = chi[u][i];
        int v = p.first;
        ll c = p.second;
        if (hav[v] == 1) D = gcd(D, abs(a2[u] - (a1[v] + c)), dm1, dm2);
        d2[i] = D;
    }

    // for (int x: c2) cout << x << " ";
    // cout << "\n";
    // for (int x: d2) cout << x << " ";
    // cout << "\n";

    forn(i, chi[u].size()){
        pii p = chi[u][i];
        int v = p.first;
        ll c = p.second;
        if (i < chi[u].size() - 1){
            b2[v] = gcd(b2[v], d2[i+1], dm1, dm2);
        }
        if (i > 0){
            b2[v] = gcd(b2[v], c2[i-1], dm1, dm2);
        }
    }

    for (pii p: chi[u]){
        int v = p.first;
        find_ab2(v);
    }
}

void solve(){
    int n;
    cin >> n >> k;
    int ro;
    forn(i, k){
        int u; cin >> u;
        dis[u] = 1;
        ro = u;
    }
    forn(i, n-1){
        int u, v;
        ll c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    // cout << ro << "\n";

    if (n == 1){
        cout << 0 << "\n";
        return;
    }

    rt(ro);
    find_sz(ro);
    find_cst(ro);

    // rep(i, 1, n) cout << sz[i] << " ";
    // cout << "\n";

    // rep(i, 1, n) cout << cst[i] << " ";
    // cout << "\n";

    rep(i, 1, n){
        if (dis[i] == 1 && i != ro){
            sm[ro] += cst[i];
        }
    }

    // cout << gc << "\n";
    // cout << "\n";

    find_sm(ro);
    find_hav(ro);
    find_ab1(ro);
    find_ab2(ro);

    // cout << "\n";

    // rep(i, 1, n){
    //     cout << i << " " << a1[i] << " " << b1[i] << "\n";
    // }

    // cout << "\n";
    // rep(i, 1, n){
    //     cout << i << " " << a2[i] << " " << b2[i] << "\n";
    // } 

    vector<ll> g(n+1, 0);
    rep(i, 1, n){
        g[i] = gcd(a1[i], b1[i], dm1, dm2);
        g[i] = gcd(g[i], a2[i], dm1, dm2);
        g[i] = gcd(g[i], b2[i], dm1, dm2);
    }

    // rep(i, 1, n) cout << g[i] << " ";
    // cout << "\n";

    ll ans;
    rep(i, 1, n) if (sm[i] == 0){
        cout << 0 << "\n";
        return;
    }
    rep(i, 1, n) if (g[i] != 0) ans = sm[i] / g[i];
    rep(i, 1, n) if (g[i] != 0) ans = min(ans, sm[i] / g[i]);
    cout << ans * 2 << "\n";
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