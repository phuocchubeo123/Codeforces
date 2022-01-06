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
    int n, x; 
    cin >> n >> x;
    vector<int> h(n), s(n);
    for0(i, n) cin >> h[i];
    for0(i, n) cin >> s[i];
    vector<vector<int>> dp(n, vector<int> (x + 1, 0));
    for0(i, x){
        for0(j, n){
            if (j + 1 < n) dp[j + 1][i] = max(dp[j][i], dp[j + 1][i]);
            if (i + h[j + 1] <= x) dp[j + 1][i + h[j + 1]] = max(dp[j + 1][i + h[j + 1]], dp[j][i] + s[j]);
        }
    }
    cout << dp[n - 1][x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}