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

const int maxn = 5e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;


int adj[maxn][maxn];

void add_edge(int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void solve1(){
    int n; cin >> n;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) adj[i][j] = 0;

    for (int i = 1; i <= n-1; i++){
        int u, v; cin >> u >> v;
        add_edge(u, v);
    }

    int p[n+1];
    vector<int> q;
    for (int i = 1; i <= n; i++) q.push_back(i);
    int ans = 0;

    do{
        // cout << 1 << "\n";
        // cout.flush();
        for (int i = 0; i < n; i++){
            p[i+1] = q[i];
        }
        

        bool flag = true;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if (adj[i][j] != adj[p[i]][p[j]]){
                    // cout << i << " " << j << "; ";
                    flag = false; 
                    break;
                }
            }
            if (!flag) break;
        }

        if (flag){for (int i = 1; i <= n; i++) cout << p[i] << " ";
        cout << "\n"; ans++;}
    } while (next_permutation(q.begin(), q.end()));
    
    cout << ans << "\n";
    return;
}

void solve(){
    ll k; cin >> k;

    int prime[401];

    for (int i = 2; i <= 400; i++){
        bool flag = true;
        for (int j = 2; j < i; j++){
            if (i % j == 0) flag = false;
        }
        if (flag) prime[i] = 1;
        else prime[i] = 0;
    }

    // for (ll x = 2; x <= 400; x++) cout << prime[x] << " ";
    // cout << "\n";

    vector<ll> p;
    for (ll x = 2; x <= 400; x++){
        if (prime[x] == 1){
            // cout << x << " " << prime[380] << "\n";
            p.push_back(x);
        }
    }

    reverse(p.begin(), p.end());

    bool flag = false;
    for (ll x: p){
        if (k % x == 0) flag = true;
    }

    if (!flag){
        cout << -1 << "\n";
        return;
    }

    vector<ll> f;
    f.push_back(1);
    for (ll i = 1; i < 400; i++){
        if (f.back() * i > 1e18) break;
        f.push_back(f.back() * i);
    }

    vector<ll> l;

    while (true){
        if (k == 1) break;
        for (ll x: p){
            if (k % x == 0){
                // cout <<   x << "\n";
                if (x >= f.size()){
                    // cout << "too large\n";
                    cout << -1 << "\n";
                    return;
                }
                if (k % f[x] != 0){
                    // cout << "cannot\n";
                    cout << -1 << "\n";
                    return;
                }
                k /= f[x];
                l.push_back(x);
                break;
            }
        }
    }

    vector<int> cnt(40, 0);
    for (ll x: l){
        cnt[x]++;
    }

    int pt = 1;
    vector<pair<int, int>> ans;
    for (int x = 2; x < 40; x++){
        if (cnt[x] > 0){
            ans.push_back({1, ++pt});
            int cur = pt;
            for (int i = 0; i < x; i++){
                ans.push_back({cur, ++pt});
            }
            if (cnt[x] == 1){
                continue;
            }

            cur = 1;
            for (int i = 0; i < cnt[x] - 1; i++){
                ans.push_back({cur, ++pt});
                cur = pt;
                ans.push_back({cur, ++pt});
                int u = pt;
                for (int j = 0; j < x; j++){
                    ans.push_back({u, ++pt});
                }
            }
        }
    }

    ans.push_back({1, ++pt});

    cout << pt << "\n";
    for (auto pp: ans){
        cout << pp.first << " " << pp.second << "\n";
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