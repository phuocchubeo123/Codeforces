// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

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
    ll n; cin >> n;
    vector<ll> a(n+1); rep(i, 1, n) cin >> a[i];
    vector<ll> dp(n+1); dp[1] = 0;
    ll mn = a[1];
    rep(i, 2, n){ mn = min(mn, a[i]); dp[i] = min(1ll * i * n, 1ll * (i - 1) * (i - 1) * mn);}
    vector<ll> last(n+5, -1);
    last[a[1]] = 1;
    ll curr;
    ll sq = sqrt(n) + 1;
    vector<int> st;
    st.push_back(1);
    for (int i = 2; i <= n; i++){
        mn = a[i];
        ll ans = dp[i];
        for (int j = i-1; j >= 1 && j >= i - sq; j--){
            mn = min(mn, a[j]);
            ans = min(ans, dp[j] + mn * (i - j) * (i - j));
        }

        ll x = a[i];
        if (x <= sq){
            for (int j = i-1; (j >= 1) && (a[j] > x); j--){
                ans = min(ans, dp[j] + x * (i - j) * (i - j));
            }
        }

        for (ll j = 1; j <= min(a[i], sq); j++){
            if (last[j] == -1) continue;
            ll k = last[j];
            ans = min(ans, dp[k] + j * (i - k) * (i - k));
        }
        
        dp[i] = ans;
        last[a[i]] = i;
    }

    rep(i, 1, n) cout << dp[i] << " ";
}

using namespace std::chrono;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}