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

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    // to find lcp between 2 arbitrary suffices i and j, we call min of the lcp in range [i...j-1]
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

struct dsu{
    vi p;

    dsu(){}
    dsu(int n){p.resize(n); forn(i, n) p[i] = i;}

    int get(int u){
        return (u == p[u]) ? u : (p[u] = get(p[u]));
    }
    bool unite(int u, int v){
        u = get(u); v = get(v);
        if (u != v){ p[u] = v; return true;}
        return false;
    }
};

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s.push_back('a' - 1);

    vi sfx_array = sort_cyclic_shifts(s);
    // for (int x: sfx_array){
        // cout << x << " ";
    //     rep(i, x, s.size()) cout << s[i];
    //     cout << "\n";
    // }
    // cout << "\n";

    vi lcp = lcp_construction(s, sfx_array);

    // rep(i, 1, n-1) cout << lcp[i] << " ";
    // cout << "\n";

    vvi nums(n+1);
    rep(i, 1, n-1) nums[lcp[i]].push_back(i);

    // rep(i, 1, n){
    //     cout << i << ": ";
    //     for (int j: nums[i]) cout << j << " ";
    //     cout << "\n";
    // }

    dsu d(n+1);
    vi sz(n+1, 1);
    vi cnt(n+1, 0);
    cnt[1] = n;
    ll ans = 0;

    per(k, n, 2){
        for (int i: nums[k]){
            int x = d.get(i), y = d.get(i+1);
            if (x == y) continue;
            d.unite(i, i+1);
            cnt[sz[x]]--;
            cnt[sz[y]]--;
            sz[d.get(i)] = sz[x] + sz[y];
            cnt[sz[d.get(i)]]++;
        }

        // rep(i, 1, n) cout << d.get(i) << " ";
        // cout << "\n";

        for (int i = 1; i * k <= n; i++){
            ans += 1ll * cnt[i * k] * i * k;
        }

        // cout << ans << "\n";
    }

    ans += n;
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