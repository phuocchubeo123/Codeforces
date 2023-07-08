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

ll gcd(ll a, ll b){
    if (a == 0) return b;
    if (b == 0) return a;
    if (a > b) return gcd(b, a);
    if (b % a == 0) return a;
    return gcd(b % a, a);
}

void solve(){
    ll x; cin >> x;
    int n; cin >> n;
    ll m = 1;
    while (m < x) m *= 2;

    // cout << "m: " << m << "\n";

    vector<ll> l(n), r(n);
    forn(i, n) cin >> l[i] >> r[i];

    if (x == 1){
        forn(i, n){
            cout << r[i] - l[i] + 1 << "\n";
        }
        return;
    }

    vi can(m, 0);
    for (ll i = 0; i < m; i++){
        if (gcd((i * x) ^ x, x) == 1) can[i] = 1;
    }

    vi pref(m, 0), suf(m, 0);
    pref[0] = can[0];
    for (ll i = 1; i < m; i++){
        pref[i] = pref[i-1] + can[i];
    }

    suf[m-1] = can[m-1];
    for (ll i = m-2; i >= 0; i--){
        suf[i] = suf[i+1] + can[i];
    }

    forn(i, n){
        ll L = l[i] / m;
        ll R = r[i] / m + 1;
        ll ans = (R - L) * pref[m-1];
        // cout << l[i] % m << " " << r[i] % m << "\n";
        if (l[i] % m > 0){
            ans -= pref[l[i] % m - 1];
        }
        if (r[i] % m < m-1){
            ans -= suf[r[i] % m + 1];
        }
        cout << ans << "\n";
    }
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