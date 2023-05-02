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
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int> (b + 1, 0));
    for1(i, a){
        dp[i][1] = i - 1;
        forlr(j, 2, b + 1, 1){
            if (i == j){
                dp[i][j] = 0;
                continue;
            }
            int minn = 1e9;
            forlr(slc, 1, i / 2 + 1, 1) minn = min(minn, dp[slc][j] + dp[i - slc][j] + 1);
            forlr(slc, 1, j / 2 + 1, 1) minn = min(minn, dp[i][slc] + dp[i][j - slc] + 1);
            dp[i][j] = minn;
        }
    }
    // for1(i, a){
    //     for1(j, b) cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << dp[a][b];
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