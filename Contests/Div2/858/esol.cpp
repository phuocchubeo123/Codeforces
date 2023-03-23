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

int n;
vvi chi(maxn);
vi dep(maxn);
map<ll, ll> cost;
vi p(maxn);
vector<ll> a(maxn);

void dfs(int i){
    for (int j: chi[i]){
        dep[j] = dep[i] + 1;
        dfs(j);
    }
}

void solve(){
    cin >> n;
    int q; cin >> q;
    rep(i, 1, n) cin >> a[i];
    rep(i, 2, n) cin >> p[i];
    vi u(q), v(q);
    forn(i, q) cin >> u[i] >> v[i];

    rep(i, 2, n) chi[p[i]].push_back(i);
    dep[1] = 0;
    dfs(1);

    // rep(i, 1, n) cout << dep[i] << " ";
    // cout << "\n";

    vi cnt(n+1, 0);
    rep(i, 1, n) cnt[dep[i]]++;
    vi alr(n+1, 0);
    vi label(n+1, 0);
    vvi nodes(n+1);
    rep(i, 1, n) if (cnt[dep[i]] < 400){
        nodes[dep[i]].push_back(i);
        label[i] = alr[dep[i]];
        alr[dep[i]]++;
    }

    // forn(i, n+1){
    //     cout << i << " " << cnt[i] << "\n";
    //     for (int x: nodes[i]) cout << x << " ";
    //     cout << "\n";
    // }

    vector<vector<vector<ll>>> ans(n+1);
    forn(d, n+1){
        if (cnt[d] < 400 && cnt[d] > 0){
            vector<vector<ll>> tmp(cnt[d], vector<ll> (cnt[d]));
            ans[d] = tmp;
        }
    }   

    ans[0][0][0] = a[1] * a[1];

    rep(d, 1, n){
        if (cnt[d] < 400 && cnt[d] > 0){
            forn(i, nodes[d].size()){
                forn(j, nodes[d].size()){
                    int x = nodes[d][i], y = nodes[d][j];
                    int x1 = x, y1 = y;
                    int d1 = d;
                    ll tot = 0;
                    while (true){
                        tot += a[x1] * a[y1];
                        x1 = p[x1]; y1 = p[y1];
                        d1--;
                        if (cnt[d1] < 400 && cnt[d1] > 0){
                            ans[d][label[x]][label[y]] = tot + ans[d1][label[x1]][label[y1]];
                            break;
                        }
                    }
                }
            }
        }
    }

    // return;

    forn(i, q){
        int x = u[i], y = v[i];
        int d = dep[x];
        ll tot = 0;
        while (true){
            // cout << x << " " << y << "\n";
            if (cnt[d] < 400 && cnt[d] > 0){
                cout << tot + ans[d][label[x]][label[y]] << "\n";
                break;
            }
            tot += a[x] * a[y];
            x = p[x]; y = p[y];
            d--;
        }
        // cout << "\n";
    }

    /////////////
    // clear data
    rep(i, 1, n) chi[i].clear();
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