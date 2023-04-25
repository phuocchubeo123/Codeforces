#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

vt<int> adj[N], c[N];
int p[N], dis[N];

void findDis(int i){
    for (int x: c[i]){
        dis[x] = dis[i] + 1;
        findDis(x);
    }
}

void solve(){
    int n;
    cin >> n;
    for1(i, n) adj[i].clear();
    int u, v;
    for0(i, n - 1){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    stack<int> s;
    for1(i, n) c[i].clear();
    for1(i, n) p[i] = -1;
    s.push(1);
    while (!s.empty()){
        int curr = s.top(); s.pop();
        for (int next: adj[curr]){
            if (p[curr] != next){
                c[curr].pb(next);
                p[next] = curr;
                s.push(next);
            }
        }
    }

    for1(i, n) dis[i] = 0;
    findDis(1);

    sort(dis + 1, dis + n + 1);
    reverse(dis + 1, dis + n + 1);
    int mx = 0;

    // for1(i, n) mx = max(mn, dis[i]);

    for1(i, n){
        if (dis[1] <= i) cout << dis[1] << " "; 
        else{
            cout << max(dis[2], i) << " ";
        }
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        solve();
    }
}