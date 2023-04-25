#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4, MOD = 1e9 + 7;
int T;

void prepare(){

}

void solve(){
    int n; cin >> n;
    int sz = (n * (n + 1)) / 2;
    if (sz % 2 == 1){
        cout << 0;
        return;
    }

    sz /= 2;
    vt<vt<int>> dp(n + 1, vt<int> (sz + 1, 0));
    dp[1][1] = 1;
    for1(i, sz){
        for1(j, n - 1){
            (dp[j + 1][i] += dp[j][i]) %= MOD;
            if (i + j + 1 <= sz) (dp[j + 1][i + j + 1] += dp[j][i]) %= MOD;
        }
    }

    cout << dp[n][sz];
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