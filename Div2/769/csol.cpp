#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 4e5 + 4;
int T, ans[N], bor[N], borinv[N], vis[N];

void prepare(){

}

void dfs(int n){
    if (vis[n]) return;

    vis[n] = 1;

}

void solve(){
    int a, b;
    cin >> a >> b;
    int x = 0;
    while (x < b) x = 2 * (x + 1) - 1;

    vt<int> can;
    can.pb(b);
    for0(i, 22){
        // cout << ((b >> i) & 1);
        if (((b >> i) & 1) == 0){
            // cout << i << " ";
            can.pb(((b >> i) | 1) << i);
            // can.pb((b >> (i + 1)) << (i + 1));
        } 
    }

    int ans = b - a;
    forlr(i, a, b, 1){
        for (int x: can){
            ans = min(ans, (i | x) + i - a - b + 1);
        }
    }

    cout << ans << "\n";
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