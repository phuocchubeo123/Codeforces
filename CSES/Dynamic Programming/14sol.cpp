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

const ll LOW = -1e9 * 5000 - 5;
vector<ll> x;
ll dp[2][5000][5000];

void findAns(int s, int l, int r){
    if (dp[s][l][r] > LOW) return;

    if (l == r){
        dp[s][l][r] = (s == 1) ? x[l] : 0;
        return; 
    }

    findAns(1 ^ s, l + 1, r);
    findAns(1 ^ s, l, r - 1);
    if (s == 1) dp[s][l][r] = max(x[l] + dp[1 ^ s][l + 1][r], x[r] + dp[1 ^ s][l][r - 1]);
    else dp[s][l][r] = min(dp[1 ^ s][l + 1][r], dp[1 ^ s][l][r - 1]);

    return;
}

void solve(){
    for (int i = 0; i < 5000; i++){
        for (int j = 0; j < 5000; j++){
            for (int k = 0; k < 2; k++) dp[k][i][j] = LOW;
        }
    }

    int n;
    cin >> n;
    x.resize(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    findAns(1, 0, n - 1);

    cout << dp[1][0][n - 1];
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