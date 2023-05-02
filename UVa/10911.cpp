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

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int n;

void solve(){
    vector<double> x(2 * n), y(2 * n);
    forn(i, 2 * n){
        string s; cin >> s;
        cin >> x[i] >> y[i];
    }

    double tot;
    forn(i, 2 * n) tot += dist(x[i], y[i], 0, 0);
    vector<double> dp(1 << (2 * n), tot);
    for (int mask = 0; mask < (1 << (2 * n)); mask++){
        int N = 0;
        for (int bit = 0; bit < (2 * n); bit++) if ((mask >> bit) & 1) N++;
        if (N == 0) dp[mask] = 0;
        if (N & 1) continue;
        // for (int bit = 0; bit < (2 * n); bit++) cout << ((mask >> bit) & 1);
        int p1;
        for (int bit = 0; bit < (2 * n); bit++) if ((mask >> bit) & 1){ p1 = bit; break;}
        // cout << " " << p1 << "\n";
        int mask2 = mask ^ (1 << p1);
        for (int bit = 0; bit < (2 * n); bit++) if ((mask >> bit) & 1){
            if (bit == p1) continue;
            dp[mask] = min(dp[mask], dp[mask2 ^ (1 << bit)] + dist(x[p1], y[p1], x[bit], y[bit]));
            // cout << dp[mask] << " ";
        }
        // cout << "\n";
    }

    cout << fixed;
    cout << setprecision(2) << dp[(1 << (2 * n)) - 1] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    string S;
    while (true){
        cin >> n;
        if (n == 0) break;
        cout << "Case " << T << ": ";
        solve();
        T++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}