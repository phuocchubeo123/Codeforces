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
const ll MOD = 1e9 + 7; // 998244353
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

void solve(){
    // f(a, b) = k
    // 1  0
    // 3  0 0  1
    // 9  0 1  3  0  3
    // 27 0 6  9  3  10 0 9
    // 81 0 27 27 19 33 9 

    // 1 0

    // y_n = 1/3 * 3^n
    // x_{n+1} = 3x_n + 1/3 * 3^n
    // z_{n+1} = z_n + 1/9
    // z_1 = 0
    // z_2 = 1/9
    // z_n = 1/9 * (n-1)

    // (n-1)/9 & 1/3

    // y_n = ((n-2)/27 + 1/3) * 3^n
    // z_{n+1} = z_n + (n-2)/81 + 1/9
    // z_2 = 0
    // z_3 = 1/9
    // z_4 = 1/81 + 2/9
    // z_5 = 3/81 + 3/9 = (n-2)c2 / 81 + (n-2) / 9
    // (n-2)c2 / 81 + (n-2) / 9 &  (n-2)/27 + 1/3


    // (n-3)c3 / 729 + 2(n-3)c2 / 81 + (n-3) / 9  &  (n-3)c2 / 243 + 2(n-3)/27 + 1/3

    // n, k
    // (k-1)c0 (n-k)ck * 3^(n-2k) + (k-1)c1 * (n-k)c(k-1) / 9^{k-1} + (k-1)c2 * (n-k)c(k-2) / 9^{k-2}

    // x_{n+1} = 3x_n + (n-2)/27 * 3^n
    // y_{n+1} = y_n + (n-2) / 81
    // y_2 = 0
    // y_3 = 0
    // y_4 = 1/81
    // y_5 = 3/81 = (5-2) choose 2   

    int n, k; cin >> n >> k;

    vector<mint> pow_mod(n+1);
    pow_mod[0] = mint(1);
    rep(i, 1, n) pow_mod[i] = pow_mod[i-1] * mint(3);

    if (k == 0){
        cout << pow_mod[n];
        return;
    }

    vector<mint> c(k), c1(k+1);
    c[0] = mint(1);
    // k-1 c i / k-1 c i-1 = k-i / i
    rep(i, 1, k-1) c[i] = c[i-1] * mint(k-i) / mint(i);

    // n-k choose something
    c1[0] = mint(1);
    rep(i, 1, k){
        if (i <= n-k) c1[i] = c1[i-1] * mint(n-k-i+1) / mint(i);
        else c1[i] = 0;
    }
    // forn(i, k+1) cout << c1[i] << " ";

    mint ans(0);
    forn(i, k){
        mint d;
        if (k - i > n-k) d = mint(0);
        else d = c[i] * c1[k-i] * pow_mod[n-2*(k-i)];
        // cout << d << " ";
        ans += d;
    }

    forn(i, k){
        mint d;
        if (k - i - 1 > n - k) d = mint(0);
        else d = c[i] * c1[k-i-1] * pow_mod[n - 2*(k-i) + 1];
        ans += d;
    }

    cout << ans;
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