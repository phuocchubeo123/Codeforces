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
    // p1 * 1 + p2 * 1
    // (p1 * p2)

    // a * 1 + a * 1 
    // a * 2

    // p1 * p2 + p1 * p3
    // p1 * p2 * p3 + p1

    int n; cin >> n;
    vi p;
    vi cnt;
    for (int x = 2; x * x <= n; x++){
        if (n % x == 0){ 
            p.push_back(x);
            int c = 0;
            while (n % x == 0){ n /= x; c++;}
            cnt.push_back(c);
        }
    }
    if (n > 1){ p.push_back(n); cnt.push_back(1);}

    // for (int x: p) cout << x << " ";
    // cout << "\n";
    // for (int x: cnt) cout << x << " ";
    // cout << "\n";

    int ans = 0;
    forn(_, 40){
        int a = 1;
        forn(i, p.size()){
            if (cnt[i] > 0){
                a *= p[i];
                cnt[i]--;
            }
        }
        // cout << a << " ";
        ans += (a == 1) ? 0: a;
    }
    // cout << "\n";

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