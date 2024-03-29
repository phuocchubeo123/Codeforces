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
    int n, m, d; cin >> n >> m >> d;
    vi p(n+1); rep(i, 1, n) cin >> p[i];
    vi pos(n+1); rep(i, 1, n) pos[p[i]] = i;
    vi a(m); forn(i, m) cin >> a[i];

    int ans = n;
    forn(i, m-1){
        int p1 = pos[a[i]], p2 = pos[a[i+1]];
        if (p2 < p1){ cout << 0 << "\n"; return;}
        if (p2 > p1 + d){ cout << 0 << "\n"; return;}
        int x1 = p2 - p1;
        if (d >= n-1){ ans = min(ans, x1); continue;}
        int x2 = p1 + d - p2 + 1;
        ans = min(ans, min(x1, x2));
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