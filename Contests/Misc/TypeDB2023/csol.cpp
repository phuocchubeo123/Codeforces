#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef complex<double> cd;
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

void solve(){
    int n; cin >> n;
    ll s; cin >> s;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];

    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    vector<ll> x(n), y(n);
    forn(i, n){
        if (a[i] < s){ x[i] = a[i]; y[i] = 0;}
        else{ x[i] = s; y[i] = a[i] - s;}
    }
    dp[1][0] = x[1] * a[0];
    dp[1][1] = y[1] * a[0];

    rep(i, 2, n-2){
        dp[i][0] = min(dp[i-1][0] + y[i-1] * x[i], dp[i-1][1] + x[i-1] * x[i]);
        // cout << dp[i-1][0] << " " << y[i-1] << " " << dp[i-1][0] + y[i-1] * x[i] << "\n";
        dp[i][1] = min(dp[i-1][0] + y[i-1] * y[i], dp[i-1][1] + x[i-1] * y[i]);
    }
    // cout << "\n";
    ll ans = min(dp[n-2][0] + y[n-2] * a[n-1], dp[n-2][1] + x[n-2] * a[n-1]);
    // cout << dp[n-2][0] << " " << y[n-2] * a[n-1] << "\n";
    // cout << dp[n-2][1] + x[n-2] * a[n-1] << "\n";

    // forn(i, n) cout << dp[i][0] << " ";
    // cout << "\n";
    // forn(i, n) cout << dp[i][1] << " ";
    // cout << "\n";
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}