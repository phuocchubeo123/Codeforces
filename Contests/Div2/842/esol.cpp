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

const int maxn = 3e6 + 5;
ll MOD = 1e9 + 7; // 998244353
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

mint pow_mod[maxn];
void calPowMod(){
    pow_mod[0] = mint(1);
    for (int i = 1; i < maxn; i++) pow_mod[i] = pow_mod[i - 1] * mint(2);
}

mint factor_mod[maxn];
void calFactor(){
    factor_mod[0] = mint(1);
    for (int i = 1; i < maxn; i++) factor_mod[i] = factor_mod[i - 1] * mint(i);
}

mint inv_mod[maxn];
void calInverse(){
    for (int i = 1; i < maxn; i++) inv_mod[i] = inverse(mint(i));
}

void solve(){
    ll n; cin >> n;
    cin >> MOD;
    calFactor();
    // calInverse();

    vector<mint> binom(n + 1);
    binom[0] = mint(1);
    rep(i, 1, n){
        binom[i] = binom[i-1] * mint(n - 1ll * (i - 1)) / mint(1ll * i);
    }
    // forn(i, n+1) cout << binom[i] << " ";
    // cout << "\n";

    auto start = high_resolution_clock::now();
    // only fixed permutation has 0 operation
    mint ans0(1);

    // <=1 operation: if first n is fixed or last n is fixed
    // first fixed + last n fixed - both fixed
    mint ans1 = factor_mod[2 * n] + factor_mod[2 * n] - factor_mod[n];

    // <= 2 operations: first n in first 2n or last n in last 2n
    
    mint a3(0);
    forn(i, n+1){
        a3 += binom[i] * binom[n-i] * factor_mod[n] * factor_mod[2 * n];
        // cout << a3 << " ";
    }
    // cout << "\n";
    mint b3(0);
    forn(i, n+1){
        b3 += binom[i] * binom[n-i] * binom[n-i] * factor_mod[n] * factor_mod[n-i] * factor_mod[n + i];
    }

    mint ans2 = 2 * a3 - b3;

    mint ans = ans0 * 0 + (ans1 - ans0) * 1 + (ans2 - ans1) * 2 + (factor_mod[3 * n] - ans2) * 3;
    // cout << ans0 << " " << ans1 << " " << ans2 << " " << factor_mod[3 * n] << "\n";
    cout << ans << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
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