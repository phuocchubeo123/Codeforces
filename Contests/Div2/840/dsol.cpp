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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
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
        mint z(1);
        mint x(val);
        while (y > 0){
            if (y % 2 == 1) z = z * x;
            x = x * x;
            y /= 2;
        }
        return z;
    }

    mint operator/(const mint& other){
        return mint(val) * mint(other.val).pow(MOD - 2);
    }
};

vector<vector<mint>> c(105, vector<mint>(105));

void prepare(){
    forn(i, 105) c[0][i] = 1;
    rep(i, 1, 104){
        c[i][i] = 1;
        rep(j, i+1, 104){
            c[i][j] = c[i][j-1] + c[i-1][j-1];
        }
    }
}

void solve(){
    int n, i, j, x, y; cin >> n >> i >> j >> x >> y;
    auto valid = [&](int p, int v){
        if (p == i && v != x) return false;
        if (p == j && v != y) return false;
        return true;
    };

    vector<vector<mint>> dp(n+1, vector<mint>(n+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = mint(0);
        }
    }
    for (int i = 2; i <= n-1; i++){
        if (valid(i, n)) dp[i][i] = mint(1);
    }

    for (int len = 2; len <= n; len++){
        int curr = n - len + 1;
        // cout << len << " " << curr << "\n";
        for (int i = 1; i <= n; i++){
            int j = i + len - 1;
            if (j > n) continue;
            if (valid(i, curr)) dp[i][j] = dp[i][j] + dp[i+1][j];
            if (valid(j, curr)) dp[i][j] = dp[i][j] + dp[i][j-1];
        }
    }
    // cout << "\n";

    cout << dp[1][n].val << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    prepare();
    while(T--){
        solve();
    }
}