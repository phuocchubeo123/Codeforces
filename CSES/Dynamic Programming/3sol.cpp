#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e6 + 4, MOD = 1e9 + 7;
int T;

void prepare(){

}

int dp[N];

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for1(i, N) dp[i] = 0;
    for0(i, n){
        cin >> c[i];
        dp[c[i]] = 1;
    }
    for1(i, x){
        for0(j, n){
            if (i + c[j] <= x) dp[i + c[j]] = (dp[i] + dp[i + c[j]]) % MOD;
        }
    }

    // for1(i, x) cout << dp[i] << " ";
    // cout << "\n";
    cout << dp[x];
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