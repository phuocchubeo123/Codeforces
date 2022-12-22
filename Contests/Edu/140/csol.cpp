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
    int n; cin >> n;
    vector<vi> a(n+1, vi(n+1, 0));
    rep(i, 1, n){
        rep(j, i, n){
            cin >> a[i][j];
        }
    }

    vi adj(n+1);
    rep(i, 1, n) adj[i] = i;
    rep(i, 1, n){
        int max_same = i;
        rep(j, i, n){
            if (a[i][j] == 1) max_same = max(max_same, j);
        }
        rep(j, i, max_same-1){
            adj[j] = j+1;
        }
    }

    vi c(n+1);
    c[n] = 1;

    per(i, n-1, 1){
        if (adj[i] == i){
            c[i] = c[i+1] + 1;
            continue;
        }

        adj[i] = adj[i+1];
        c[i] = c[i+1];
    }

    per(i, n, 1) c[i] = c[1] + 1 - c[i];
    // rep(i, 1, n) cout << c[i] << " ";
    // cout << "\n";

    vi dif(n+1, n+1);
    rep(i, 1, n){
        rep(j, i, n){
            if (a[i][j] == 2){
                if (j <= adj[i]){
                    cout << 0;
                    return;
                }
                // cout << i << " " << c[i] << " " << j << " " << c[j] << "\n";
                dif[c[i]] = min(dif[c[i]], c[j]);
            }
        }
        rep(j, 1, i) dif[c[j]] = min(dif[c[j]], dif[c[i]]);
    }

    // rep(i, 1, c[1]) cout << dif[i] << " ";
    // cout << "\n";

    vector<vector<mint>> dp(n+1, vector<mint>(2, 0));
    dp[c[n]][0] = mint(1); dp[c[n]][1] = mint(1);
    per(i, c[n]-1, 1){
        if (dif[i] == n+1){
            dp[i][0] += dp[i+1][0] + dp[i+1][1];
            dp[i][1] += dp[i+1][0] + dp[i+1][1];
            continue;
        }

        rep(j, i+1, dif[i]){
            dp[i][0] += dp[j][1];
            dp[i][1] += dp[j][0];
        }
        continue;
    }

    // rep(i, 1, c[n]){
    //     cout << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
    // }

    cout << dp[1][0] + dp[1][1];
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