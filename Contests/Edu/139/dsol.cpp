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

const int maxn = 3170;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vi is_prime(maxn, 1);
vi prime;

void find_prime(){
    is_prime[0] = 0; is_prime[1] = 0;
    for (int i = 2; i < maxn; i++){
        for (int j = 2; j * i < maxn; j++){
            is_prime[i * j] = 0;
        }
    }

    for (int i = 0; i < maxn; i++) if (is_prime[i] == 1) prime.push_back(i);
}

void solve(){
    find_prime();// find_divisors();
    int n; cin >> n;
    vector<int> x(n), y(n);
    forn(i, n) cin >> x[i] >> y[i];

    // d | x + i and d | y + i then d | x-y
    // find the smallest i such that gcd(x+i, x-y) > 1

    forn(i, n){
        // cout << x[i] << " " << y[i] << "\n";
        int dif = y[i] - x[i];
        int ans = 1e8;
        for (int p: prime){
            if (dif % p == 0){
                while (dif % p == 0) dif = dif / p;
                if (x[i] % p == 0) ans = 0;
                else ans = min(ans, p - x[i] % p);
            }
        }

        if (dif > 1){
            if (x[i] % dif == 0) ans = 0;
            else ans = min(ans, dif - x[i] % dif);
        }
        if (ans == 1e8) cout << -1 << "\n";
        else cout << ans << "\n";
    }
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