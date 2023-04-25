#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
int T, n = 1, u, v, odd, even;
vector<int> adj[N];
stack<int> odd_s, even_s, s;
int new_pos[N];
bool visited[N], deg[N];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void read(){
    while (!s.empty()) s.pop();
    cin >> n;
    for (int i = 1; i <= n; i++){
        adj[i].clear();
    }

    for (int i = 0; i < n - 1; i++){
        cin >> u >> v;
        addEdge(u, v);
    }
}

void findDeg(){
    s.push(1);
    for (int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    while (!s.empty()){
        int curr = s.top(); s.pop();
        // cout << "curr: " << curr << "\n";
        for (int dest: adj[curr]){
            if (!visited[dest] && dest != curr){
                // cout << "dest: " << dest << "\n";
                deg[dest] = deg[curr] ^ 1;
                s.push(dest);
            }
        }
        visited[curr] = 1;
    }

    odd = 0; even = 0;
    while (!odd_s.empty()) odd_s.pop();
    while (!even_s.empty()) even_s.pop();

    for (int i = 1; i <= n; i++){
        if (deg[i] == 1){
            odd++;
            odd_s.push(i);
            // cout << i << " odd\n";
        }

        else{
            even++;
            even_s.push(i);
            // cout << i << " even\n";
        }
    }
}

void findReplacement(){
    int max_i = 0;
    for (int i = 0; (1 << (i + 1)) <= 2 * n; i++){
        max_i = i;
    }

    for (int i = max_i; i >= 0; i--){
        // cout << (1 << i) << "\n";
        // cout << odd << " " << even << "\n";
        if (odd >= even){
            for (int j = (1 << i); j <= min((1 << (i + 1)) - 1, n); j++){
                int ori = odd_s.top(); odd_s.pop(); odd--;
                new_pos[ori] = j;
            }
        }

        else{
            for (int j = (1 << i); j <= min((1 << (i + 1)) - 1, n); j++){
                int ori = even_s.top(); even_s.pop(); even--;
                new_pos[ori] = j;
            }
        }
    }
}

void solve(){
    findDeg();
    findReplacement();
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        read();

        // cout << "edges\n";
        // for (int i = 1; i <= n; i++){
        //     for (auto j: adj[i]) cout << i << " " << j << "\n";
        // }
        solve();

        for (int i = 1; i <= n; i++){
            cout << new_pos[i] << " ";
        }
        cout << "\n";
    }
}