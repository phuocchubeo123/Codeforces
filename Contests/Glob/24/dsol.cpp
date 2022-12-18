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

const int maxn = 5005;
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

ll MOD;

template <typename T>
struct mint{
    T val;

    mint(){
        val = 0;
    }

    mint(int x){
        while (x >= MOD) x -= MOD;
        while (x < 0) x += MOD;
        val = x;
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

    mint operator/(const mint& other){
        return mint(val) * mint(other.val).pow(MOD - 2);
    }
};

mint<ll> factor_mod[maxn];

void calFactor(){
    factor_mod[0] = mint<ll>(1);
    for (int i = 1; i < maxn; i++) factor_mod[i] = factor_mod[i - 1] * mint<ll>(i);
}

mint<ll> inv_mod[maxn];

void calInverse(){
    for (int i = 1; i < maxn; i++) inv_mod[i] = mint<ll>(i).pow(MOD - 2);
}

mint<ll> combi[maxn][maxn];

void calCombi(){
    combi[0][0] = 1;
    for (int i = 1; i < maxn; i++){
        combi[i][0] = 1;
        for (int j = 1; j <= i; j++){
            combi[i][j] = combi[i-1][j] + combi[i-1][j-1];
        }
    }
}

void solve(){
    int n; cin >> n;
    cin >> MOD;
    mint<ll> x(5), y(10);
    calFactor();
    calInverse();
    calCombi();
    // cout << inv_mod[5].val << "\n";
    mint<ll> ans(0);
    for (int i = 1; i <= (n-1) / 2; i++){
        for (int j = 0; j <= i-1; j++){
            mint<ll> x = ans, y = mint<ll>(n*1ll) * factor_mod[n-(j+3)] * combi[i-1][j] * mint<ll>((i+1-(n&1)) * 1ll);
            ans = x + y;
        }
        // cout << ans.val << "\n";
    }

    if (n % 2 == 0){
        ans = ans + mint<ll>(n*1ll) * factor_mod[n-2];
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