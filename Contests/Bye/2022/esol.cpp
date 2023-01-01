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

const int maxn = 3e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct mint{
    ll val;
    mint(){
        val = 0;
    }
    mint(ll x){
        val = x;
        if (val < 0) val = MOD - (-val) % MOD;
        if (val >= MOD) val %= MOD;
    }
    mint(int x){
        val = 1ll * x;
        if (val < 0) val = MOD - (-val) % MOD;
        if (val >= MOD) val %= MOD;
    }
    bool operator==(const mint& other){
        return val == other.val;
    }
    mint operator+(const mint& other){
        return mint(val + other.val);
    }
    mint operator-(const mint& other){
        return mint(val - other.val);
    }
    mint operator*(const mint& other){
        return mint((val * 1ll * other.val) % MOD);
    }
    void operator+=(const mint& other){
        val = (mint(val) + other).val;
    }
    mint pow(int y){
        if (y == 0) return mint(1);
        if (y == 1) return mint(val);
        mint x = mint(val).pow(y/2);
        if (y % 2 == 0) return x * x;
        else return x * x * mint(val);
    }
    mint operator/(const mint& other){
        return mint(val) * mint(other.val).pow(MOD - 2);
    }

    friend ostream& operator<<(ostream& os, const mint& x);
};

ostream& operator<<(ostream& cout, const mint& x){
    cout << x.val;
    return cout;
}

vector<vector<pair<int, int>>> adj(maxn);
vi wu(maxn), wv(maxn), btf(maxn);

void dfs(int u, int v, int i){
    // cout << u << " " << v << " " << i << "\n";
    if (u < v){
        if (wv[i] != -1) return;
        wv[i] = 0;
        if (btf[v] == 1) wv[i]++;
        for (auto p: adj[v]){
            int w = p.first, j = p.second;
            if (w == u) continue;
            dfs(v, w, j);
            if (v < w) wv[i] += wv[j];
            else wv[i] += wu[j];
        }
    }
    else{
        if (wu[i] != -1) return;
        wu[i] = 0;
        if (btf[v] == 1) wu[i]++;
        for (auto p: adj[v]){
            int w = p.first, j = p.second;
            if (w == u) continue;
            dfs(v, w, j);
            if (v < w) wu[i] += wv[j];
            else wu[i] += wu[j];
        }
    }
}

void solve(){
    int n, k; cin >> n >> k;
    forn(i, n) btf[i] = 0;
    vi a(k); forn(i, k){ cin >> a[i]; a[i]--; btf[a[i]] = 1;}
    vi u(n), v(n); 
    forn(i, n-1){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        if (u[i] > v[i]){ int tmp = u[i]; u[i] = v[i]; v[i] = tmp;}
    }

    forn(i, n-1){ adj[u[i]].push_back({v[i], i}); adj[v[i]].push_back({u[i], i});}

    forn(i, n-1){ wu[i] = -1; wv[i] = -1;}
    forn(i, n-1){
        dfs(u[i], v[i], i);
        dfs(v[i], u[i], i);
    }

    // forn(i, n-1) cout << wu[i] << " " << wv[i] << "\n";

    vector<mint> p(n, mint(0));
    // cout << "butterflies\n";
    // forn(i, k) cout << a[i] << " ";
    // cout << "\n";
    forn(i, k) p[a[i]] = mint(1);
    // mint x(1);
    // cout << x << "\n";

    // cout << "prob of nodes\n";
    // forn(i, n) cout << p[i] << " ";
    // cout << "\n";

    mint ans(0);
    forn(i, n-1){
        // continue;
        mint P = p[u[i]], Q = p[v[i]], l = mint(wu[i]), r = mint(wv[i]);
        // if both nodes are empty, no fly
        ans += (mint(1) - P) * (mint(1) - Q) * l * r; 
        // if node u is not empty, butterfly can fly from u to v with 1/2 chance
        ans += P * (mint(1) - Q) * (l * r + (l - mint(1)) * (r + mint(1))) / mint(2);
        // if node v is not empty
        ans += (mint(1) - P) * Q * (l * r + (l + mint(1)) * (r - mint(1))) / mint(2);
        // if node u and node v are both not empty, no fly
        ans += P * Q * l * r;

        // update chances
        p[u[i]] = (P + Q) / mint(2);
        p[v[i]] = (P + Q) / mint(2);
    }

    vector<double> p1(n, 0);
    double ans2 = 0;
    forn(i, k) p1[a[i]] = 1;
    // cout << "iterations\n";
    forn(i, n-1){
        continue;
        cout << u[i] << " " << v[i] << "\n";
        double P = p1[u[i]], Q = p1[v[i]], l = (double) wu[i], r = (double)wv[i];

        ans2 += (1 - P) * (1 - Q) * l * r;      
        ans2 += P * (1-Q) * (l * r + (l-1) * (r+1)) / 2;
        ans2 += (1-P) * Q * (l * r + (l+1) * (r-1)) / 2;
        ans2 += P * Q * l * r;

        p1[u[i]] = P * Q + P * (1 - Q) / 2 + (1 - P) * Q / 2;
        p1[v[i]] = P * Q + P * (1 - Q) / 2 + (1 - P) * Q / 2;
        forn(i, n) cout << p1[i] << " ";
        cout << "\n";
        cout << ans2 << "\n";
    }

    // cout << "answer\n";
    cout << ans / mint(k) / mint(k-1) * mint(2);

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