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

void solve(){
    int n, m;
    cin >> n >> m;
    vt<vt<int>> adj(n+1);
    for0(i, m){
        int x, y;
        cin >> x >> y;
        if (x == n || y == n) continue;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vt<int> ans(n+1);
    for1(i, n) ans[i] = 1;

    vt<int> vis(n);
    stack<int> st;
    st.push(n-1);
    while (!st.empty()){
        int curr = st.top(); st.pop();
        vis[curr] = 1;
        ans[curr] = 0;
        for (int next: adj[curr]){
            if (vis[next]) continue;
            st.push(next);
        }
    }

    for1(i, n){
        if (ans[i]) cout << "A";
        else cout << "B";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}