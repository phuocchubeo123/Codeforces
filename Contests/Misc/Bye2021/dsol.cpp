#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, x, a[N], d[N], dp[N][3];
vector<int> pos;

void prepare(){

}

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> x;
}

void solve(){
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;

    if (n == 1){
        cout << 1 << "\n";
        return;
    }

    dp[2][0] = 1;
    dp[2][1] = 1;
    if (a[1] + a[2] < 2 * x) dp[2][2] = 1;
    else dp[2][2] = 2;

    if (n == 2){
        cout << dp[2][2] << "\n";
        return;
    }

    dp[3][0] = dp[2][2];
    dp[3][1] = max(1 + dp[1][2], dp[3][0]);

    if (a[3] + a[2] < 2 * x) dp[3][2] = dp[3][1];
    else{
        if (a[3] + a[2] + a[1] < 3 * x || a[2] + a[1] < 2 * x) dp[3][2] = max(dp[3][1], 2);
        else{
            dp[3][2] = dp[2][2] + 1;
        }
    }

    if (n == 3){
        cout << dp[3][2] << "\n";
        return;
    }

    for (int i = 4; i <= n; i++){
        dp[i][0] = dp[i - 1][2];
        dp[i][1] = max(1 + dp[i - 2][2], dp[i][0]);

        if (a[i] + a[i - 1] < 2 * x) dp[i][2] = dp[i][1];
        else{
            if (a[i] + a[i - 1] + a[i - 2] < 3 * x || a[i - 1] + a[i - 2] < 2 * x) dp[i][2] = max(dp[i][1], 2 + dp[i - 3][2]);
            else dp[i][2] = dp[i - 1][2] + 1;
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j <= 2; j++) cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << dp[n][2] << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}