#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e6 + 4;
int T;

void prepare(){

}

int dp[N];

void solve(){
    int n, x; cin >> n >> x;
    for0(i, N) dp[i] = -1; 
    vector<int> coins(n);
    for0(i, n){
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    for1(i, x){
        if (dp[i] == -1) continue;
        for0(j, n){
            if (i + coins[j] <= x){
                if (dp[i + coins[j]] == -1) dp[i + coins[j]] = 1 + dp[i];
                else dp[i + coins[j]] = min(dp[i + coins[j]], 1 + dp[i]);
            }
        }
    }
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