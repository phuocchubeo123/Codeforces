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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<ll> a(maxn);
vector<ll> suf(maxn);
vector<ll> pre(maxn);
ll n, k;
ll ans;

void print_pre(){
    cout << "pre: ";
    forn(i, n) cout << pre[i] << " ";
    cout << "\n";
}

void print_suf(){
    cout << "suf: ";
    forn(i, n) cout << suf[i] << " ";
    cout << "\n";
}

void find(int l, int r){
    if (l == r){
        if (a[l] >= 0) ans++;
        suf[l] = a[l];
        pre[l] = a[l];
        // cout << "lr: " << l << " " << r << " " << ans << "\n";
        // print_pre();
        // print_suf();
        return;
    }

    int m = (l + r) / 2;
    find(l, m);
    find(m+1, r);

    int pt = m;
    rep(i, m+1, r){
        while (suf[pt] + pre[i] >= 0){
            if (pt > l) pt--;
            else break;
        }
        if (suf[pt] + pre[i] >= 0) ans += 1ll * (m - pt + 1);
        else ans += 1ll * (m - pt);
    }

    vector<ll> new_pre;
    int u = l, v = m+1;
    ll tot = 0;
    rep(i, l, m) tot += a[i];
    while (true){
        if (v == r+1 && u == m+1) break;
        if (v == r+1){
            new_pre.push_back(pre[u]);
            u++;
            continue;
        }
        if (u == m+1){
            new_pre.push_back(tot + pre[v]);
            v++;
            continue;
        }
        if (pre[u] <= tot + pre[v]){
            new_pre.push_back(pre[u]);
            u++;
        }
        else{
            new_pre.push_back(tot + pre[v]);
            v++;
        }
    }
    rep(i, l, r) pre[i] = new_pre[i-l];

    vector<ll> new_suf;
    u = l; v = m+1;
    tot = 0;
    rep(i, m+1, r) tot += a[i];
    while (true){
        if (v == r+1 && u == m+1) break;
        if (v == r+1){
            new_suf.push_back(suf[u] + tot);
            u++;
            continue;
        }
        if (u == m+1){
            new_suf.push_back(suf[v]);
            v++;
            continue;
        }
        if (suf[u] + tot <= suf[v]){
            new_suf.push_back(suf[u] + tot);
            u++;
        }
        else{
            new_suf.push_back(suf[v]);
            v++;
        }
    }
    rep(i, l, r) suf[i] = new_suf[i-l];

    // cout << "lr: " << l << " " << r << " " << ans << "\n";
    // print_pre();
    // print_suf();
}

void solve(){
    cin >> n;
    cin >> k;
    forn(i, n){
        cin >> a[i];
        a[i] -= k;
    }

    ans = 0;
    find(0, n-1);
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