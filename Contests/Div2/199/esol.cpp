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
ll dis[maxn];
int c[maxn];
queue<pair<int, ll>> nb;
ll ans;

void reRoot(int u){
    for (int v: adj[u]){
        if (par[u][0] == v) continue;
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
        // cout << u << " " << d << "\n";
        // cout.flush();
        nb.pop();
        if (vis[u] == 1) continue;

        dis[u] = min(dis[u], d);
        vis[u] = 1;

        for (int v: adj[u]){
            // cout << v << " " << c[v] << "\n";
            if (c[v] == 1) continue; 
            if (vis[v] == 1) continue;
            nb.push({v, d+1});
        }
    }
}

ll dst(int u, int v){
    if (l[u] < l[v]) return dst(v, u);
    int cu = u, cv = v;
    int jmp = LOG-1;
    ll ans2 = 0;
    while (l[cu] > l[cv]){
        if (l[cu] - (1ll<<jmp) < l[cv]) jmp--;
        else{
            ans2 += (1ll << jmp);
            if (ans2 >= ans) return ans;
            cu = par[cu][jmp];
        }
    }
    if (cu == cv) return ans2;

    // cout << cu << " " << cv << "\n";
    // cout.flush();

    jmp = LOG-1;  
    while (true){
        if (par[cu][0] == par[cv][0]) return ans2 + 2;
        if (par[cu][jmp] == par[cv][jmp]) jmp--;
        else{
            cu = par[cu][jmp];
            cv = par[cv][jmp];
            ans2 += 2 * (1ll << jmp);
            if (ans2 >= ans) return ans;
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
    l[1] = 0;
    findLevel(1);

    nb.push({1, 0});
    c[1] = 1;

    for (int i = 1; i <= n; i++){
        dis[i] = INF;
    }

    for (int _ = 0; _ < m; _++){
        if (_ % sq == 0){
            for (int i = 1; i <= n; i++) vis[i] = 0;
            findClosest();
        }

        int t; cin >> t;
        int u; cin >> u;
        if (t == 1){
            nb.push({u, 0});
            c[u] = 1;
        }

        else{
            queue<pair<int, ll>> q = nb;
            ans = dis[u];
            while (!q.empty()){
                int v = q.front().first; q.pop();
                if (abs(l[v] - l[u]) >= dis[u]) continue;
                ans = min(ans, dst(u, v));
            }
            cout << ans << "\n";
        }
    }
}

int main(){
    solve();
}