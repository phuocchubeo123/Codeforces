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

void solve(){
    int n; cin >> n;
    vi a(n);
    forn(i, n){
        cin >> a[i];
    }

    vi l1(n), l2(n);
    int last2=n, last1=n, last3=n;

    forn(i, n){
        l1[i] = last1;
        l2[i] = last2;
        if (a[i] == 0) continue;
        else if (a[i] = 3){
            
        }
        else if (a[i] == 2){
            last2 = i;
        }
        else{
            last1 = i;
        }
    }

    // forn(i, n) cout << l1[i] << " ";
    // cout << "\n";

    // if 2 is cut from 2 then not +1
    // 2 3 1 2

    ll ans = 0;

    vector<ll> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++){
        // cout << i << " ";
        if (a[i] == 0){
            dp[i] = dp[i-1] + 1ll * (i + 1);
        }
        
        else if (a[i] == 2){
            if (l2[i] == n){
                // cout << "one"; 
                dp[i] = dp[i-1] + 1ll * (i + 1);
            }
            else{
                // cout << "two";
                dp[i] = dp[i-1] + 1ll * (i - l2[i]);
            }
        }

        else{
            if (l1[i] == n){
                // cout << "three";
                dp[i] = dp[i-1] + 1ll * (i + 1);
            }
            else{
                // cout << "four " << l1[i]; 
                dp[i] = dp[i-1] + 1ll * (i - l1[i]);
            }
        }

        // cout << "\n";
    }

    forn(i, n) cout << dp[i] << " ";
    cout << "\n";
    forn(i, n) ans += dp[i];
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