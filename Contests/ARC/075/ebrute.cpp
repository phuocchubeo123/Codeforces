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
        cout << "lr: " << l << " " << r << " " << ans << "\n";
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
    int a = l, b = m+1;
    while (true){
        if (b == r+1 && a == m+1) break;
        if (b == r+1){
            new_pre.push_back(pre[a]);
            a++;
            continue;
        }
        if (a == m+1){
            new_pre.push_back(pre[m] + pre[b]);
            b++;
            continue;
        }
        if (pre[a] <= pre[m] + pre[b]){
            new_pre.push_back(pre[a]);
            a++;
        }
        else{
            new_pre.push_back(pre[m] + pre[b]);
            b++;
        }
    }
    rep(i, l, r) pre[i] = new_pre[i-l];

    vector<ll> new_suf;
    a = l; b = m+1;
    while (true){
        if (b == r+1 && a == m+1) break;
        if (b == r+1){
            new_suf.push_back(suf[a] + suf[m+1]);
            a++;
            continue;
        }
        if (a == m+1){
            new_suf.push_back(suf[b]);
            b++;
            continue;
        }
        if (suf[a] + suf[m+1] <= suf[b]){
            new_suf.push_back(suf[a] + suf[m+1]);
            a++;
        }
        else{
            new_suf.push_back(suf[b]);
            b++;
        }
    }
    rep(i, l, r) suf[i] = new_suf[i-l];

    cout << "lr: " << l << " " << r << " " << ans << "\n";
    // print_pre();
    // print_suf();
}

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    forn(i, n) cin >> a[i];

    int ans = 0;
    forn(i, n){
        rep(j, i, n-1){
            int tot = 0;
            rep(x, i, j) tot += a[x];
            // cout << i << " " << j << " " << tot << "\n";
            if (tot >= k * (j - i + 1)){
                ans++;
            }
        }
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