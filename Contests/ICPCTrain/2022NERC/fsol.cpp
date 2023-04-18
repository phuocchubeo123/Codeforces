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
    double k; cin >> k;
    vector<pair<double, pii>> chem;
    forn(i, n){
        double x, c, w; cin >> x >> c >> w;
        chem.push_back({x / 100, {c, w}});
    }

    sort(all(chem));
    vector<double> dp(n);

    for (int i = n - 1; i >= 0; i--){
        dp[i] = -chem[i].second.first;
        for (int j = i + 1; j < n; j++){
            double first_part = (chem[i].second.second + chem[j].second.second) * (chem[j].first - chem[i].first) / 2;
            dp[i] = max(dp[i], -chem[i].second.first + k * first_part + dp[j]);
        }
        // cout << dp[i] << " ";
    }

    // cout << "\n";

    double mx = 0;
    forn(i, n) mx = max(mx, dp[i]);
    cout << fixed << setprecision(9) << mx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}