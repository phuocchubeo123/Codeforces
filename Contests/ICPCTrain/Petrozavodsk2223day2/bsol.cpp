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

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> ein(n+1);
    vector<vector<int>> eout(n+1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        ein[v].push_back(u);
        eout[u].push_back(v);
    }

    queue<int> q;

    for (int u = 1; u <= n; u++){
        if (ein[u].size() == 0){
            cout << "NO\n";
            return;
        }
        if (ein[u].size() == 1) q.push(u);
    }

    vector<int> vis(n+1, 0);
    vector<int> par(n+1, 0);

    while (true){
        if (q.empty()){
            cout << "YES\n";
            return;
        }

        queue<int> new_q;

        while (!q.empty()){
            int u = q.front();
            q.pop();
            if (par[u] != 0) continue;

            vector<int> can;
            for (int v: ein[u]){
                if (par[v] != u) can.push_back(v);
            }
            if (can.size() == 0){
                cout << "NO\n";
                return;
            }

            if (can.size() == 1){
                par[u] = can[0];
                new_q.push(can[0]);
                continue;
            }
        }

        while (!new_q.empty()){
            q.push(new_q.front()); new_q.pop();
        }
    }

    cout << "YES\n";
    return;
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