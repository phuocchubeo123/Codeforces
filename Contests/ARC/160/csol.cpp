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

const int maxn = 4e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    int n; cin >> n;
    vi a(maxn, 0);
    forn(i, n){
        int x; cin >> x;
        a[x]++;
    }

    vi b(maxn, 0);
    rep(i, 1, maxn-1){
        b[i] = (a[i - 1] + b[i-1]) / 2;
    }

    vector<vector<ll>> dp(maxn);
    per(i, maxn-1, 0){
        forn(j, b[i]+1) dp[i].push_back(0);
        if (i == maxn-1){ dp[i][0] = 1; continue;}
        int j = 0;
        while (j <= a[i]){
            (dp[i][0] += dp[i+1][j / 2]) %= MOD;
            j += 2;
        }
        rep(k, 1, b[i]){
            if (j <= a[i] + k){
                dp[i][k] = (dp[i][k-1] + dp[i+1][j/2]) % MOD;
                j += 2; 
            }
            else{
                dp[i][k] = dp[i][k-1]; 
            }
        }
    }

    // forn(i, 6){
    //     for (int x: dp[i]) cout << x << " ";
    //     cout << "\n";
    // }

    cout << dp[0][0] << "\n";
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