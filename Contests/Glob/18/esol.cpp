#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, k, u, v, p[N], d[N], ml[N], cnt[N];
ll ans;
vector<int> adj[N], c[N];

void read(){
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void findDepth(int num){
    for (int x: c[num]){
        d[x] = d[num] + 1;
        findDepth(x);
    }
}

void findMaxLeaf(int num){
    ml[num] = num;
    for (int x: c[num]){
        findMaxLeaf(x);
        if (d[ml[x]] > d[ml[num]]) ml[num] = ml[x];
    }
}

void solve(){
    for (int i = 1; i <= n; i++) p[i] = -1;
    stack<int> s;
    s.push(1);

    while (!s.empty()){
        int curr = s.top(); s.pop();
        // cout << curr << "\n";
        for (int next: adj[curr]){
            if (next != p[curr]){
                s.push(next); 
                p[next] = curr;
                c[curr].push_back(next);
            } 
        }
    }

    vector<int> childs;
    for (int i = 1; i <= n; i++){
        if (c[i].empty()) childs.push_back(i);
    }

    if (k >= childs.size()){
        // cout << "right\n";
        // cout << childs.size() << " " << k << "\n";
        ans = 0;
        for (int i = childs.size(); i <= k; i++){
            // cout << i * (n - i) << "\n";
            ans = max(ans, 1ll * i * (n - i));
        }
        cout << ans << "\n";
        return;
    }

    findDepth(1);
    // for (int i = 1; i <= n; i++) cout << d[i] << " ";
    // cout << "\n";

    findMaxLeaf(1);
    // for (int i = 1; i <= n; i++) cout << ml[i] << " ";

    for (int i = 1; i <= n; i++) cnt[ml[i]]++;
    sort(cnt + 1, cnt + n + 1);
    reverse(cnt + 1, cnt + n + 1);
    int white = 0;
    for (int i = 1; i <= k; i++) white += cnt[i];

    if (n - white <= k){
        cout << 1ll * (white - k) * (k - n + white) << "\n";
        return;
    }

    ans = 0;
    for (int i = 0; i <= n - k - white; i++){
        ans = min(ans, 1ll * (white - k + i) * (k - n + white + i));
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}