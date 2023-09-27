#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll maxn = 1e5+5;
const ll LOG = 18;

vector<int> adj[maxn];
vector<int> chi[maxn];
int par[maxn][LOG];
int c[maxn];

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

    for (int i = 1; i <= n; i++) c[i] = 0;
    c[1] = 1;

    for (int _ = 0; _ < m; _++){
        if (_ == sq){

        }
        int t; cin >> t;
        int u; cin >> u;
        if (t == 1){
            c[u] = 1;
        }
    }
}

int main(){
    solve();
}