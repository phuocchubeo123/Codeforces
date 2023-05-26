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

const ll maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    ll n; cin >> n;
    ll ans = 0, ans2;
    rep(i, 1, n){
        ll x = i;
        ll as = 0;
        while (x > 0){
            ll lo = 1, hi = maxn;
            while (lo < hi){
                ll mi = (lo + hi + 1) / 2;
                // cout << lo << " " << hi << " " << mi << "\n";
                if (mi * mi * mi > x){
                    hi = mi-1;
                }
                else{
                    lo = mi;
                }
            }
            // cout << x << " " << lo << "\n";
            as++;
            x -= lo * lo * lo;
        }
        // cout << "ans: " << as << "\n";
        if (as >= ans){
            ans = as;
            ans2 = i;
        }
    }

    cout << ans << " " << ans2 << "\n";
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