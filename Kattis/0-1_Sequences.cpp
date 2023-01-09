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
    string s; cin >> s;
    int sz = s.size();
    mint init(0), k(0);
    mint tot0(0);
    forn(i, sz) if (s[i] == '0'){
        init += 1;
        tot0 += (i+1);
    }
    mint tot(0);
    forn(i, sz) if (s[i] == '?'){
        k += 1;
        tot += (1 + i);
    }

    // cerr << "k:\n";
    // cerr << k << " " << init << " " << tot << "\n";

    vector<mint> binom(k.val+1);
    binom[0] = 1;
    rep(i, 1, k.val-1){
        binom[i] = binom[i-1] / mint(i) * mint(k - i);
    }

    // cerr << "binom k-1\n";
    // forn(i, k) cerr << binom[i] << " ";
    // cerr << "\n";

    vector<mint> binom0(k.val+1);
    binom0[0] = 1;
    rep(i, 1, k.val){
        binom0[i] = binom0[i-1] / mint(i) * mint(k - i + 1);
    }

    // cerr << "binom k\n";
    // forn(i, k+1) cerr << binom0[i] << " ";
    // cerr << "\n";
    mint ans(0);
    // if all ? are 1

    ans = tot0 - mint(1ll * init * (init + 1) / 2);

    rep(i, 1, k.val){
        // if there are i 0's
        // each position occurs k-1 choose i-1 times
        // so sum of pos would be tot * (k-1 choose i-1)
        ans += binom[i-1] * tot + binom0[i] * tot0 - binom0[i] * (1ll * i + init) * (1ll * i + init + 1) / 2;
        // cerr << "ans: " << ans << "\n";
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