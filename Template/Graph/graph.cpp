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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

vector<vi> adj(maxn), chi(maxn);
vi vis(maxn), par(maxn);

void reRoot(int u){
    // Re root the tree
    // O(n)

    forn(i, maxn) par[i] = -1;
    stack<int> st;
    st.push(u);   
    while (!st.empty()){
        int curr = st.top(); st.pop();
        for (int next: adj[curr]){
            if (par[curr] == next) continue;
            par[next] = curr;
            chi[curr].push_back(next);
        }
    }
}

vi co(maxn);
int color;

void connectedComponents(int u){
    // find connected Components
    if (co[u] != -1) return;
    co[u] = color;
    for (int v: adj[u]) connectedComponents(v);
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

int main(){
    // read graph
}