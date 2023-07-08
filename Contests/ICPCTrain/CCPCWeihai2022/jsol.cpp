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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    vector<pair<int, int>> xy(k);
    forn(i, k) cin >> xy[i].first >> xy[i].second;
    xy.push_back({-1, 0});

    sort(all(xy));

    map<int, int> con;
    forn(i, k+1) con[xy[i].first] = xy[i].second;

    set<int> beg;
    forn(i, k+1){
        if (xy[i].second == 0) beg.insert(xy[i].first);
    }

    map<int, int> cnt;
    sort(all(a));

    ll ans = 0;
    int pt = 0;
    int cc = 0;
    while (true){
        if (pt == a.size()) break;
        int x = a[pt];
        auto it = beg.upper_bound(x);
        it--;
        int y = *it;

        // cout << pt << " " << y << "\n";
        // cout.flush();
        // cc++;
        // if (cc == 15) break;

        if (cnt[y] == con[y]){
            if (con[y+1] > 0){
                y++;
                beg.insert(y);
            }
            else{
                ans += 1ll * (x - y - 1);
                pt++;
            }
            continue;
        }

        cnt[y]++;
        ans += 1ll * (x - y);
        pt++;

    }

    // cout << "ans: " << ans << "\n";
    // cout << "\n";
    if (ans % 2 == 0){
        cout << "FuuFuu\n";
    }
    else cout << "Pico\n";
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