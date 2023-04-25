#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4, LOG = 31;
int T, n, m, a, b, p, x[N], y[N], v[N], vis[N], ps[N];
bool flag;
vector<pair<int, int>> adj[N];
stack<int> s;

void read(){
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++){
        cin >> x[i] >> y[i] >> v[i];
        if (v[i] != -1){
            int cnt = 0;
            for (int j = 0; j < LOG; j++){
                if ((v[i] >> j) & 1 == 1) cnt++;
            }
            if (cnt % 2 == 0){
                adj[x[i]].push_back({y[i], 0});
                adj[y[i]].push_back({x[i], 0});
            }
            else{
                adj[x[i]].push_back({y[i], 1});
                adj[y[i]].push_back({x[i], 1});
            }
        }
    }

    for (int i = 0; i < m; i++){
        cin >> a >> b >> p;
        adj[a].push_back({b, p});
        adj[b].push_back({a, p});
    }
}

void dfs(int num){

    if (vis[num]) return;;

    ps[num] = 0;
    while (!s.empty()) s.pop();
    s.push(num);
    while (!s.empty()){
        int curr = s.top(); s.pop();
        
        for (pair<int, int> pr: adj[curr]){
            int next = pr.first, pd = pr.second;
            if (ps[next] == -1){
                ps[next] = ps[curr] ^ pd;
                vis[next] = 1;
                s.push(next);
            }

            else{
                if (ps[next] != ps[curr] ^ pd){
                    flag = false;
                    return;
                }

                if (vis[next]) continue;
                else{
                    s.push(next);
                    vis[next] = 1;
                }
            }
        }
    }
}

void solve(){
    // for (int i = 1; i <= n; i++){
    //     cout << i << ":\n";
    //     for (auto x: adj[i]) cout << x.first << ", " << x.second << "; ";
    //     cout << "\n";
    // }
    for (int i = 1; i <= n; i++){
        vis[i] = 0;
        ps[i] = -1;
    }

    flag = true;

    for (int i = 1; i <= n; i++){
        dfs(i);
        if (!flag){
            cout << "NO\n";
            return;
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (ps[i] == -1) ps[i] = 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n - 1; i++){
        cout << x[i] << " " << y[i] << " ";
        if (v[i] != -1) cout << v[i] << "\n";
        else cout << (ps[x[i]] ^ ps[y[i]]) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
        for (int i = 1; i <= n; i++){
            adj[i].clear();
        }
    
    }
}