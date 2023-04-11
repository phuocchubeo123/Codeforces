#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int xs, ys, xd, yd;
int B, C0;
int T, N;
array<int, 105> C;
array<int, 1005> x, y;
array<int, 1005> cost;
int l, j, m;
array<vector<pair<int, int>>, 1005> adj;
pair<int, int> curr;
array<int, 1005> d;
array<bool, 1005> visited;
priority_queue<pair<int, int>> q;
bool has_edge[1005][1005];
int i;

int dist(int i, int j){
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) - 1) + 1;
}

void addEdge(int i, int j, int m){
    int c = C[m] * dist(i, j);
    adj[i].push_back({j, c});
    adj[j].push_back({i, c});
    has_edge[i][j] = 1;
    has_edge[j][i] = 1;
}

void clearVars(){
    for (int i = 0; i <= 1005; i++) has_edge[i][i] = 1;
    for (int i = 0; i <= 1005; i++) adj[i].clear();
    for (int i = 0; i <= 1005; i++) visited[i] = false;
}

void read(){
    cin >> xs >> ys;
    cin >> xd >> yd;
    cin >> B;
    cin >> C[0];
    cin >> T;
    for (i = 1 ; i <= T; i++){
        cin >> C[i];
    }

    cout << "cost: ";
    for (i = 0; i <= T; i++){
    cout << C[i] << " ";
    }
    cout << "\n";
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> l;
        for (int k = 0; k < l; k++){
            cin >> j >> m;
            addEdge(i, j, m);
        }

        // cout << i << ": ";
        // for (j = 0; j <= N + 1; j++){
        //     cout << has_edge[i][j] << " ";
        // }
        // cout << "\n";

        // cout << "\n";
    }

    x[N] = xs; y[N] = ys; x[N+1] = xd; y[N+1] = yd;

    for (i = 0; i <= N + 1; i++){
        for (j = 0; j <= N + 1; j++){
            if (j != i && has_edge[i][j] == 0){
                addEdge(i, j, 0);
            }
        }
    }
}

void update(pair<int, int> dest){
    j = dest.first;
    if (visited[j]) return;

    int new_cost = curr.second + dest.second;
    int new_dist = d[i] + dist(i, j);

    if (new_dist >= B) return;

    if (cost[j] > new_cost){
        cost[j] = new_cost;
        d[j] = new_dist;
    }

    if (cost[j] == new_cost){
        if (d[j] > new_dist){
            d[j] = new_dist;
        }
    }

    q.push({j, cost[j]});
}

void solve(){
    cost[N] = 0;

    q.push({N, 0});

    while (q.size() > 0){
        curr = q.top(); q.pop();
        cout << curr.first << "\n";
        i = curr.first; 
        if (i == N+1){
            cout << cost[N + 1] << "\n";
            return;
        }

        for (auto dest: adj[i]){
            update(dest);
        }
        visited[i] = true;
    }
}

int main(){
    // cin >> T;
    // T = 1;

    for (int t = 0; t < 1; t++){
        clearVars();
        read();


        for (i = 0; i <= N + 1; i++){
            for (auto y: adj[i]){
                cout << y.first << ", " << y.second << "; ";
            }
            cout << "\n";
        }
        solve();
    }
}