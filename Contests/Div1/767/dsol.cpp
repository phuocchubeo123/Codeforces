#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e6 + 4, MOD = 1e9 + 7;
int T;

struct mint{
    int val;

    mint(){
        val = 0;
    }

    mint(int x){
        while (x >= MOD) x -= MOD;
        while (x < 0) x += MOD;
        val = x;
    }

    bool operator==(const mint& other){
        return val == other.val;
    }

    mint operator+(const mint& other){
        return mint(val + other.val);
    }

    mint operator-(const mint& other){
        return mint(val - other.val);
    }

    mint operator*(const mint& other){
        return mint((val * 1ll * other.val) % MOD);
    }

    mint pow(int y){
        mint z(1);
        mint x(val);
        while (y > 0){
            if (y % 2 == 1) z = z * x;
            x = x * x;
            y /= 2;
        }
        return z;
    }

    mint operator/(const mint& other){
        return mint(val) * mint(other.val).pow(MOD - 2);
    }
};

mint pow_mod[N];

void calPowMod(){
    pow_mod[0] = mint(1);
    for (int i = 1; i < N; i++) pow_mod[i] = pow_mod[i - 1] * mint(2);
}

mint factor_mod[N];

void calFactor(){
    factor_mod[0] = mint(1);
    for (int i = 1; i < N; i++) factor_mod[i] = factor_mod[i - 1] * mint(i);
}

void prepare(){
    calPowMod();
    calFactor();
}

mint binom(int x, int y){
    return factor_mod[x] / (factor_mod[y] * factor_mod[x - y]);
}

vt<int> dp(N);

void solve(){
    int n, m, k;
    cin >> n >> m >> k; 
    dp[0] = 0;
    dp[1] = 1;

    if (m == n){
        cout << (mint(k) * mint(n)).val << "\n";
        return;
    }

    forlr(i, 2, m + 1, 1){
        dp[i] = (mint(4) * mint(dp[i - 1]) - mint(4) * mint(dp[i - 2]) + binom(n - m + i - 2, n - m - 1)).val;
    }

    cout << ((mint(dp[m]) / pow_mod[n - 1]) * mint(k)).val << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        solve();
    }
}