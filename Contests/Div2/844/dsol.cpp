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

bool is_sq(ll x){
    ll y = sqrt(x);
    return y * y == x;
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n+1); rep(i, 1, n) cin >> a[i];
    int ans = 1;
    rep(i, 1, n){
        rep(j, i+1, n){
            ll z = a[j] - a[i];
            for (ll x = 1; x * x <= z; x++){
                int ans2 = 0;
                if (z % x != 0) continue;
                ll y = z / x;
                if ((x + y) & 1) continue;
                ll u = (x + y) / 2, v = (y - x) / 2;
                rep(l, 1, n){
                    if (is_sq(u * u - a[j] + a[l])) ans2++;
                }
                // cout << i << " " << v << " " << j << " " << u << " " << ans2 << "\n";
                // cout << u * u - v * v << " " << z << "\n";
                if (u * u >= a[j]) ans = max(ans, ans2);
            }
        }
    }
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