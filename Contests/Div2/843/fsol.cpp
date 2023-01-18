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

const int maxn = 1e3;
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

int get_ans(int n){
    int a = sqrt(n);
    if (a * a == n) return a + a;
    if (a * (a + 1) >= n) return 2 * a + 1;
    return 2 * a + 2;
}

void solve1(){
    int n; cin >> n;
    int a = sqrt(n);
    if (get_ans(n) == 2 * a){
        cout << a << " " << a << "\n";
        forn(i, a){ forn(j, a) cout << '#'; cout << "\n";}
        return;
    }

    if (get_ans(n) == 2 * a + 1){
        cout << a << " " << a + 1 << "\n";
        int rem = a * (a + 1) - n;
        forn(i, rem){
            forn(j, a) cout << '#';
            cout << ".\n";
        }
        rep(i, rem, a-1){
            forn(j, a+1) cout << '#';
            cout << "\n";
        }
        return;
    }

    if (get_ans(n) == 2 * a + 2){
        cout << a+1 << " " << a+1 << "\n";
        int rem = (a + 1) * (a + 1) - n;
        forn(i, rem){
            forn(j, a) cout << '#';
            cout << ".\n";
        }
        rep(i, rem, a){
            forn(j, a+1) cout << "#";
            cout << '\n';
        }
    }
}

vector<mint> f(maxn, mint(0)), g(maxn, mint(0));
void precal(){
    rep(i, 1, maxn-1) f[i] = mint(1ll);
    forn(i, maxn) g[i] += f[i];
    f[0] = 1;
    rep(i, 2, maxn-1){
        vector<mint> b(maxn, mint(0));
        for (int j = 1; j * i < maxn; j++){
            for (int k = 0; k + i * j < maxn; k++){
                b[k + j * i] += f[k];
            }
        }
        forn(j, maxn) g[j] += b[j];
        forn(j, maxn) b[j] += f[j];
        f = b;
    }

    g[0] = mint(1);
    // forn(i, 15) cout << g[i] << " ";
    // cout << "\n";

    vector<mint> b(maxn, mint(0));
    forn(i, maxn){
        for (int j = 0; j + i < maxn; j++){
            b[i+j] += (g[i] * g[j]);
            // if (i + j == 2) cout << b[i+j] << " " << g[i] << " " << g[j] << "\n";
        }
    }
    g = b;

    // forn(i, 15) cout << g[i] << " ";
    // cout << "\n";

    forn(i, maxn) b[i] = mint(0);
    forn(i, maxn){
        for (int j = 0; j + i < maxn; j++){
            b[i+j] += g[i] * g[j];
        }
    }
    g = b;

    // forn(i, 15) cout << g[i] << " ";
    // cout << "\n";
}

void solve2(){
    int n; cin >> n;
    int a = sqrt(n), b = get_ans(n) - a;
    if (b == a + 2){ b--; a++;}
    cout << (a + b) * 2 << " ";
    mint ans(0);
    while (a * b >= n){
        // cout << a << " " << b << "\n";
        if (a != b) ans += 2 * g[a * b - n];
        else ans += g[a * b - n];
        a--; b++;
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    int u; cin >> u;
    if (u == 2){ cin >> MOD; precal();}
    while(T--){
        if (u == 1) solve1();
        if (u == 2) solve2();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}