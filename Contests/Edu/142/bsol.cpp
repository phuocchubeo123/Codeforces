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

void solve(int a1, int a2, int a3, int a4){
    if (a2 > a3){ solve(a1, a3, a2, a4); return;}
    int ans = 0;
    int a = 0, b = 0;
    if (a1 == 0){ cout << 1 << "\n"; return;}
    // first jokes both like
    ans += a1; a += a1; b += a1;
    // jokes only one likes
    ans += 2 * a2;
    // cout << "ans: " << ans << "\n";
    a3 -= a2;
    if (a < a3){ cout << ans + a + 1 << "\n"; return;}
    ans += a3;
    a -= a3;
    b += a3;
    if (a < a4){ cout << ans + a + 1 << "\n"; return;}
    ans += a4;
    cout << ans << "\n"; return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        solve(a1, a2, a3, a4);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}