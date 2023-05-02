#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
const ll MOD = 998244353;
int T, n, w, b, num_qs[3] = {0, 0, 0};
bool has_all = false, has_bw = false, has_wb = false;
string s;
ll rev_fact[N];

void preprocess(){
    if (s == "WW" || s == "BB") has_all = true;
    else if (s == "BW" || s == "B?" || s == "?W") has_bw = true;
    else if (s == "WB" || s == "W?" || s == "?B") has_wb = true;

    int qs = 0;

    for (char c: s){
        if (c == 'W') w--;
        else if (c == 'B') b--;
        else qs++;
    }

    num_qs[qs]++;
}

void read(){
    cin >> n;
    w = n; b = n;

    for (int i = 1; i <= n; i++){
        cin >> s;
        preprocess();
    }
}

ll revMod(ll x){
    ll rev = 1;
    for (ll i = 32; i >= 0; i--){
        if ((((MOD - 2) >> i) & 1) == 0) rev = (rev * rev) % MOD;
        else rev = ((rev * rev) % MOD * x) % MOD;
    }

    return rev;
}

ll fact(ll x){
    if (x == 0) return 1;
    return (x * fact(x - 1)) % MOD;
}

ll powMod(ll x){
    if (x == 0) return 1;
    return (2 * powMod(x - 1)) % MOD;
}

void solve(){
    if (w < 0 || b < 0){
        // cout << "one\n";
        cout << 0;
        return;
    }

    // cout << w << " " << b << "\n";
    // cout <<(revMod(fact(w)) * revMod(fact(b))) % MOD << "\n";

    ll ans = (fact(w + b) * ((revMod(fact(w)) * revMod(fact(b))) % MOD)) % MOD;
    // cout << "first ans: " << ans << "\n";

    if (has_all){
        // cout << "two\n";
        cout << ans;
        return;
    }

    // cout << powMod(num_qs[2]) << "\n";
    ans = (ans - powMod(num_qs[2]) + MOD) % MOD;

    if (has_bw && has_wb) ans += 0;
    else if (has_bw || has_wb) ans++;
    else ans += 2;

    cout << ans;
    return;
}

int main(){
    // cin >> T;
    T = 1;

    // cout << revMod(3) << "\n";
    // cout << fact(6) << "\n";

    while (T--){
        read();
        solve();
    }
}