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
    int n, k, x; cin >> n >> k >> x;
    int tot = 0;
    rep(i, 1, n) tot = tot ^ i;
    int need;
    if ((k & 1) ^ 1) need = 0;
    else need = x;
    if (tot != need){ cout << "NO\n"; return;}
    vi vis(n+1, 0);
    vi can;
    rep(i, 1, n) if ((i ^ x) <= n){ 
        if (vis[i] == 1) continue;
        if (i == x){
            can.push_back(i);
            vis[i] = 1;
            continue;
        }
        can.push_back(i);
        vis[i] = 1; 
        vis[i^x] = 1;
    }
    if (can.size() < k){ cout << "NO\n"; return;}

    int cnt = 0;
    vi visited(n+1, 0);
    vvi anss;
    for (int i: can){
        cnt++;
        vi a;
        if (cnt == k){
            rep(i, 1, n) if (visited[i] == 0) a.push_back(i);
            anss.push_back(a);
            break;
        }
        if (i == x){
            a.push_back(i);
            visited[i] = 1;
            anss.push_back(a);
            continue;
        }
        a.push_back(i);
        a.push_back(i^x);
        visited[i] = visited[i^x] = 1;
        anss.push_back(a);
    }

    cout << "YES\n";
    for (vi a: anss){
        cout << a.size() << " ";
        for (int i: a) cout << i << " ";
        cout << "\n";
    }
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