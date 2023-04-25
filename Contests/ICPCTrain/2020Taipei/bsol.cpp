#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e5 + 4;
int T;

void prepare(){

}

vt<vt<int>> adj(N), chi(N);
vt<int> par(N, 0), dp0(N), dp1(N);

void dfs(int u, int isr){
    // cout << u << "\n";
    if (chi[u].size() == 0){
        dp0[u] = 1;
        dp1[u] = 0;
        return;
    }

    for (int v: chi[u]){
        dfs(v, 1);
    }

    dp0[u] = 1;
    for (int v: chi[u]){
        dp0[u] += min(dp0[v], dp1[v]);
    }

    vt<pair<int, pair<int, int>>> costs;
    for (int v: chi[u]){
        costs.pb({dp0[v] - dp1[v], {dp0[v], dp1[v]}});
    }

    int tot = 0;
    for (int v: chi[u]){
        tot += dp1[v];
    }

    sort(costs.begin(), costs.end());
    int mid;
    if (isr == 0) mid = (chi[u].size() - 1) / 2;
    else mid = (chi[u].size() + 1) / 2;

    int i = 0;
    while (i < costs.size() && (i < mid || costs[i].first <= 0)){
        tot += costs[i].first;
        i++;
    }

    dp1[u] = tot;
}

void solve(){
    int n; cin >> n;

    for0(i, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    //root
    stack<int> st;
    st.push(1);
    while (!st.empty()){
        int u = st.top(); st.pop();
        for (int v: adj[u]){
            if (v == par[u]) continue;
            chi[u].pb(v);
            par[v] = u;
            st.push(v);
        }
    }

    dfs(1, 0);
    cout << min(dp0[1], dp1[1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}