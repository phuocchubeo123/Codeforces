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

const int maxn = 2005;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<pair<int, int>> adj[maxn];
vector<int> new_adj[maxn];
vector<int> vis(maxn), can(maxn);
vector<int> bs(maxn);

void can_go(int u){
    if (vis[u] == 1) return;
    vis[u] = 1;

    for (auto p: adj[u]){
        int v = p.first, w = p.second;
        // cout << v << " " << w << "\n";
        // cout.flush();
        can_go(v);
        if (can[v] == 1) can[u] = 1;
    }
}

void set_bst(int u){
    int bst = 10;
    for (auto p: adj[u]){
        int v = p.first, w = p.second;
        if (can[v] == 1) bst = min(bst, w);
    }

    bs[u] = bst;
    for (auto p: adj[u]){
        int v = p.first, w = p.second;
        if (can[v] == 1 && w == bst) new_adj[u].push_back(v);
    }
}

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
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

ll inverse(ll a, ll b){
    ll x, y;
    ll g = gcd(a, b, x, y);
    if (g != 1) return -1;
    else{ x = (x % b + b) % b; return x;}
}

struct mint{
    ll val;
    void normalize(){
        if (val < 0) val = MOD - (-val) % MOD;
        if (val >= MOD) val %= MOD;
    }
    mint(){ val = 0;}
    mint(ll x){ val = 1ll * x; normalize();}
    bool operator==(const mint& other){ return val == other.val;}
    mint operator+=(const mint& other){ (val += other.val) %= MOD; return *this;}
    mint operator+=(const ll& x){ return *this += mint(x);}
    mint operator-=(const mint& other){ ((val -= other.val) += MOD) %= MOD; return *this;}
    mint operator-=(const ll& x){ return *this -= mint(x);}
    mint operator*=(const mint& other){ val *= other.val; normalize(); return *this;}
    mint operator*=(const ll& x){ val *= x; normalize(); return *this;}
    mint operator/=(const mint& other){ val *= inverse(other.val, MOD); normalize(); return *this;}
    mint operator/=(const ll& x){ val *= inverse(x, MOD); normalize(); return *this;}

    friend ostream& operator<<(ostream& os, const mint& x);
};

ostream& operator<<(ostream& cout, const mint& x){ cout << x.val; return cout;}
mint operator+(const mint& x, const mint& y){ return mint(x) += y;}
mint operator+(const mint& x, const ll& y){ return mint(x) += y;}
mint operator+(const ll& x, const mint& y){ return mint(x) += y;}
mint operator-(const mint& x, const mint& y){ return mint(x) -= y;}
mint operator-(const mint& x, const ll& y){ return mint(x) -= y;}
mint operator-(const ll& x, const mint& y){ return mint(x) -= y;}
mint operator*(const mint& x, const mint& y){ return mint(x) *= y;}
mint operator*(const mint& x, const ll& y){ return mint(x) *= y;}
mint operator*(const ll& x, const mint& y){ return mint(x) *= y;}
mint operator/(const mint& x, const mint& y){ return mint(x) /= y;}
mint operator/(const mint& x, const ll& y){ return mint(x) /= y;}
mint operator/(const ll& x, const mint& y){ return mint(x) /= y;}
mint inverse(const mint& x){ return mint(inverse(x.val, MOD));}
mint pow(const mint& x, const int& y){
    if (y == 0) return mint(1);
    mint tmp = pow(x, (y >> 1));
    return (y & 1) ? tmp * tmp *x : tmp * tmp;
}


void solve(){
    int n, m; cin >> n >> m;
    forn(i, n) adj[i].clear();
    forn(i, n) {vis[i] = 0; can[i] = 0;}
    forn(i, n) new_adj[i].clear();
    can[1] = 1;
    vis[1] = 1;


    forn(i, m){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});      
    }

    can_go(0);
    forn(i, n) set_bst(i);

    string ans = "";

    vector<int> crr(n, 0);        
    vector<int> nxt(n, 0);
    crr[0] = 1;

    // forn(u, n) cout << can[u] << " ";
    // cout << "\n";
    // forn(u, n) cout << bs[u] << " ";
    // cout << "\n";

    forn(step, 3*n + 16){
        int bst = 10;
        forn(u, n) nxt[u] = 0;
        forn(u, n){
            if (crr[u] == 1) bst = min(bst, bs[u]);
        }

        ans.push_back('0' + bst);
        forn(u, n){
            if (crr[u] == 1 && bs[u] == bst){
                for (int v: new_adj[u]) nxt[v] = 1;
            }
        }

        forn(u, n) crr[u] = nxt[u];

        if (nxt[1] == 1) break;
    }

    // if (make_pair(n, m) != make_pair(5, 5) && make_pair(n, m) != make_pair(5, 6)){
    //     cout << 1 << "\n";
    //     return;
    // }

    if (ans.size() < 3*n+5){
        mint num(0), den(0);
        den = mint(1);
        for (int i = 0; i < ans.size(); i++){
            num = num * 10 + (ans[i] - '0');
            den = den * 10;
        }
        cout << num / den << "\n";
    }

    else{
        // cout << ans << "\n";
        string ans2 = ans;
        reverse(all(ans2));
        vector<int> z = z_function(ans2);
        // for (int x: z) cout << x << " ";
        // cout << "\n";
        z[0] = -1;
        int period, start;
        for (int i = 0; i < z.size(); i++){
            if (z[i] >= i){
                period = i;
                start = ans.size() - i - z[i];
                break;
            }
        }

        // cout << start << " " << period << "\n";
        mint num1(0), den1(1), num2(0), den2(0);
        for (int i = 0; i < start; i++){
            num1 = num1 * 10 + (ans[i] - '0');
            den1 = den1 * 10;
            // den2 = den2 * 10 + 9;
        }
        for (int i = start; i < start + period; i++){
            num2 = num2 * 10 + (ans[i] - '0');
            den2 = den2 * 10 + 9;
        }
        cout << num1 / den1 + num2 / den2 / den1 << "\n";
        // cout << mint(5) / mint(10) + mint(12) / mint(99) / mint(10) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    int tcase = 0;
    while(T--){
        tcase++;
        cout << "Case #" << tcase << ": ";
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}