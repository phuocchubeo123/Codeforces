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

const int maxn = 805;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vector<pair<int, ll>>> adj(maxn);

void solve(){
    int n, m;
    ll p;
    cin >> n >> m >> p;
    vi w(n+1);
    rep(i, 1, n) cin >> w[i];
    forn(i, m){
        int a, b;
        ll s;
        cin >> a >> b >> s;
        adj[a].push_back({b, s});
    }

    priority_queue<pair<pair<ll, ll>, int>> pq;
    pq.push({{0, -p}, 1});
    vi visited(n+1, 0);
    vi perf(n+1, 0);
    vi money(n+1, -p);
    while (!pq.empty()){
        pair<pair<ll, ll>, int> curr = pq.top();
        pq.pop();
        int i = curr.second;
        visited[i] = 1;
        for (pair<int, ll> next: adj[i]){
            int j = next.second;
            if (visited[j] == 1) continue;
            
        }
    }

    ////////////////////////
    // clear everything
    rep(i, 1, n) adj[i].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}