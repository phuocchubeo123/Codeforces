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
    vi a(n); forn(i, n) cin >> a[i];

    vector<ll> dp(n);
    ll n1 = 0;
    ll n2 = 0;
    ll n3 = 0;
    ll n11 = 0;
    ll n12 = 0;
    ll n13 = 0;
    ll n21 = 0;
    ll n22 = 0;
    ll n23 = 0;
    ll n31 = 0;
    ll n32 = 0;
    ll n33 = 0;
    ll n0 = 0;

    ll tot = 0;
    forn(i, n){
        if (a[i] == 0){
            n0 += 1;
            // tot += ll (i + 1);
            // continue;
        }
        else if (a[i] == 3){
            n3 = n1 + n2 + n3 + 1 + n0;
            n1 = 0;
            n2 = 0;
            n0 = 0;
            n31 = n11 + n21 + n31;
            n11 = 0;
            n21 = ll (0);
            n32 = n12 + n22 + n32;
            n12 = ll (0);
            n22 = ll (0);
            n33 = n13 + n23 + n33;
            n13 = ll (0);
            n23 = ll (0);
        }
        else if (a[i] == 2){
            n2 = n3 + n2 + n0 + ll (1);
            n3 = ll (0);
            n0 = ll (0);
            n21 = n31 + n21;
            n31 = ll (0);
            n22 = n32 + n22;
            n32 = ll (0);
            n23 = n33 + n23;
            n33 = ll (0);
            n12 = n1 + n12;
            n1 = ll (0);
            n13 = n11 + n13;
            n11 = ll (0);
        }
        else{
            n1 = n3 + n1 + n0 + ll (1);
            n3 = ll (0);
            n0 = ll (0);
            n11 = n31 + n11;
            n31 = ll (0);
            n12 = n32 + n12;
            n32 = ll (0);
            n13 = n33 + n13;
            n33 = ll (0);
            n21 = n2 + n21;
            n2 = ll (0);
            n23 = n22 + n23;
            n22 = ll (0);
        }

        // cout << n1 << " " << n2 << " " << n3 << " " << n11 << " " << n22 << " " << n33 << " ";
        // cout << n21 << " " << n22 << " " << n23 << " " << n31 << " " << n32 << " " << n33 << "\n";
        // cout << n1 + n2 + n3 + ll (2) * (n11 + n12 + n21 + n22 + n31 + n32) + mint(3) * (n13 + n23 + n33) << "\n";
        tot += n1 + n2 + n3 + ll (2) * (n11 + n12 + n21 + n22 + n31 + n32) + ll (3) * (n13 + n23 + n33);
    }

    ll zero(0);
    forn(i, n){
        if (a[i] == 0) tot += ll (i+1) * ll (n-i);
    }

    cout << tot;
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