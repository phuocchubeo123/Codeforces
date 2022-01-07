#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e6 + 4, MOD = 1e9 + 7;
int T;

int dp[N + 10];

void prepare(){
    for1(i, N) dp[i] = 0;
    for1(i, 6) dp[i] = 1;
    for1(i, N){
        for1(j, 6) dp[i + j] = (dp[i + j] + dp[i]) % MOD;
        // cout << dp[i];
    }
}


void solve(){
    int n; cin >> n;
    cout << dp[n];
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
    return 0;
}