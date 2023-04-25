#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))

const int maxn = 4e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vi> adj(maxn), chi(maxn);
vi vis(maxn), par(maxn), co(maxn), co_size(maxn);
int color;

void connectedComponents(int u){
    if (co[u] != -1) return;
    co[u] = color;
    for (int v: adj[u]) connectedComponents(v);
}

void solve(){
    int n; cin >> n;
    forn(u, n) adj[u].clear();
    forn(u, n){
        string s; cin >> s;
        forn(v, n) if (s[v] == '1') adj[u].push_back(v);
    }

    color = 0;
    forn(i, n) co[i] = -1;
    forn(i, n){
        if (co[i] != -1) continue;
        color++;
        connectedComponents(i);
    }

    if (color == 1){
        cout << 0 << "\n";
        return;
    }

    rep(i, 1, n) co_size[i] = 0;
    forn(i, n) co_size[co[i]]++;

    rep(i, 1, n) if (co_size[i] == 1){
        cout << 1 << "\n";
        forn(j, n) if (co[j] == i){ cout << j+1 << "\n"; break;}
        return;
    }

    forn(i, n) if (adj[i].size() + 1 < co_size[co[i]]){
        cout << 1 << "\n";
        int mn = n+1;
        forn(j, n) if (co[j] == co[i]) mn = min((int) adj[j].size(), mn);
        forn(j, n) if (co[j] == co[i] && adj[j].size() == mn){ cout << j+1 << "\n"; break;}
        return;
    }

    if (color >= 3){
        cout << 2 << "\n";
        forn(i, n) if (co[i] == 1){ cout << i+1 << " "; break;}
        forn(i, n) if (co[i] == 2){ cout << i+1 << " "; break;}
        cout << "\n";
        return;
    }

    if (co_size[1] <= co_size[2]){
        cout << co_size[1] << "\n";
        forn(i, n) if (co[i] == 1) cout << i+1 << " ";
    }
    else{
        cout << co_size[2] << "\n";
        forn(i, n) if (co[i] == 2) cout << i+1 << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}