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
    vector<ll> p(2 * n);
    forn(i, 2*n) cin >> p[i];
    if (n == 1){
        cout << abs(p[1] - p[0]) << "\n";
        return;
    }

    if (n == 2){
        // 0 0 0 0
        ll ans = 0;
        forn(i, 2*n) ans += abs(p[i]);

        // -1 -1 -1 2
        ll tot = 0;
        forn(i, 2*n) tot += abs(p[i] + 1);
        forn(i, 2*n){
            ans = min(ans, tot - abs(p[i] + 1) + abs(p[i] - 2));
        }

        // 2 2 2 2 
        tot = 0;
        forn(i, 4) tot += abs(p[i] - 2);
        ans = min(tot, ans);

        cout << ans << "\n";
        return;
    }

    if (n % 2 == 0){
        // 0000000
        ll ans = 0;
        forn(i, 2*n) ans += abs(p[i]);

        ll tot = 0;
        forn(i, 2*n) tot += abs(p[i] + 1);
        // -1 -1 -1 -1 -1 -1 -1 n
        forn(i, 2*n){
            ans = min(ans, tot - abs(p[i] + 1) + abs(p[i] - n));
        }

        cout << ans << "\n";
        return;
    }

    ll ans = 0;
    forn(i, 2*n) ans += abs(p[i]);
    cout << ans << "\n";
    return;
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