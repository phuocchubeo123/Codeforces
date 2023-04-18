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

const int maxn = 2e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n, m; cin >> n >> m;
    vi a(n); forn(i, n) cin >> a[i];
    vi cnt(maxn, 0);
    forn(i, n) cnt[a[i]]++;
    // forn(i, n) cout << cnt[i] << " ";
    // cout << "\n";
    vi c(m); forn(i, m) cin >> c[i];
    sort(all(c));
    reverse(all(c));
    int ans = 0;
    forn(i, m){
        int mx = cnt[0], ind = 0;
        forn(j, maxn){
            if (cnt[j] > mx){ mx = cnt[j]; ind = j;}
        }
        // cout << mx << " " << ind << "\n";
        if (mx >= c[i]){
            cnt[ind] -= c[i];
            ans += c[i];
        }
        else{
            ans += cnt[ind];
            cnt[ind] = 0;
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