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
    vt<int> v(n), t(n);
    for0(i, n) cin >> v[i];
    for0(i, n) cin >> t[i];
    vt<int> x(n);
    for0(i, n) x[i] = t[i] - v[i];

    vt<vt<int>> adj(n);
    for0(e, m){
        int i, j;
        cin >> i >> j;
        adj[i - 1].pb(j - 1);
        adj[j - 1].pb(i - 1);
    }

    bool tot = 0;
    for0(i, n) tot = tot ^ (x[i] & 1);
    if (tot == 1){
        cout << "NO\n";
        return;
    }

    vt<bool> vis(n, 0);
    vt<int> c(n);
    for0(i, n) c[i] = (-1) * i;

    bool flag = false;
    stack<int> s;
    s.push(0);
    while (!s.empty()){
        int curr = s.top(); s.pop();
        vis[curr] = 1;
        for (int next: adj[curr]){
            if (vis[next]){
                if (c[next] == c[curr]){
                    flag = true;
                    break;
                }
                else{
                    continue;
                }
            }
            else{
                c[next] = c[curr] ^ 1;
                s.push(next);
            }
        }
    }

    if (flag){
        cout << "YES\n";
        return;
    }

    else{
        ll red = 0, blue = 0;
        for0(i, n){
            if (c[i] == 0) red += 1ll * x[i];
            else blue += 1ll * x[i];
        }

        if (red == blue) cout << "YES\n";
        else cout << "NO\n";
    }
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