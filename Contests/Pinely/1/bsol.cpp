#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
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
    // c b a c b c b 
    // 1 2 1 2 -> 1 2 
    int n; cin >> n;
    vi a(n); forn(i, n) cin >> a[i];
    if (n & 1){ cout << n << "\n"; return;}
    int mx = 0, mn = n;
    forn(i, n){ mx = max(mx, a[i]); mn = min(mn, a[i]);}
    vi cnt(n+1); forn(i, n) cnt[a[i]]++;
    if (cnt[mx] == n / 2 && cnt[mn] == n/2){ cout << n / 2 + 1 << "\n"; return;}
    cout << n << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}