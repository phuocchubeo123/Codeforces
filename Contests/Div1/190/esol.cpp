#pragma GCC optimize("O3")
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const int maxn = 4005;
 
int n, k;
int u[maxn][maxn];
int u1[maxn][maxn];
int dp[maxn][maxn];
int best[maxn][maxn];
int cost[maxn][maxn];
 
void dac(int u, int l, int r, int st, int en){
    int m = (l + r) / 2;
 
    for (int i = st; i < min(m, en+1); i++){
        if (dp[i][u-1] + cost[i+1][m] < dp[m][u]){
            dp[m][u] = dp[i][u-1] + cost[i+1][m];
            best[m][u] = i;
        }
    }
 
    if (m > l) dac(u, l, m-1, st, best[m][u]);
    if (m < r) dac(u, m+1, r, best[m][u], en);
}
 
void solve(){
    cin >> n >> k;
 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) cin >> u[i][j];
    }
 
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) u1[i][j] = 0;
 
    u1[1][1] = u[1][1];
 
    for (int i = 2; i <= n; i++) u1[1][i] = u1[1][i-1] + u[1][i];
 
    for (int i = 1; i <= n; i++){
        u1[i][1] = u1[i-1][1] + u[i][1];
        for (int j = 2; j <= n; j++){
            u1[i][j] = u1[i-1][j] + u1[i][j-1] - u1[i-1][j-1] + u[i][j];
        }
    }
 
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++) cost[i][j] = u1[j][j] - u1[i-1][j] - u1[j][i-1] + u1[i-1][i-1];
    }
 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++) dp[i][j] = 4000 * 4000 * 9 + 5;
    }
 
    for (int i = 1; i <= n; i++){
        dp[i][1] = cost[1][i];
    }
 
    for (int i = 2; i <= k; i++){
        dac(i, 1, n, 1, n);
    }
 
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= k; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
 
    cout << dp[n][k] / 2 << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    solve();
}