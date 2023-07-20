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
    int k; cin >> k;
    vi a(n+1); rep(i, 1, n) cin >> a[i];

    vector<vector<bool>> occur(n+1, vector<bool>(k+1, 0));
    occur[1][0] = 1;
    rep(i, 2, n){
        rep(j, 0, k){
            occur[i][j] = occur[i-1][j] | ((j >= a[i-1]) ? occur[i-1][j-a[i-1]] : 0);
        }
    }


    vector<vector<bool>> occur2(n+1, vector<bool>(k+1, 0));
    occur2[n][0] = 1;
    per(i, n-1, 1){
        rep(j, 0, k){
            occur2[i][j] = occur2[i+1][j] | ((j >= a[i+1]) ? occur2[i+1][j-a[i+1]] : 0);
        }
    }


    vvi window(n+1, vi(k+1, 0));
    rep(i, 1, n){
        rep(j, 1, k){
            window[i][j] = window[i][j-1] + occur2[i][j-1] - ((j >= a[i] + 1) ? occur2[i][j-a[i]-1] : 0);
        }
    }

    // rep(i, 1, n){
    //     rep(j, 0, k) cout << window[i][j] << " ";
    //     cout << "\n";
    // }

    int ans = 0;
    rep(i, 1, n){
        bool flag = false;

        ll tot = 0;
        rep(j, 1, n) if (j != i) tot += 1ll * a[j];
        // cout << "tot: " << tot << "\n";
        if (tot < k - a[i]){
            ans++;
            continue;
        }
        if (tot < k){
            continue;
        }

        // cout << i << ":\n";
        rep(j, 0, k){
            if ((occur[i][j] > 0) && (window[i][k-j] > 0)){
                // cout << j << " ";
                flag = true;
            }
        }
        // cout << '\n';

        if (!flag) ans++;
    }

    cout << ans << "\n";
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