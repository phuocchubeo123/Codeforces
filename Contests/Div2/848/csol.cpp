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
    int k; cin >> k;
    string a, b; cin >> a >> b;
    set<char> s;
    forn(i, n) s.insert(a[i]);
    string q;
    for (char c: s) q.push_back(c);
    int m = q.length();

    // cout << "m: " << m << "\n";

    ll mx = 0;
    vi can(26);
    // cout << (1 << m) << "\n";
    for (int mask = 0; mask < (1 << m); mask++){
        forn(i, 26) can[i] = 0;
        string Q;
        for (int bit = 0; bit < m; bit++){
            if ((mask >> bit) & 1){ can[q[bit]-'a'] = 1; Q.push_back(q[bit]);}
        }
        if (Q.length() > k) continue;
        if (Q.length() < min(m, k)) continue;
        string A = a;
        forn(i, n) if (can[A[i]-'a']) A[i] = b[i];
        int r = 0;
        ll ans = 0;
        forn(i, n){
            if (A[i] == b[i]) r++;
            else{ ans += 1ll * r * (r+1) / 2; r = 0;}
        }
        ans += 1ll * r * (r+1) / 2;
        // cout << A << " " << ans << "\n";
        mx = max(ans, mx);
    }

    cout << mx << "\n";
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