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

const int maxn = 1e3 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

int n, m;
vector<vector<int>> adj(maxn), adj_rev(maxn);
vector<vector<pii>> adj_pa(maxn), adj_rev_pa(maxn);
vector<bool> used(maxn);
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

vvi components;

void stronglyConnectedCC(){
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    reverse(order.begin(), order.end());
    for (auto v : order){
        if (!used[v]) {
            dfs2 (v);
            // processing next component
            // for (int x: component) cout << x << " ";
            // cout << "\n";
            components.push_back(component);
            component.clear();
        }
    }
}

vector<int> roots(maxn, 0);
vector<int> root_nodes;
vector<vector<int>> adj_scc(n);

void condensedGraph(){
    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    reverse(order.begin(), order.end());
    for (auto v : order){
        if (!used[v]) {
            dfs2(v);
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);
            component.clear();
        }
    }
    for (int v = 0; v < n; v++){
        for (auto u : adj[v]) {
            int root_v = roots[v], root_u = roots[u];
            if (root_u != root_v) 
                adj_scc[root_v].push_back(root_u);
        }
    }
}

struct Edge {
    int a, b, cost;
};

vector<Edge> edges;
// const int INF = 1000000000;

void BellmanFord()
{
    vector<int> d(n, INF);
    d[v] = 0;
    for (;;) {
        bool any = false;

        for (Edge e : edges)
            if (d[e.a] < INF)
                if (d[e.b] > d[e.a] + e.cost) {
                    d[e.b] = d[e.a] + e.cost;
                    any = true;
                }

        if (!any)
            break;
    }
    // display d, for example, on the screen
}
ll dp[maxn][3*maxn][2];
ll dist[2*maxn+2];
void solve(){
    cin >> n >> m;
    vi x(m), y(m), z(m);
    for (int i = 0; i < m; i++){
        cin >> x[i] >> y[i] >> z[i];
    }

    forn(i, m){
        adj[x[i]].push_back(y[i]);
        adj_rev[y[i]].push_back(x[i]);
        adj_pa[x[i]].push_back({y[i],z[i]});
        adj_rev_pa.push_back({x[i],z[i]});
    }
    ll ans[n+1];
    bool found[n+1];
    for(i=0;i<n;i++){
        found[i]=false;
    }
    stronglyConnectedCC();
    for (vi component: components){
        if(component.size()==0){
            continue;
        }
        set<ll> s;
        for(auto num:component){
            s.insert(num);
        }
        ll a=component[0];
        for(i=0;i<n;i++){
            for(j=0;j<=3*n;j++){
                if(j==0){
                    if(i==a){
                        dp[i][j][0]=0;
                        dp[i][j][1]=INF;
                    }
                    else{
                        dp[i][j][0]=INF;
                        dp[i][j][1]=INF;
                    }
                    continue;
                }
                if(s.count(i)==0){
                    continue;
                }
                dp[i][j][0]=INF;
                dp[i][j][1]=INF;
                for(auto pa:adj_rev_pa[i]){
                    if(s.count(pa.fi)==0){
                        continue;
                    }
                    if(pa.se%2==0){
                        if(dp[pa.fi][j-1][0]<INF){
                            dp[i][j][0]=min(dp[i][j][0],dp[pa.fi][j-1][0]+pa.se);
                        }

                        if(dp[pa.fi][j-1][1]<INF){
                            dp[i][j][1]=min(dp[i][j][1],dp[pa.fi][j-1][1]+pa.se);
                        }
                    }
                    else{
                        if(dp[pa.fi][j-1][0]<INF){
                            dp[i][j][1]=min(dp[i][j][1],dp[pa.fi][j-1][0]+pa.se);
                        }

                        if(dp[pa.fi][j-1][1]<INF){
                            dp[i][j][0]=min(dp[i][j][0],dp[pa.fi][j-1][1]+pa.se);
                        }
                    }
                }
            }
        }
        bool findodd,findneg;
        findodd=false;
        findneg=false;
        for(i=0;i<=3*n;i++){
            if(dp[a][i][1]<INF){
                findneg=true;
            }
        }
        for(i=0;i<n;i++){
            dist[i]=INF;
        }
        for(auto i:s){
            for(j=0;j<=n-1;j++){
                dist[i]=min(dist[i],dp[i][j][0]);
                dist[i]=min(dist[i],dp[i][j][1]);
            }
        }
        for(j=0;j<m;j++){
            if(s.count(x[j])==0||s.count(y[j])==0){
                continue;
            }
            if(dist[x[j]]!=INF&&dist[x[j]]+z[j]<dist[y[j]]){
                findneg=true;
            }
        }
        if(!findodd){
            continue;
        }
        for(auto i:s){
            found[i]=true;
        }
        if(!findneg){
            for(auto i :s){
                ans[i]=INF;
            }
            continue;
        }
        for(auto i:s){
            for(j=0;j<2*n;j++){
                dist[j]=INF;
            }
            dist[i]=0;
            set<pll> allpa;
            allpa.insert({i,dist[i]});
            while(!allpa.empty()){
                auto pa=*allpa.begin();
                allpa.erase(allpa.begin());
                for(auto pa1:adj_pa[pa.fi%n]){
                    if(pa1.second%2==0){    
                        if(dist[pa1.fi+(pa.fi/n)]>dist[pa.fi]+pa.se){
                            dist[pa1.fi+(pa.fi/n)]=dist[pa.fi]+pa.se
                        }
                    }
                }
            }
        }
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