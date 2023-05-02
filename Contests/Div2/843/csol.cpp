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
    ll n, x; cin >> n >> x;
    ll up = (1ll << 62), down = n;
    forn(bit, 62){
        int i = ((n >> bit) & 1), j = ((x >> bit) & 1);
        if (i == 0 && j == 0) continue;
        if (i == 0 && j == 1){ cout << -1 << "\n"; return;}
        if (i == 1 && j == 0){ down = (((n >> (bit + 1)) + 1) << (bit + 1));}
        if (i == 1 && j == 1){ up = min(up, (((n >> (bit + 1)) + 1) << (bit + 1)) - 1);}
        // cout << up << " " << down << "\n";
    }

    if (up >= down) cout << down << "\n";
    else cout << -1 << "\n";
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