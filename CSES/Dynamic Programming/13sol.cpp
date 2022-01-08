#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e5 + 4;
int T;

void prepare(){

}

void solve(){
    int n; cin >> n;
    vector<int> x(n + 1);
    for1(i, n) cin >> x[i];
    sort(x.begin() + 1, x.begin() + n + 1);
    // for1(i, n) cout << x[i] << " ";
    // cout << "\n";

    vector<vector<bool>> dp(n + 1, vector<bool> (N, 0));
    dp[0][0] = 1;
    for0(i, N){
        for0(j, n){
            if (dp[j][i] == 0) continue;
            forlr(k, j + 1, n + 1, 1){
                dp[k][i] = 1;
                if (i + x[k] <= 1e5) dp[k][i + x[k]] = 1;
            }
        }
    }
    int cnt = 0;
    for1(i, 1e5) if (dp[n][i]) cnt++;
    cout << cnt << "\n";
    for1(i, 1e5) if (dp[n][i]) cout << i << " ";
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