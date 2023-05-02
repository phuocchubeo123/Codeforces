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
    int n; cin >> n;    
    vector<string> dp(n);
    for0(i, n) cin >> dp[i];
    if (dp[n - 1][n - 1] == '*'){
        cout << -1;
        return;
    }

    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            dp[i][j] = 0;
        }
    }

    dp[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            if (i - 1 >= 0) (dp[i - 1][j] += dp[i][j]) %= MOD;
            if (j - 1 >= 0) (dp[i][j - 1] += dp[i][j]) %= MOD;
        }
    }
    cout << dp[0][0];
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