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
    int n, s; cin >> n >> s;
    int mx = 0;
    vi cnt(51, 0);
    vi a(n); forn(i, n){ cin >> a[i]; cnt[a[i]] = 1; mx = max(mx, a[i]);}
    int tot = 0;
    rep(i, 1, mx) if (i <= mx && cnt[i] == 0) tot += i;
    if (tot > s){ cout << "NO\n"; return;}
    if (tot == s){ cout << "YES\n"; return;}
    rep(i, mx+1, 1000){
        tot += i;
        if (tot > s){ cout << "NO\n"; return;}
        if (tot == s){ cout << "YES\n"; return;}
    }
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