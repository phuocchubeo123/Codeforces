#include<bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> par;

    dsu(int n){
        par.resize(n+1);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    bool uni(int u, int v){
        if (find(u) == find(v)) return true;
        par[par[u]] = par[v];
        par[u] = par[v];
        return false;
    }

    int find(int u){
        if (par[u] == u) return u;
        par[u] = find(par[u]);
        return par[u];
    }
};

void solve(){
    int n; cin >> n;
    dsu d(1000);
    for (int i = 0; i < n; i++){
        int p, q; cin >> p >> q;
        if (d.uni(p, q)) cout << "Y\n";
        else cout << "N\n";
    }
}

int main(){
    solve();
}