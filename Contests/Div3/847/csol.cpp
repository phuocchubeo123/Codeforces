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
    vvi a(n, vi(n));
    forn(i, n){
        rep(j, 1, n-1) cin >> a[i][j];
    }

    // 1 1 1 0
    // 2 2 1 0
    // 2 2 3 0
    // 3 3 3 0

    // 1 1 1 1 0
    // 2 2 2 1 0
    // 3 3 2 2 0
    // 4 3 3 3 0
    // 4 4 4 4 0

    vi rk(n+1);
    forn(i, n){
        rep(j, 1, n-1) rk[a[i][j]] += j;
    }

    vector<pii> nums;
    rep(i, 1, n) nums.push_back({rk[i], i});
    sort(all(nums));
    forn(i, n){
        cout << nums[i].second << " ";
    }
    cout << "\n";
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