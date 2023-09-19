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
    int n, m; cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c; cin >> c;
            grid[i][j] = (c - '0');
        }
    }

    ll ans = 0;

    vector<vector<bool>> vertical(n, vector<bool>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m-1; j++){
            if (grid[i][j] && grid[i][j+1]) vertical[i][j] = 1;
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m-1; j++){
    //         cout << vertical[i][j];
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for (int j = 0; j < m-1; j++){
        if (vertical[0][j]) ans++;
        for (int i = 1; i < n; i++){
            if (vertical[i][j] && (vertical[i-1][j] ^ 1)) ans++;
        }
    }

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] && grid[i+1][j]) ans++;  
        }
    }

    // cout << ans << "\n";

    if (ans & 1){
        cout << "Mirko\n";
    }
    else{
        cout << "Slavko\n";
    }
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