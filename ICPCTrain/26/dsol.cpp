#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 4;
int T, n, p, u, v, cnt[N], r[N], lb[N], pos[N];
vector<int> adj[N];

void prepare(){

}

void read(){
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
        // cout << u << " " << v << "\n";
    }
}

void solve(){
    for (int i = 1; i <= n; i++) r[i] = i;
    sort(r + 1, r + n + 1, [&](int u, int v){
        return cnt[u] < cnt[v];
    });
    for (int i = 1; i <= n; i++) lb[i] = n + 1;
    lb[0] = 1;
    for (int i = n; i >= 1; i--) lb[cnt[r[i]]] = i;
    for (int i = n - 1; i >= 1; i--){
        lb[i] = min(lb[i], lb[i + 1]);
    }
    for (int i = 1; i <= n; i++) pos[r[i]] = i;

    // for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    // cout << "\n";
    // for (int i = 1; i <= n; i++) cout << pos[i] << " ";
    // cout << "\n";
    // for (int i = 1; i <= n; i++) cout << lb[i] << " ";
    // cout << "\n";

    // cout << "\n";
    
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        for (int x: adj[i]){
            int tmp = pos[x];
            pos[x] = pos[r[lb[cnt[x]]]];
            pos[r[lb[cnt[x]]]] = tmp;
            r[tmp] = r[lb[cnt[x]]];
            r[lb[cnt[x]]] = x;
            lb[cnt[x]]++;
            cnt[x]--;
        }

        int need = max(0, p - cnt[i]);
        // cout << i << " " << need << " " << lb[need] << "\n";
        // for (int i = 1; i <= n; i++) cout << r[i] << " ";
        // cout << "\n";
        // for (int i = 1; i <= n; i++) cout << cnt[r[i]] << " ";
        // cout << "\n";
        // for (int i = 1; i <= n; i++) cout << lb[cnt[r[i]]] << " ";
        // cout << "\n";
        ans += 1ll * (n - lb[need] + 1);
        if (cnt[i] >= need) ans-= 1;

        for (int x: adj[i]){
            cnt[x]++;
            int tmp = pos[x];
            pos[x] = pos[r[lb[cnt[x]] - 1]];
            pos[r[lb[cnt[x]] - 1]] = tmp;
            r[tmp] = r[lb[cnt[x]] - 1];
            r[lb[cnt[x]] - 1] = x;
            lb[cnt[x]]--;
        }
    }

    cout << ans / 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}