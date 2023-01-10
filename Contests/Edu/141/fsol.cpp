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

void swap(vi& p, vi& p1, int i, int j){
    p1[p[i]] = j;
    p1[p[j]] = i;
    int tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}

void solve(){
    int n; cin >> n;
    vi a(n+1), b(n+1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    vi a1(n+1), b1(n+1);
    rep(i, 1, n){ a1[a[i]] = i; b1[b[i]] = i;}

    vi ans;
    rep(i, 1, n){
        if (a[i] != i && b[i] != i){
            ans.push_back(i);
            swap(a, a1, i, a1[i]);
            swap(b, b1, i, b1[i]);
        }
    }

    vector<bool> visa(n+1, false), visb(n+1, false);
    vvi cyca, cycb;
    rep(i, 1, n){
        if (visa[i]) continue;
        int curr = i;
        vi cyc;
        while (!visa[curr]){
            cyc.push_back(curr);
            visa[curr] = true;
            curr = a[curr];
        }
        cyca.push_back(cyc);
    }

    rep(i, 1, n){
        if (visb[i]) continue;
        int curr = i;
        vi cyc;
        while (!visb[curr]){
            cyc.push_back(curr);
            visb[curr] = true;
            curr = b[curr];
        }
        cycb.push_back(cyc);
    }

    for (vi cyc: cyca){
        forn(i, cyc.size() - 1) ans.push_back(cyc[i]);
    }

    for (vi cyc: cycb){
        forn(i, cyc.size() - 1) ans.push_back(cyc[i]);
    }

    cout << ans.size() << "\n";
    for (int x: ans) cout << x << " ";
    // rep(i, 1, n) cout << a[i] << " ";
    // cout << "\n";
    // rep(i, 1, n) cout << a1[i] << " ";
    // cout << "\n";
}

using namespace std::chrono;

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