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
    vector<ll> a(3*n);
    forn(i, 3*n) cin >> a[i];

    priority_queue<ll> pq;

    ll tot = 0;
    forn(i, n){
        pq.push(-a[i]);
        tot += a[i];
    }

    vector<ll> l(3*n);
    l[n-1] = tot;

    rep(i, n, 2*n-1){
        pq.push(-a[i]);
        ll x = pq.top();
        pq.pop();
        tot += a[i] + x;
        l[i] = tot;
    }

    vector<ll> r(3*n);
    while (!pq.empty()) pq.pop();

    tot = 0;
    per(i, 3*n-1, 2*n){
        pq.push(a[i]);
        tot += a[i];
    }
    r[2*n] = tot;

    per(i, 2*n-1, n){
        pq.push(a[i]);
        ll x = pq.top();
        pq.pop();
        tot += a[i] - x;
        r[i] = tot;
    }

    ll ans = - 3e14;
    rep(i, n-1, 2*n-1){
        ans = max(ans, l[i] - r[i+1]);
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