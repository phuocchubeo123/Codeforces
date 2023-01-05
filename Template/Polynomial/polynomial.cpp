#include <bits/stdc++.h>
using namespace std;

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

void fft(poly<cd>& f, bool invert) {
    // must use T as complex<double>
    int n = f.a.size();
    if (n == 1)
        return;
    poly<cd> f0, f1;
    for (int i = 0; 2 * i < n; i++) {
        f0.a.push_back(f.a[2*i]);
        f1.a.push_back(f.a[2*i+1]);
    }
    fft(f0, invert);
    fft(f1, invert);
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        f.a[i] = f0.a[i] + w * f1.a[i];
        f.a[i + n/2] = f0.a[i] - w * f1.a[i];
        if (invert) {
            f.a[i] /= 2;
            f.a[i + n/2] /= 2;
        }
        w *= wn;
    }
}    
poly<ll> operator* (const poly<ll>& a, const poly<ll>& b){
    poly<cd> fa(vector<cd>(a.a.begin(), a.a.end())), fb(vector<cd>(b.a.begin(), b.a.end()));
    int n = 1;
    while (n < fa.a.size() + fb.a.size()) n <<= 1;
    fa.a.resize(n);
    fb.a.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa.a[i] *= fb.a[i];
    fft(fa, true);

    poly<ll> result;
    for (int i = 0; i < n; i++)
        result.a.push_back(round(fa.a[i].real()));
    result.removeZero();
    return result;
}

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

template <typename T> ostream& operator<<(ostream& cout, const poly<T>& f){ for (T x: f.a) cout << x << " "; return cout;}
template <typename T> poly<T> pow(const poly<T>& f, const int& k){
    if (k == 0) return poly<T>({T(1)});
    poly<T> res = pow(f, (k >> 1));
    return (k & 1) ? res * res * f : res * res;
}
template <typename T> poly<T> operator*(const poly<T>& f, const T& k){ return poly<T>(f) *= k;}
template <typename T> T BernoulliNumber(int n){
    T B(0);
    forn(k, n+1){
        forn(v, k+1){
            B += pow(T(-1), v) * binom[k][v] * pow(T(v+1), n) / T(k+1);
        }
    }
    return B;
}

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


int main(){
    vi t{5,3,2,1};
    poly<int> pl(t);
    cout << pl << "\n";
    poly<int> pl2(t);
    pl += pl2;
    cout << pl << "\n";
    cout << pl + pl2 << "\n";
    cout << pl << "\n";
    cout << -pl << "\n";
    cout << pl.mul_xk(5) << "\n";

    poly<ll> a({1, 2});
    poly<ll> b({3, 4});
    cout << a * b << "\n";

    poly<mint> aa(vector<mint>(a.a.begin(), a.a.end()));    
    poly<mint> bb(vector<mint>(b.a.begin(), b.a.end()));    
    cout << aa * bb << "\n";

    cout << pow(mint(3), 3) << "\n";
}