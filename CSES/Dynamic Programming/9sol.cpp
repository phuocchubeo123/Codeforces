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

void solve(){
    int n; cin >> n;
    vector<int> dp(n + 1);
    int pow_2 = 1;
    for1(i, n - 1) (pow_2 *= 2) %= MOD;
    dp[0] = pow_2;
    int tot = pow_2;
    for1(i, n){
        
    }
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