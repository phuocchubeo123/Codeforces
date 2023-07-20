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
    ll W; cin >> W;
    vector<ll> w(n+1);
    vector<ll> v(n+1);
    rep(i, 1, n) cin >> w[i] >> v[i];
    vector<ll> a(n+1);
    a[1] = 0;
    rep(i, 1, n-1) a[i+1] = w[i+1] - w[1];

    // rep(i,1,n) cout << a[i] << "\n";
    // cout << "\n\n";
    vector<vector<vector<ll>>> knapsack(n+1, vector<vector<ll>>(n+1, vector<ll>(3 * (n+1), 0)));

    rep(i, 1, n){
        rep(j, 1, n){
            forn(k, 3 * (n+1)){
                if (k >= a[j]) knapsack[i][j][k] = max(knapsack[i][j][k], knapsack[i-1][j-1][k-a[j]] + v[j]);
                knapsack[i][j][k] = max(knapsack[i][j][k], knapsack[i][j-1][k]);
            }
        }
    }

    // rep(i, 1, n){
    //     rep(j, 1, n){
    //         forn(k, 3 * (n+1)){
    //             cout << knapsack[i][j][k] << " ";
    //         }
    //         cout << "\n";
    //     }

    //     cout << "\n";
    // }

    ll ans = 0;
    rep(i, 1, n){
        forn(k, 3 * (n+1)){
            if (1ll * i * w[1] + k <= W) ans = max(ans, knapsack[i][n][k]);
        }
    }

    cout << ans << "\n";
}

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