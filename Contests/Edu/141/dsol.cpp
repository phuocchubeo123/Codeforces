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

const int maxn = 300 * 300;
const ll MOD = 998244353;
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n; cin >> n;
    vi a(n); forn(i, n) cin >> a[i];
    // if b[n-1] = x, then b[n-2] = a[i] - b[n-1] or a[i] + b[n-1]
    // a[2] + a[1] or a[2] - a[1]
    // a[3] - a[2] - a[1]
    // a[3] - a[2] + a[1]
    // a[3] + a[2] + a[1]
    // a[3] + a[2] - a[1]

    // a[2] - a[1]
    // a[3] - a[2] - a[1]

    vector<vector<ll>> cnt(n, vector<ll>(2 * maxn + 1, 0));
    cnt[1][a[1] + maxn] = 1;
    rep(i, 2, n-1){
        cnt[i][a[i] + maxn] = cnt[i-1][maxn];
        rep(j, -maxn, maxn){
            if (j == 0) continue;
            if (j + a[i] <= maxn) (cnt[i][j + a[i] + maxn] += cnt[i-1][j + maxn]) %= MOD;
            if (j - a[i] >= -maxn) (cnt[i][j - a[i] + maxn] += cnt[i-1][j + maxn]) %= MOD;
        }
    }

    ll ans = 0;
    // forn(i, n){
    //     rep(j, -4, 4) cout << cnt[i][j + maxn] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    forn(j, 2 * maxn + 1) (ans += cnt[n-1][j]) %= MOD;
    cout << ans << "\n";
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