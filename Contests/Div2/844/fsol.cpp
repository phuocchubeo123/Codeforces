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

const int maxn = 505;
const ll MOD = 998244353;
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

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

ll s[maxn][maxn], tp[maxn][maxn], tq[maxn][maxn], t[maxn][maxn], f[maxn][maxn], g[maxn][maxn];

ll inv_mod[2 * maxn];
void calInverse(){
    for (int i = 1; i < 2 * maxn; i++) inv_mod[i] = inverse(mint(i)).val;
}

void solve(){
    calInverse();
    int n; cin >> n;
    ll p; cin >> p;
    p = (mint(p) / 10000ll).val;
    ll q = (1 - p + MOD) % MOD;

    s[0][0] = 1;
    s[1][0] = (mint(1) / 2).val;
    s[0][1] = (mint(1) / 2).val;

    rep(i, 2, n) s[i][0] = s[i-1][0] * (2 * i - 1) % MOD * inv_mod[2 * i] % MOD;
    rep(j, 2, n) s[0][j] = (((s[0][j-1] * (2 * j - 1)) % MOD) * inv_mod[2 * j]) % MOD;
    rep(i, 1, n) rep(j, 1, n){
        s[i][j] = (s[i-1][j] * (2 * i - 1) % MOD * inv_mod[2 * i + 2 * j] % MOD + s[i][j-1] * (2 * j - 1) % MOD * inv_mod[2 * i + 2 * j] % MOD) % MOD;
    }


    t[0][0] = 1;
    t[1][0] = (mint(2) / 3).val;
    t[0][1] = (mint(1) / 3).val;
    rep(i, 2, n) t[i][0] = t[i-1][0] * (2 * i) % MOD * inv_mod[2 * i + 1] % MOD;   
    rep(j, 2, n) t[0][j] = t[0][j-1] * (2 * j - 1) % MOD * inv_mod[2 * j + 1] % MOD;
    rep(i, 1, n) rep(j, 1, n){
        t[i][j] = (t[i-1][j] * (2 * i) % MOD * inv_mod[2 * i + 2 * j + 1] % MOD + t[i][j-1] * (2 * j - 1) % MOD * inv_mod[2 * i + 2 * j + 1] % MOD) % MOD;
    }

    rep(i, 0, n) rep(j, 0, n) tp[i][j] = t[i][j] * p % MOD;
    rep(i, 0, n) rep(j, 0, n) tq[i][j] = t[i][j] * q % MOD;


    f[0][0] = 1;
    g[0][0] = 1;

    rep(j, 1, n){
        f[0][j] = 1;
        g[0][j] = 1;
    }

    rep(i, 1, n){
        rep(k, 0, i-1) f[i][0] += tp[k][i-1-k] * g[k][0] % MOD * f[i-1-k][1] % MOD;
        f[i][0] %= MOD;
        rep(k, 0, i) g[i][0] += s[k][i-k] * f[k][0] % MOD * f[i-k][0] % MOD;
        g[i][0] %= MOD;

        rep(j, 1, n){
            rep(k, 0, i-1) f[i][j] = f[i][j] + tq[k][i-1-k] * g[k][j] % MOD * f[i-1-k][j-1] % MOD + tp[k][i-1-k] * g[k][j] % MOD * f[i-1-k][j+1] % MOD;
            f[i][j] %= MOD;
        }
        rep(j, 1, n){
            rep(k, 0, i) g[i][j] += s[k][i-k] * f[k][j] % MOD * f[i-k][j] % MOD;
            g[i][j] %= MOD;
        }
    }

    // rep(i, 1, n) cout << f[i][0] << " ";
    // cout << "\n";

    cout << f[n][0] << "\n";
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