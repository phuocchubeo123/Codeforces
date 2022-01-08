#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

void solve(){
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size(); 
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));   
    for0(i, n + 1) dp[i][0] = i;
    for1(j, m){
        dp[0][j] = j;
        for1(i, n){
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    }
    // for0(i, n + 1){
    //     for0(j, m + 1) cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << dp[n][m];
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