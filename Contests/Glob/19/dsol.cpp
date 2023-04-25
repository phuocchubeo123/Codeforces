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
    int n; cin >> n;
    vt<int> a(n), b(n);
    for0(i, n) cin >> a[i];
    for0(i, n) cin >> b[i];
    vt<vt<int>> dp(2 * n * 100 + 1, vt<int>(n, 0));
    for0(j, 2 * n * 100 + 1){
        if (j == a[0] || j == b[0]) dp[j][0] = 1;
    }

    for0(i, n - 1){
        for0(j, 2 * n * 100 + 1){
            if (dp[j][i] == 1){
                if (j + a[i + 1] <= 2 * n * 100) dp[j + a[i + 1]][i + 1] = 1;
                if (j + b[i + 1] <= 2 * n * 100) dp[j + b[i + 1]][i + 1] = 1;
            }
        }
    }

    ll ans = 1e9 + 4;
    ll tot = 0;
    for0(i, n) tot += 1ll * (a[i] + b[i]);
    for0(i, 2 * n * 100 + 1){
        if (dp[i][n - 1] == 1){
            ans = min(ans, (1ll * (i * i) + 1ll * (tot - i) * (tot - i)));
        }
    }

    ll tot2 = 0;
    for0(i, n) tot2 += 1ll * (a[i] * a[i] + b[i] * b[i]);
    cout << ans + (n - 2) * tot2 << "\n";
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