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

ll sz, p;
void solve(){
    ll l = 1, r = 1000000;
    while (l < r){
        ll m = (l + r) / 2;
        if (m * m < p) l = m + 1;
        else r = m;
    }
    if (l % 2 == 0) r++;
    if (r * r - r < p){
        cout << "Line = " << (sz >> 1) + 1 + (r >> 1) - (r * r) + p << ", column = " << (sz >> 1) + 1 + (r >> 1) << ".\n";
    }
    else if (r * r - 2 * r + 1 < p){
        cout << "Line = " << (sz >> 1) + 1 - (r >> 1) << ", column = " << (sz >> 1) + 1 + (r >> 1) - r * r + r - 1 + p << ".\n";
    }
    else if (r * r - 3 * r + 2 < p){
        cout << "Line = " << (sz >> 1) + 1 - (r >> 1) + r * r - 2 * r + 2 - p << ", column = " << (sz >> 1) + 1 - (r >> 1) << ".\n";
    }
    else{
        cout << "Line = " << (sz >> 1) + 1 + (r >> 1) << ", column = " << (sz >> 1) + 1 - (r >> 1) + r * r - 3 * r + 3 - p << ".\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    while (true){
        cin >> sz >> p;
        if (sz == 0 && p == 0) break;
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}