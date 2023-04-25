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
const int prm = sqrt(1e9) + 5;

vi is_prime(prm);
vi prime;

void sieve(){
    for (int i = 0; i < prm; i++) is_prime[i] = 1;
    is_prime[0] = 0;
    is_prime[1] = 0;
    is_prime[2] = 1;
    for (int i = 2; i < prm; i++){
        if (is_prime[i]){
            for (int j = 2; j * i < prm; j++) is_prime[i * j] = 0;
        }
    }

    int cnt = 0;
    for (int i = 0; i < prm; i++) if (is_prime[i] == 1) prime.push_back(i);
}

void solve(){
    int n; cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];

    for (auto x: prime){
        int cnt = 0;
        forn(i, n){
            if (a[i] % x == 0){
                cnt++;
                if (cnt == 2){
                    cout << "YES\n";
                    return;
                }
                while (a[i] % x == 0) a[i] /= x;
            }
        }
    }

    sort(all(a));
    forn(i, n-1){
        if (a[i] == a[i+1] && a[i] > 1){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    sieve();
    while(T--){
        solve();
    }
}