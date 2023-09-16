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
    int n; cin >> n;
    if (n == 1){
        cout << 1 << "\n";
        return;
    }

    vector<mint> tot(n+2);
    vector<mint> tot2(n+2);
    vector<mint> tot3(n+2);

    tot[1] = mint(0);
    tot2[1] = mint(0);
    tot3[1] = 0;
    
    tot[2] = 0;
    tot2[2] = 0;
    tot3[2] = 0;  

    rep(i, 3, n+1){
        tot[i] = 1ll * mint(i-2);
        tot[i] += tot3[i-3];
        tot2[i] = tot2[i-1] + tot[i];
        tot3[i] = tot3[i-1] + tot2[i];
    }
    
    // rep(i, 1, n) cout << tot[i] << " ";
    // cout << "\n";
    // rep(i, 1, n) cout << tot2[i] << " ";
    // cout << "\n";
    // rep(i, 1, n) cout << tot3[i] << " ";
    // cout << "\n";

    mint ans(0);
    ans += tot2[n-1] * mint(n-1);
    ans += n-1;

    // cout << ans << "\n";

    rep(i, 2, n){
        ans += tot2[n-i] * mint(n-1) * mint(n-1);
        ans += mint(n-1) * mint(n-1);
        // cout << ans << "\n";
    }

    // cout << ans << "\n";

    for (int i = 2; i <= n; i++){
        ans += tot2[n-i] * mint(n-1);
        ans += mint(n-1);
    }


    ans += 1;

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