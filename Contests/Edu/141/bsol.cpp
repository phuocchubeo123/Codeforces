#include <bits/stdc++.h>
using namespace std;

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
    // n = 1: 1
    // n = 2: 
    // 1 7 4
    // 9 3 6
    // 2 8 5

    int n; cin >> n;
    vi a;
    a.push_back(1);
    int curr = 1;
    int sign = -1;
    per(i, n * n - 1, 1){
        sign = -sign;
        curr = curr + sign * i;
        a.push_back(curr);
    }
    // forn(i, n * n) cout << a[i] << " ";
    // cout << "\n";
    forn(i, n / 2){
        forn(j, n) cout << a[n * (2 * i) + j] << " ";
        cout << "\n";
        forn(j, n) cout << a[n * (2 * i + 2) - j - 1] << " ";
        cout << "\n";
    }
    if (n & 1){
        forn(i, n) cout << a[n * (n-1) + i] << " ";
        cout << "\n";
    }
}

using namespace std::chrono;

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