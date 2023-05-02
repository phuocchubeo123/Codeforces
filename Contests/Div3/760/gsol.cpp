#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, m, q, a[N], b[N], k[N], c[2 * N], p[2 * N];
ll cumu[2 * N];
ll tot = 0;
vector<pair<int, int>> nodes;
set<int> ks;
map<int, ll> ans;
map<int, vector<int>> edge;

void read(){
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= q; i++) cin >> k[i];
}

ll segSum(int x, int y){
    if (x == 0) return cumu[y];
    return cumu[y] - cumu[x - 1];
}

void merge(int i){
    int l = nodes[i].second, r = nodes[i + 1].second;
    int parent = p[i + 1], child = c[i];
    c[parent] = child; p[child] = parent;
    nodes[parent].second = l + r;
    nodes[child].second = l + r;
    tot += 1ll * (segSum(parent - l - r + 1, parent - r) - segSum(i - l + 1, i));
}

void solve(){
    for (int i = 1; i <= n; i++){
        nodes.push_back({a[i], 1});
        tot += 1ll * a[i];
    }

    for (int i = 1; i <= m; i++) nodes.push_back({b[i], 0});
    sort(nodes.begin(), nodes.end());

    ll cumu_tot = 0;
    for (int i = 0; i < nodes.size(); i++){
        cumu_tot += 1ll * nodes[i].first;
        cumu[i] = cumu_tot;
    }

    for (int i = 1; i <= q; i++) ks.insert(k[i]);

    for (int i = 0; i < nodes.size() - 1; i++){
        set<int>::iterator min_k = ks.lower_bound(nodes[i + 1].first - nodes[i].first);
        if (min_k != ks.end()){
            edge[*min_k].push_back(i);
        }
    }

    for (int i = 0; i < nodes.size(); i++){
        c[i] = i;
        p[i] = i;
    }

    // for (int i = 0; i < nodes.size(); i++) cout << nodes[i].first << " ";
    // cout << "\n";

    for (int query: ks){
        // for (int i = 0; i < nodes.size(); i++) cout << p[i] << " ";
        // cout << "\n";
        // for (int i = 0; i < nodes.size(); i++) cout << nodes[i].second << " ";
        // cout << "\n";
        // cout << "\n";

        vector<int> add_edge = edge[query];

        for (int i: add_edge) merge(i);
        ans[query] = tot;
    }

    for (int i = 1; i <= q; i++) cout << ans[k[i]] << "\n";
}

int main(){
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}