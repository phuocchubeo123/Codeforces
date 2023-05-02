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
    ll c; cin >> c;
    vector<ll> a(n+1); rep(i, 1, n) cin >> a[i];
    vector<pair<ll, int>> b(n+1);
    rep(i, 1, n) b[i] = {a[i], i};
    rep(i, 1, n) b[i].first = a[i] + min(1ll * i, 1ll * (n+1-i));
    sort(b.begin()+1, b.end());
    
    vector<ll> pre(n+1, 0);
    rep(i, 1, n) pre[i] = pre[i-1] + b[i].first;

    // rep(i, 1, n) cout << pre[i] << " ";
    // cout << "\n";

    int ans = 0;
    rep(i, 1, n){
        // cout << i << ":\n";
        int l = 0, r = n;
        while (l < r){
            int m = (l + r + 1) / 2;
            ll tot;
            if (m >= i){
                tot = pre[m] - b[i].first + a[b[i].second] + b[i].second;
            }
            else{
                tot = pre[m] - b[m].first + a[b[i].second]+ b[i].second;
            }
            // cout << l << " " << r << " " << m << " " << tot << "\n";

            if (tot <= c) l = m;
            else r = m - 1;
        }
        ans = max(ans, l);
    }
    cout << ans << "\n"; return;
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