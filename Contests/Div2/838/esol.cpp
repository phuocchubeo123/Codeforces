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
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 5e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct mint{
    ll val;

    mint(){
        val = 0;
    }

    mint(int x){
        val = 1ll * x;
        if (val < 0) val = MOD - (-val) % MOD;
        if (val >= MOD) val %= MOD;
    }

    mint(ll x){
        val = x;
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

    mint pow(int y){
        mint z(1);
        mint x(val);
        while (y > 0){
            if (y % 2 == 1) z = z * x;
            x = x * x;
            y /= 2;
        }
        return z;
    }

    void operator+=(const mint& other){
        val = (mint(val) + other).val;
    }

    mint operator/(const mint& other){
        return mint(val) * mint(other.val).pow(MOD - 2);
    }
};

void solve(){
    int n; cin >> n;
    if (n % 2 == 1){
        cout << 0;
        return;
    }

    if (n == 2){
        cout << 998244352;
        return;
    }

    if (n == 4){
        cout << 998244343;
        return;
    }

    vector<mint> f(maxn);
    f[0] = mint(0); 
    f[1] = mint(1);
    f[2] = mint(2);
    for (int i = 3; i < maxn; i++){
        f[i] = mint(i).pow(i-2);
    }

    vector<mint> c(maxn);
    c[0] = 1;
    c[1] = n-2;
    for (int i = 2; i < maxn; i++){
        c[i] = c[i-1] * mint(n - i + 1) / mint(i);
    }

    mint ans(0);
    for (int i = 1; i <= n - 1; i++){
        mint adding = mint(-1).pow(i % 2) * mint(i) * mint(n-i) * f[i] * f[n-i] * c[i-1];
        cout << adding.val << "\n";
        ans += adding;
    }

    cout << ans.val;
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