#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4, MOD = 1e9 + 7;
int T;

void prepare(){

}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> x(n + 1);
    for1(i, n) cin >> x[i];
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    if (x[1] == 0) for1(j, m) dp[1][j] = 1;
    else dp[1][x[1]] = 1;
  
    for1(i, n){
        if (x[i] == 0){
            for1(j, m){
                if (j - 1 >= 1) (dp[i][j] += dp[i - 1][j - 1]) %= MOD;
                (dp[i][j] += dp[i - 1][j]) %= MOD;
                if (j + 1 <= m) (dp[i][j] += dp[i - 1][j + 1]) %= MOD;
            }
        }
        else{
            for1(j, m){
                if (j != x[i]) dp[i][j] = 0;
                else{
                    if (j - 1 >= 1) (dp[i][j] += dp[i - 1][j - 1]) %= MOD;
                    (dp[i][j] += dp[i - 1][j]) %= MOD;
                    if (j + 1 <= m) (dp[i][j] += dp[i - 1][j + 1]) %= MOD;
                }
            }
        }
    }
    
    int tot = 0;
    for1(i, m) (tot += dp[n][i]) %= MOD;
    cout << tot;
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