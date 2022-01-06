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
    int n; cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    auto digits = [](int x){
        vector<int> dgs;
        while (x > 0){
            dgs.push_back(x % 10);
            x /= 10;
        }
        return dgs;
    };
    for1(i, n){
        vector<int> dg = digits(i);
        dp[i] = 1e9;
        for0(j, dg.size()) dp[i] = min(dp[i], dp[i - dg[j]] + 1);
    }
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
}