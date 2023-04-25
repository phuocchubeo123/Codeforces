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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n; cin >> n;
    int m; cin >> m;
    vi a(n); forn(i, n) cin >> a[i];
    vi b = a;
    sort(all(b));
    vi pre(n);
    pre[0] = b[0];
    rep(i, 1, n-1) pre[i] = pre[i-1] + b[i];
    vector<pii> nums;
    forn(i, n) nums.push_back({a[i], i});
    sort(all(nums));
    int best = -1;

    // cout << "pre: \n"; 
    // forn(i, n) cout << pre[i] << " ";
    // cout << "\n";

    for (pii p: nums){
        int x = p.first, i = p.second;
        // cout << "best: " << best << "\n";
        // cout << x << " " << i << "\n";

        if (i == 0){
            if (m >= b[0]) best = max(best, i);
            continue;
        }

        if (i == 1){
            if (m >= a[1]) best = max(best, i);
            if (m >= pre[1]) best = max(best, i);
            continue;
        }

        // if win against i+1 th player
        int m2 = m - a[i];
        // need another i - 1 wins
        int need;
        if (b[i-2] > a[i]) need = pre[i-1] - a[i];
        else if (b[i-2] < a[i]) need = pre[i-2];
        else{
            if (b[i-1] > a[i]) need = pre[i-1] - a[i];
            else need = pre[i-2];
        }
        // cout << "need if win: " << need << " " << m2 << "\n";
        if (need <= m2) best = max(best, i);

        // if not win against i+1 th player
        // need i + 1 wins
        // cout << "need if not win: " << pre[i] << "\n";
        if (pre[i] <= m) best = max(best, i);
    }
    cout << n - best << "\n";
}

using namespace std::chrono;

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