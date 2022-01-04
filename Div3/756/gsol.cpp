#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, m;
string s;
vector<vector<bool>> grid, vis;
set<pair<int, int>> is_one;
stack<pair<pair<int, int>, pair<int, int>>> stk;
pair<pair<int, int>, pair<int, int>> p;
pair<int, int> node, parent;

void read(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        grid.push_back({});
        vis.push_back({});
        cin >> s;
        for (int j = 0; j < m; j++){
            vis[i].push_back(0);
            if (s[j] == '1'){
                grid[i].push_back(1);
                is_one.insert({i, j});
            }
            else{
                grid[i].push_back(0);
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++) cout << grid[i][j] << " ";
    //     cout << "\n";
    // }
}

bool one(pair<int, int> node){
    return grid[node.first][node.second];
}

bool in_grid(int x, int y){
    return (x < n && x >= 0) && (y < m && y >= 0);
}

void solve(){
    int ans = 0;
    while (!is_one.empty()){
        pair<int, int> curr = *(is_one.begin());
        is_one.erase(curr);

        cout << curr.first << " " << curr.second << "\n";
        while (!stk.empty()) stk.pop();
        stk.push({curr, curr});
        bool matched = false;

        while (!stk.empty()){
            p = stk.top(); stk.pop();
            node = p.first;
            parent = p.second;

            cout << "node: " << node.first << " " << node.second << ", parent: " << parent.first << " " << parent.second << "\n";

            if (parent != curr){
                cout << "end" << vis[node.first][node.second] << "\n";
                break;
            }

            if (vis[node.first][node.second]) continue;

            vis[node.first][node.second] = 1;

            if (one(node)){
                curr = node;
                is_one.erase(node);
            }

            // cout << "push " << node.second + 1 << " ";
            if (in_grid(node.first + 1, node.second + 1)){
                stk.push({{node.first + 1, node.second + 1}, curr});
            }

            // cout << "push " << node.second - 1 << " ";
            if (in_grid(node.first + 1, node.second - 1)){
                stk.push({{node.first + 1, node.second - 1}, curr});
            }
            // cout << "\n";
        }
        ans++;
    }

    cout << ans << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        grid.clear(); vis.clear();
        read();
        solve();
    }
}