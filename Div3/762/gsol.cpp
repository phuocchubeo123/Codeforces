#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, k, color, x[N], y[N], t[N], vis[N], c[N], et[N];
map<int, vector<pair<int, int>>> X, Y;
set<int> xs, ys;
vector<int> adj[N];
stack<int> s;

void read(){
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> t[i];
    }

    // for (int i = 0; i < n; i++) cout << i << " " << x[i] << " " << y[i] << " " << t[i] << "\n";
}

void splitRowCol(){
    X.clear(); Y.clear(); xs.clear(); ys.clear(); 

    for (int i = 0; i < n; i++){
        X[x[i]].push_back({y[i], i});
        Y[y[i]].push_back({x[i], i});
        xs.insert(x[i]);
        ys.insert(y[i]);
    }

    // for (auto &xx: X){
    //     cout << xx.first << "\n";
    //     for (auto yy: xx.second) cout << yy.first << " ";
    //     cout << "\n";
    // }
}

void createGraph(){
    for (int i = 0; i < n; i++) adj[i].clear();

    for (int xx: xs){
        sort(X[xx].begin(), X[xx].end());
        for (int i = 0; i < X[xx].size() - 1; i++){
            if (X[xx][i + 1].first - X[xx][i].first <= k){
                adj[X[xx][i + 1].second].push_back(X[xx][i].second);
                adj[X[xx][i].second].push_back(X[xx][i + 1].second);
            }
        }
    }

    for (int yy: ys){
        sort(Y[yy].begin(), Y[yy].end());
        for (int i = 0; i < Y[yy].size() - 1; i++){
            if (Y[yy][i + 1].first - Y[yy][i].first <= k){
                adj[Y[yy][i + 1].second].push_back(Y[yy][i].second);
                adj[Y[yy][i].second].push_back(Y[yy][i + 1].second);
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //     cout << i << "\n";
    //     for (int j: adj[i]) cout << j << " ";
    //     cout << "\n";
    // }
}

void findConnectedComponents(){
    for (int i = 0; i < n; i++) vis[i] = 0;

    color = 0;
    for (int i = 0; i < n; i++){
        if (vis[i]) continue;
        color++;

        while (!s.empty()) s.pop();
        s.push(i);
        while (!s.empty()){
            int curr = s.top(); s.pop();

            if (vis[curr]) continue;
            vis[curr] = 1;

            c[curr] = color;
            
            for (int next: adj[curr]) s.push(next);
        }
    }

    // for (int i = 0; i < n; i++) cout << c[i] << " ";
}

void findTimes(){
    for (int i = 1; i <= color; i++) et[i] = 1e9 + 2;

    for (int i = 0; i < n; i++){
        et[c[i]] = min(et[c[i]], t[i]);
    }

    sort(et + 1, et + color + 1);

    // for (int i = 1; i <= color; i++) cout << et[i] << " ";
}

void solve(){

    splitRowCol();
    createGraph();
    findConnectedComponents();
    findTimes();

    int pt = color;
    for (int i = 0; i < color; i++){
        pt--;
        if (pt == 0){
            cout << i << "\n";
            return;
        }

        if (i >= et[pt]){
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}