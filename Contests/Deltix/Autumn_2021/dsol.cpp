#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e3 + 4;
int T, n, d, x[N], y[N], c[N], remain, vis[N], need[N];
queue<int> q;
vector<int> adj[N];
array<int, N> cnt;

void read(){
    cin >> n >> d;

    for (int i = 1; i <= d; i++){
        cin >> x[i] >> y[i];
    }
}

void solve(int j){
    remain = 0;
    int tot = 0;

    for (int i = 1; i <= n; i++) c[i] = 0;

    for (int i = 1; i <= n; i++){
        adj[i].clear();
    }

    for (int i = 1; i <= j; i++){
        adj[x[i]].push_back(y[i]);
        adj[y[i]].push_back(x[i]);
    }

    for (int i = 1; i <= n; i++) vis[i] = 0;

    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;

        tot++;

        while (!q.empty()) q.pop();
        q.push(i);

        while (!q.empty()){
            int curr = q.front(); q.pop();

            if (vis[curr]) continue;
            vis[curr] = 1;

            c[curr] = tot;

            for (int next: adj[curr]){
                q.push(next);
            }
        }

    }


    for (int i = 1; i <= n; i++) cout << c[i] << " ";
    cout << "\n";


    for (int i = 0; i < N; i++) cnt[i] = 0;

    for (int i = 1; i <= n; i++){
        if (c[i]) cnt[c[i]]++;
    }

    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());

    for (int i = 1; i < N; i++) need[i] = 0;
    for (int i = 1; i <= j; i++) need[c[x[i]]]++;

    for (int i = 1; i <= n; i++) cout << need[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    cout << "\n";

    for (int i = 1; i <= tot; i++) remain += need[i] - cnt[i] + 1;

    cout << "remain: " << remain << "\n";


    int ans = 0;

    for (int i = 0; i <= remain; i++){
        ans += cnt[i];
    }

    cout << ans - 1 << "\n";
}

int main(){
    read();

    for (int j = 1; j <= d; j++){
        solve(j);
    }
}