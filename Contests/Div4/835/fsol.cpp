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
    int n; cin >> n;
    ll c, d; cin >> c >> d;
    vector<ll> a(n); forn(i, n) cin >> a[i];
    sort(all(a)); reverse(all(a));
    // forn(i, n) cout << a[i] << " ";
    // cout << "\n";
    vector<ll> pre(n);
    pre[0] = a[0];
    rep(i, 1, n-1) pre[i] = pre[i-1] + a[i];

    if ((c + a[0] - 1) / a[0] > d){
        cout << "Impossible\n";
        return;
    }

    // if (a[0] >= c){
    //     cout << "Infinity\n";
    //     return;
    // }

    int l = 0, r = d+1;
    while (l < r){
        int m = (l + r + 1) / 2;
        ll interval = 1ll * m + 1;
        ll num_inters = d / interval;
        ll rem = d % interval;
        ll coins;
        if (m >= n) coins = num_inters * pre[n-1];
        else coins = num_inters * pre[m];
        if (rem != 0){
            if (rem >= n) coins += pre[n-1];
            else coins += pre[rem-1];
        }
        if (coins >= c) l = m;
        else r = m-1;
    }
    if (r != d+1) cout << l << "\n";
    else cout << "Infinity\n";
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