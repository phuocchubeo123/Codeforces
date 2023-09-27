#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll maxn = 1e5+5;
const ll LOG = 18;
const ll INF = 1e12;

vector<int> adj[maxn];
vector<int> chi[maxn];
int par[maxn][LOG];
int vis[maxn];
int l[maxn];
vector<ll> dis;
queue<pair<int, ll>> nb;

void reRoot(int u){
    for (int v: adj[u]){
        if (par[u] == v) continue;
        chi[u].push_back(v);
        par[v][0] = u;
        reRoot(v);
    }
}

void findPar(int u){
    for (int i = 1; i < LOG; i++){
        par[u][i] = par[par[u][i-1]][i-1];
    }

    for (int v: chi[u]){
        findPar(v);
    }
}

void findLevel(int u){
    for (int v: chi[u]){
        l[v] = l[u] + 1;
        findLevel(v);
    }
}

void findClosest(){
    while (!nb.empty()){
        pair<int, ll> cur = nb.front();
        int u = cur.first;
        ll d = cur.second;
        nb.pop();
        if (vis[u] == 1) continue;

        dis[u] = min(dis[u], d);
        vis[u] = 1;
        for (int v: adj[u]){
            if (vis[v] == 1) continue;
            nb.push({v, d+1});
        }
    }
}

ll dst(int u, int v){
    if (l[u] > l[v]) return dst(v, u);
    int cu = u, cv = v;
    int jmp = LOG;
    ll ans = 0;
    while (l[cu] < l[cv]){
        if (l[cu] - (1<<jmp) < l[cv]) jmp--;
        else{
            ans += (1ll << jmp);
            cu = par[cu][jmp];
        }
    }
    if (cu == cv) return ans;

    jmp = LOG;
    while (true){
        if (par[cu][0] == par[cv][0]) return ans + 1;
        if (par[cu][jmp] == par[cv][jmp]) jmp--;
        else{
            cu = par[cu][jmp];
            cv = par[cv][jmp];
            ans += (1ll << jmp);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    int sq = sqrt(n);
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[0][0] = 0;
    par[1][0] = 0;
    reRoot(1);
    findPar(1);
    level[1] = 0;
    findLevel(1);

    nb.push({1, 0});

    for (int _ = 0; _ < m; _++){
        if (_ % sq == 0){
            for (int i = 1; i <= n; i++){
                vis[i] = 0;
                dis[i] = INF;
            }
            findClosest();
        }
        int t; cin >> t;
        int u; cin >> u;
        if (t == 1){
            nb.push({u, 0});
        }
        else{
            queue<int, ll> q = nb;
            ll ans = dis[u];
            while (!q.empty()){
                int v = q.front().first; q.pop();
                ans = min(ans, dst(u, v));
            }
            cout << ans << "\n";
        }
    }
}

int main(){
    solve();
}