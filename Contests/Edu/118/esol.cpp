#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, m, r, c, nr, nc;
pair<int, int> lab, curr;
vector<vector<bool>> vis, can;
vector<vector<vector<pair<int, int>>>> adj;
vector<vector<int>> grid, order;
queue<pair<int, int>> q;

void read(){
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        grid.push_back({});
        string s; cin >> s;
        for (int j = 0; j < m; j++){
            if (s[j] == '.') grid[i].push_back(1);

            else if (s[j] == 'L'){
                grid[i].push_back(2);
                lab = {i, j};
            }

            else grid[i].push_back(0);
        }
    }
}

bool inGrid(int r, int c){
    return ((r >= 0 && r < n) && (c >= 0 && c < m));
}

void createGraph(){
    for (int i = 0; i < n; i++){
        adj.push_back({});
        order.push_back({});
        vis.push_back({});
        can.push_back({});

        for (int j = 0; j < m; j++){
            adj[i].push_back({});
            order[i].push_back(0);
            vis[i].push_back(0);
            can[i].push_back(0);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!grid[i][j]) continue;

            for (int rr = -1; rr <= 1; rr += 2){
                if (!inGrid(i + rr, j)){
                    continue;
                }

                if (grid[i + rr][j]){
                    adj[i][j].push_back({i + rr, j});
                    order[i][j]++;
                }
            }

            for (int rc = -1; rc <= 1; rc += 2){
                if (!inGrid(i, j + rc)){
                    continue;
                }

                if (grid[i][j + rc]){
                    adj[i][j].push_back({i, j + rc});
                    order[i][j]++;
                }
            }
        }
    }
}

void findDirectWay(){
    while (!q.empty()) q.pop();
    q.push(lab);

    while (!q.empty()){
        curr = q.front(); q.pop();
        r = curr.first; c = curr.second;

        // cout << r << " " << c << "\n";

        if (vis[r][c]) continue;

        for (auto next: adj[r][c]){
            nr = next.first; nc = next.second;

            order[nr][nc]--;
            if (order[nr][nc] <= 1){
                can[nr][nc] = 1;
                q.push(next);
            }
        }
        vis[r][c] = 1;
    }
}

void findIndirectWay(){

}

void solve(){
    createGraph();    

    // for (auto x: order){
    //     for (auto y: x) cout << y << " ";
    //     cout << "\n";
    // }

    findDirectWay();
    findIndirectWay();

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 0) cout << '#';
            else if (grid[i][j] == 2) cout << 'L';
            else{
                if (can[i][j]) cout << '+';
                else cout << '.';
            }
        }
        cout << "\n";
    }
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        grid.clear(); adj.clear(); vis.clear(); order.clear(); can.clear();
        read();
        solve();
    }
}