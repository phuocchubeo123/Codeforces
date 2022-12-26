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
    // turn 0 to 1 then inversion minus prefix weight and plus (n - i - suffix weight)
    // turn 1 to 0 then inversion plus prefix weight and minus (n - i - suffix weight)
    int n; cin >> n;
    vi a(n); forn(i, n) cin >> a[i];
    vector<ll> pre(n), suf(n);
    pre[0] = 0;
    rep(i, 1, n-1) pre[i] = pre[i-1] + ((a[i-1] == 1) ? 1 : 0);
    suf[n-1] = 0;
    per(i, n-2, 0) suf[i] = suf[i+1] + ((a[i+1] == 0) ? 1 : 0);

    ll inv = 0;
    forn(i, n) if (a[i] == 1) inv += suf[i];
    // cout << inv << "\n";
    ll mn = inv;
    forn(i, n){
        ll curr;
        if (a[i] == 0) curr = inv - pre[i] + suf[i];
        else curr = inv + pre[i] - suf[i];
        mn = max(mn, curr);
    }
    cout << mn << "\n";
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