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

const int maxn = 3e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

bool isp[maxn];

void eratosthenesSieve(){
    forn(i, maxn) isp[i] = true;
    isp[0] = false;
    rep(i, 1, maxn-1){
        if (i == 1){
            isp[i] = false;
            continue;
        }

        for (int j = 2; i * j < maxn; j++) isp[i * j] = false;
    }
}

vi primes;

void findPrimes(){
    forn(i, maxn) if (isp[i]) primes.push_back(i);
}

vvi divisor(maxn);

void findDivisor(){
    for (int p: primes){
        for (int i = 1; i * p < maxn; i++) divisor[i * p].push_back(p);
    }
}

vvi adj(2 * maxn);
vector<bool> vis(2 * maxn, false);
vi dis(2 * maxn, 0), pre(2 * maxn, -1);

void solve(){
    eratosthenesSieve();
    findPrimes();
    findDivisor();
    int n; cin >> n;
    vi a(n); forn(i, n) cin >> a[i];
    int s, t; cin >> s >> t; s--; t--;

    forn(i, n){
        for (int p: divisor[a[i]]){
            adj[i].push_back(p+maxn);
            adj[p+maxn].push_back(i);
        }
    }

    // forn(i, n){
    //     cout << a[i] << ":\n";
    //     for (int p: adj[i]) cout << p << " ";
    //     cout << "\n";
    // }

    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u = q.front(); q.pop();
        // cout << u << "\n";
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v: adj[u]){
            if (vis[v]) continue;
            dis[v] = dis[u] + 1;
            pre[v] = u;
            q.push(v);
            // cout << v << " " << dis[v] << "\n";
        }
    }

    // forn(i, n) cout << dis[i] << " ";
    // cout << "\n";
    // cout << dis[t] << "\n";

    if (s == t){
        cout << 1 << "\n" << s + 1 << "\n";
        return;
    }

    if (pre[t] == -1){
        cout << -1 << "\n";
        return;
    }

    int curr = t;
    vi ans;
    while (curr != s){
        ans.push_back(curr);
        curr = pre[curr];
    }
    ans.push_back(s);
    reverse(all(ans));
    cout << ans.size() / 2 + 1 << "\n";
    for (int x: ans){
        if (x < maxn) cout << x + 1 << " ";
    }
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