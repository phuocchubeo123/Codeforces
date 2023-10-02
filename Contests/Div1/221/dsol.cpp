#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5+5;

int n, m;
int sq;
int c[maxn];
vector<int> adj[maxn];
int par[maxn];
vector<int> chi[maxn];
int st[maxn], en[maxn];
int clk;
int ans[maxn];
int small[maxn], large[maxn];
int appear[maxn];
int cl[maxn];

void reRoot(int u){
    for (int v: adj[u]){
        if (par[u] == v) continue;
        par[v] = u;
        chi[u].push_back(v);
        reRoot(v);
    }
}

void dfs(int u){
    st[u] = ++clk;
    cl[clk] = c[u];
    for (int v: chi[u]) dfs(v);
    en[u] = clk;
}

struct query{
    int l, r, k, id;
    bool operator<(const query& other){
        return (l / sq == other.l / sq) ? (r < other.r) : (l < other.l);
    }
} qr[maxn];

void up(int k){
    small[k]--;
    small[k+1]++;
    large[k/sq]--;
    large[(k+1)/sq]++;
}

void down(int k){
    small[k]--;
    small[k-1]++;
    large[k/sq]--;
    large[(k-1)/sq]++;
}

void solve(){
    cin >> n >> m;
    sq = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1] = 0;
    reRoot(1);

    clk = -1;
    dfs(1);

    // for (int i = 1; i <= n; i++) cout << st[i] << " " << en[i] << "\n";

    for (int i = 1; i <= m; i++){
        int u; cin >> u;
        cin >> qr[i].k;
        qr[i].l = st[u];
        qr[i].r = en[u];
        qr[i].id = i;
    }

    sort(qr, qr+m);

    for (int i = 1; i <= n; i++){
        appear[i] = 0;
        small[i] = 0;
        large[i] = 0;
    }
    small[0] = n;
    large[0] = n;

    for (int i = 1; i <= n; i++){
        int k = appear[c[i]];
        small[k]--;
        small[k+1]++;
        large[k/sq]--;
        large[(k+1)/sq]++;
        appear[c[i]]++;
    }

    // for (int i = 0; i <= n; i++) cout << cl[i] << " ";
    // cout << "\n";

    int L = 0, R = clk; 
    for (int _ = 1; _ <= m; _++){
        query q = qr[_];
        while (L < q.l){
            int k = appear[cl[L]];
            down(k);
            appear[cl[L]]--;
            L++;
        }

        while (L > q.l){
            L--;
            int k = appear[cl[L]];
            up(k);
            appear[cl[L]]++;
        }

        while (R > q.r){
            int k = appear[cl[R]];
            down(k);
            appear[cl[R]]--;
            R--;
        }

        while (R < q.r){
            R++;
            int k = appear[cl[R]];
            up(k);
            appear[cl[R]]++;
        }

        // for (int i = 0; i <= n; i++) cout << appear[i] << " ";
        // cout << "\n";

        ans[q.id] = 0;
        for (int i = q.k / sq; i <= n / sq; i++){
            ans[q.id] += large[i];
        }
        for (int i = q.k / sq * sq; i < q.k; i++){
            ans[q.id] -= small[i];
        }

        // cout << q.l << " " << q.r << " " << q.id << " " << ans[q.id] << "\n";
    }

    for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
}

int main(){
    solve();
}