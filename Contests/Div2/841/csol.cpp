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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n; cin >> n;
    int mx = 4 * n + 5;
    vector<int> a(n); forn(i, n) cin >> a[i];
    vi pre(n); pre[0] = a[0]; rep(i, 1, n-1) pre[i] = pre[i-1] ^ a[i];
    pre.push_back(0);

    // forn(i, n + 1) cout << pre[i] << " ";
    // cout << "\n";
    vi cnt(2 * mx);
    forn(i, n + 1) cnt[pre[i]]++;
    
    ll ans = 0;
    for (int x = 0; x * x < mx; x++){
        forn(i, n + 1){
            ans += 1ll * cnt[(x * x) ^ pre[i]];
            // cout << x * x << " " << pre[i] << " " << ((x * x) ^ pre[i]) << " " << ans << "\n";
        }
    }

    // cout << ans << "\n";
    cout << (1ll * (n + 1) * (n + 1) - ans) / 2  << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}