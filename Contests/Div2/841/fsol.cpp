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

const int maxn = 1e5 + 5;
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

template <typename T>
struct poly{
    vector<T> a;

    void removeZero(){ while (!a.empty() && a.back() == T(0)) a.pop_back();}

    poly(){}
    poly(T a0){a = {a0}; removeZero();}
    poly(const vector<T> &t){ a = t; removeZero();}

    poly operator-() const{
        poly<T> res = *this;
        for (auto &it: res.a){
            it = -it;
        }
        return res;
    }
    poly operator+=(const poly &t){
        a.resize(max(a.size(), t.a.size()));
        forn(i, a.size()){
            if (i >= t.a.size()) continue;
            a[i] += t.a[i];
        }
        removeZero();
        return *this;
    }
    poly operator+(const poly<T>& t){ return poly(*this) += t;}
    poly operator-=(const poly &t){
        a.resize(max(a.size(), t.a.size()));
        forn(i, a.size()){
            if (i >= t.a.size()) continue;
            a[i] -= t.a[i];
        }
        removeZero();
        return *this;
    }
    poly operator-(const poly<T>& t){ return poly(*this) -= t;}
    poly mul_xk(int k) const{
        auto res = a;
        res.insert(begin(res), k, 0);
        return poly(res);
    }
    poly operator*=(const T& k){ for (auto &it: a) it = it * k; removeZero(); return (*this);}
};

template <typename T> ostream& operator<<(ostream& cout, const poly<T>& f){ for (T x: f.a) cout << x << " "; return cout;}

mint root = pow(mint(3), 119);
mint root_1 = inverse(root);
mint root_pw((1<<23));

void ntt(poly<mint> & f, bool invert) {
    int n = f.a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(f.a[i], f.a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        mint wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw.val; i <<= 1)
            wlen = wlen * wlen;

        for (int i = 0; i < n; i += len) {
            mint w(1);
            for (int j = 0; j < len / 2; j++) {
                mint u = f.a[i+j], v = f.a[i+j+len/2] * w;
                f.a[i+j] = u+v;
                f.a[i+j+len/2] = u-v;
                w = w * wlen;
            }
        }
    }
if (invert) {
        mint n_1 = inverse(mint(n));
        for (mint & x : f.a)
            x = x * n_1;
    }
}
poly<mint> operator* (const poly<mint>& a, const poly<mint>& b){
    poly<mint> fa = a, fb = b;
    int n = 1;
    while (n < fa.a.size() + fb.a.size()) n <<= 1;
    fa.a.resize(n);
    fb.a.resize(n);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; i++)
        fa.a[i] *= fb.a[i];
    ntt(fa, true);

    poly<mint> result;
    for (int i = 0; i < n; i++)
        result.a.push_back(fa.a[i]);
    result.removeZero();
    return result;
}

template <typename T> poly<T> pow(const poly<T>& f, const int& k){
    if (k == 0) return poly<T>({T(1)});
    poly<T> res = pow(f, (k >> 1));
    return (k & 1) ? res * res * f : res * res;
}
template <typename T> poly<T> operator*(const poly<T>& f, const T& k){ return poly<T>(f) *= k;}

vector<vector<mint>> binom(55, vector<mint>(55));

template <typename T> T BernoulliNumber(int n){
    T B(0);
    forn(k, n+1){
        forn(v, k+1){
            B += pow(T(-1), v) * binom[k][v] * pow(T(v+1), n) / T(k+1);
        }
    }
    return B;
}

mint BernoulliNum[55];

template <typename T> poly<T> sumOfKthPower(int k){
    poly<T> f;
    f.a.push_back(T(0));
    per(i, k, 0){
        T tmp = BernoulliNum[i] * binom[k+1][i];
        f.a.push_back(tmp);
    }
    f *= inverse(T(k+1));
    f.removeZero();
    return f;
}


void solve(){
    ll n; cin >> n;
    mint k; cin >> k.val;

    // binomial coefficient
    binom[0][0] = mint(1);
    binom[1][0] = mint(1);
    binom[1][1] = mint(1);
    rep(i, 2, 54){
        binom[i][0] = mint(1);
        rep(j, 1, i) binom[i][j] = binom[i-1][j] + binom[i-1][j-1];
    }

    BernoulliNum[0] = mint(1);
    rep(i, 1, 54) BernoulliNum[i] = BernoulliNumber<mint>(i);

    mint ans(0);
    // If a_i is 1 then it is always good except when the whole sequence is 1
    // rep(i, 1, n-1){
    //     // If 0 occurs i times
    //     ans += binom[n][i] * pow(k-1, n-i);
    // }

    // If a_i is k then there is no chance
    // If a_i is a number x > 1 and x < k
    // Then there are x-1 numbers smaller than x and k-x numbers larger than x

    poly<mint> f({-1, 1}), g({k, -1});
    vector<vector<poly<mint>>> fg(55, vector<poly<mint>> (55));
    forn(i, 55){
        rep(j, i+1, 54-i) fg[i][j] = pow(f, i) * pow(g, j);
    }
    poly<mint> f1({0,1}), g1({k+1,-1});

    poly<mint> h;
    rep(i, 1, n-1){
        rep(j, 0, i-1){
            mint a = binom[i-1][j];
            rep(k, j+1, n-i){
                mint b = binom[n-i][k];
                poly<mint> tmp = fg[j][k] * pow(g1,i-1-j) * pow(f1,n-i-k) * a * b;
                // cout << i << " " << j << " " << k << " " << tmp << "\n";
                h += tmp;
            }
        }
    }

    // i = 1, j = 0, k = 1 
    // left: 1
    // right: (k-x)

    h = h * poly<mint>({0, 1});

    poly<mint> res;
    forn(i, h.a.size()){
        res += sumOfKthPower<mint>(i) * h.a[i];
    }

    forn(i, res.a.size()){
        ans += pow(k, i) * res.a[i];
    }
    cout << ans << "\n";
}

using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}