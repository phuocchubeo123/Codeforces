#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 4, MOD = 998244353;
int T, n, a[N], cnt[N], first[N], eq_minus_two[N];
ll conti[N], pow_mod[N], pre[N], suf[N];

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // for (int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << "\n";
}

void init(){
    cnt[1] = 0;
    for (int i = 1; i <= n; i++){
        cnt[a[i]] = 0;
        if (a[i] >= 2) cnt[a[i] - 2] = 0;
        first[a[i]] = 0; first[a[i] + 2] = 0;
        conti[a[i]] = 0; conti[a[i] - 1] = 0;
        eq_minus_two[a[i]] = 0; eq_minus_two[a[i] + 2] = 0;
    }
}

void testCalSuf(){
    for (int i = 1; i <= n; i++) cout << suf[i] << " ";
    cout << "\n";
}

void calSuf(){
    for (int i = n; i >= 1; i--){
        suf[i] = eq_minus_two[a[i] + 2] + 1;
        cnt[a[i]]++;

        if (a[i] == 0 || a[i] == 1) continue;

        // cout << i << " " << a[i] << " " << cnt[a[i]] << " " << a[i] - 2 << " " << cnt[a[i] - 2]<< "\n";
        eq_minus_two[a[i]] = (eq_minus_two[a[i]] + pow_mod[cnt[a[i]] - 1 + cnt[a[i] - 2]]) % MOD;
        // cout << eq_minus_two[a[i]] << "\n";
    }
    // testCalSuf();
}

void testCalPre(){
    for (int i = 1; i <= n; i++) cout << pre[i] << " ";
    cout << "\n";
}

void calPre(){
    for (int i = 1; i <= n; i++){
        ll tot = (conti[a[i]] + conti[a[i] - 1]) % MOD;
        conti[a[i]] = (conti[a[i]] + tot) % MOD;
        pre[i] = tot;
        if (a[i] == 0){
            conti[a[i]] = (conti[a[i]] + 1) % MOD;
            pre[i] = (pre[i] + 1) % MOD;
        }
    }

    // testCalPre();
}

void solve(){
    init();
    calSuf();
    calPre();

    ll ans = (pow_mod[cnt[1]] - 1) % MOD;
    for (int i = 1; i <= n; i++){
        ans = (ans + pre[i] * suf[i]) % MOD;
    }
    cout << ans << "\n";
}

void calPowMod(){
    pow_mod[0] = 1;
    for (int i = 1; i < N; i++) pow_mod[i] = (pow_mod[i - 1] * 2) % MOD;
}

int main(){
    cin >> T;
    // T = 1;
    calPowMod();

    while (T--){
        read();
        solve();
    }
}