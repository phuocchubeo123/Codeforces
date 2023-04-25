#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4, LOG = 18;
int T, n, k, x[N], u, v, p[N], d[N], pp[N][LOG], fc[N], f[N];
vector<int> adj[N], c[N];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void read(){
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        adj[i].clear();
        c[i].clear();
        p[i] = 0;
        f[i] = 0;
        fc[i] = 0;
    }

    for (int i = 1; i <= k; i++){
        cin >> x[i];
    }

    for (int i = 1; i <= n - 1; i++){
        cin >> v >> u;
        addEdge(v, u);
    }
}

void testFindParentChild(){
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        for (int j: c[i]) cout << j << " ";
        cout << "\n";
    }
}

void findParentChild(){
    queue<int> q;
    q.push(1);
    p[1] = 1;

    while (q.size() > 0){
        int curr = q.front(); q.pop();
        for (int next: adj[curr]){
            if (!p[next]){
                c[curr].push_back(next);
                p[next] = curr;
                q.push(next);
            }
        }
    }

    // testFindParentChild();
}

void testFindDistance(){
    for (int i = 1; i <= n; i++) cout << d[i] << " ";
}

void findDistance(){
    queue<int> q;
    q.push(1);
    d[1] = 0;
    
    while (q.size() > 0){
        int curr = q.front(); q.pop();
        for (int child: c[curr]){
            q.push(child);
            d[child] = d[curr] + 1;
        }
    }

    // testFindDistance();
}

void calLCA(){
    for (int i = 0; i < LOG; i++){
        for (int j = 0; j <= n; j++) pp[j][i] = 0;
    }

    for (int j = 1; j <= n; j++){
        if (p[j]) pp[j][0] = p[j];
    }

    for (int i = 0; i < LOG - 1; i++){
        for (int j = 1; j <= n; j++){
            if (pp[pp[j][i]][i]) pp[j][i + 1] = pp[pp[j][i]][i];
        }
    }
}

int la(int node, int dis){
    int ancestor = node;

    for (int i = 0; i < LOG; i++){
        if ((dis >> i) & 1 == 1) ancestor = pp[ancestor][i];
    }

    return ancestor;       
}

void testFindHalfWayAncestor(){
    cout << la(5, 3);
}

void findHalfWayAncestor(){
    calLCA();

    for (int i = 1; i <= k; i++){
        x[i] = la(x[i], d[x[i]] / 2);
    }

    // testFindHalfWayAncestor();
}

void testFindOptimalFriends(){
    for (int i = 1; i <= n; i++) cout << fc[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << f[i] << " ";
}

void findOptimalFriends(){
    for (int i = 1; i <= k; i++) f[x[i]] = 1;

    queue<int> q;
    q.push(1);

    while (q.size()){
        int curr = q.front(); q.pop();

        if (fc[curr]){
            for (int child: c[curr]){
                fc[child] = 1;
                q.push(child);
            }
        }

        else{
            for (int child: c[curr]){
                fc[child] = f[curr];
                q.push(child);
            }
        }
    }

    for (int i = 1; i <= k; i++){
        if (fc[x[i]]) f[x[i]] = 0;
    }

    // testFindOptimalFriends();
}

void findLeaves(){
    int ans = 0;
    for (int i = 1; i <= n; i++) if (f[i]){
        ans++;
        fc[i] = 1;
    }

    for (int i = 1; i <= n; i++){
        if (c[i].size()) continue;

        if (!fc[i]){
            // cout << i << "YES" << "\n";
            cout << -1 << "\n";
            return;
        }
    }

    cout << ans << "\n";
}

void solve(){
    findParentChild();
    findDistance();
    findHalfWayAncestor();
    findOptimalFriends();
    findLeaves();
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}