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

vi lg10(maxn);

void solve(){
    // log10
    lg10[0] = 0;
    rep(i, 1, maxn-1) lg10[i] = lg10[i/10] + 1;

    vector<poly<mint>> res(30);
    forn(i, 2) res[1].a.push_back(mint(0));
    res[1].a[1].val = 1;

    rep(i, 2, 21){
        // add 
        rep(j, 1, i/2){
            res[i] += res[j] * res[i-j];
        }
        
        for (int k = 0; k < res[i].a.size(); k++){
            if (res[i].a[k].val > 0) res[i].a[k].val = 1;
        }

        while (res[i].a.size() > maxn) res[i].a.pop_back();

        for (int k = 0; k < res[i].a.size(); k++){
            if (res[i].a[k].val > 0) res[i].a[k].val = 1;
        }
        res[i].removeZero();

        // multiply
        rep(j, 1, i/2){
            // cout << i << " " << j << "\n";
            for (int k = 1; k < res[j].a.size(); k++){
                for (int l = 1; l < res[i-j].a.size() && k * l < maxn; l++){
                    // cout << i << " " << j << " " << k << " " << l << "\n";
                    if (res[j].a[k].val > 0 && res[i-j].a[l].val > 0){
                        if (res[i].a.size() < k * l + 1) res[i].a.resize(k*l + 1);
                        res[i].a[k * l].val += 1;
                    }
                }
            }
        }
        for (int k = 0; k < res[i].a.size(); k++){
            if (res[i].a[k].val > 0) res[i].a[k].val = 1;
        }

        while (res[i].a.size() > maxn) res[i].a.pop_back();

        // concatenate
        rep(j, 1, i-1){
            for (int k = 1; k < res[j].a.size(); k++){
                for (int l = 1; l < res[i-j].a.size() && lg10[k] + lg10[l] <= 5; l++){
                    if (res[j].a[k].val > 0 && res[i-j].a[l].val > 0){
                        if (res[i].a.size() < k * pow(10, lg10[l]) + l + 1) res[i].a.resize(k * pow(10, lg10[l]) + l + 1);
                        res[i].a[k * pow(10, lg10[l]) + l].val += 1;
                    }
                }
            }
        }

        for (int k = 0; k < res[i].a.size(); k++){
            if (res[i].a[k].val > 0) res[i].a[k].val = 1;
        }
        while (res[i].a.size() > maxn) res[i].a.pop_back();
    }

    int n; cin >> n;
    vi cnt(maxn, 0);
    int done = 0;
    rep(j, 1, 29){
        forn(i, res[j].a.size()) if (res[j].a[i].val > 0 && cnt[i] == 0){
            done++;
            cnt[i] = j;
            // if (j < 6) cout << i << " ";
        }
        // cout << "\n";
    }

    // cout << "vi ans = {";
    // forn(i, maxn) cout << cnt[i] << ", ";
    // cout << "0};";

    cout << cnt[n] << "\n";

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