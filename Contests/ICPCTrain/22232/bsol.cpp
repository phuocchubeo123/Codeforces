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
    int m; cin >> m;
    vi d(n+1); 
    rep(i, 1, n) cin >> d[i];
    vi a(m+1); rep(i, 1, m) cin >> a[i];

    int l = 1, r = n+1;
    while (l < r){
        int mid = (l + r) / 2;

        vi vis(m+1, 0);
        stack<int> s;
        int done = 0;
        per(i, mid, 1){
            if (d[i] == 0){
                if (s.empty()) continue;
                int x = s.top(); s.pop();
                if ((x-1) > 0) s.push(x-1);
            }
            else{
                if (vis[d[i]] == 1){
                    if (s.empty()) continue;
                    int x = s.top(); s.pop();
                    if ((x-1) > 0) s.push(x-1);
                }
                else{
                    vis[d[i]] = 1;
                    s.push(a[d[i]]);
                    done++;
                }
            }
        }

        if (done == m && s.empty()) r = mid;
        else l = mid + 1;
    }

    if (l == n+1) cout << -1 << "\n";
    else cout << l << "\n";
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