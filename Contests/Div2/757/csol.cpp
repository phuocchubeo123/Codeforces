#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
const ll MOD = 1e9 + 7;
int T;
ll ans1, n, m, l, r, x, ans, powMod[N];
vector<pair<pair<ll, ll>, ll>> a;
vector<pair<int, int>> b[31];

void read(){
    for (int i = 0; i <= 30; i++) b[i].clear();
    cin >> n >> m;
    ans1 = 0;
    for (ll i = 1; i <= m; i++){
        cin >> l >> r >> x;
        ans1 = (ans1 | x);
    }
}

void calPowMod(){
    powMod[0] = 1;
    for (int i = 1; i < N; i++){
        powMod[i] = (powMod[i - 1] * 2) % MOD;
    }
}

void solve(){
    // cout << "lmao " << ans1 << "\n";
    ans = 0;
    for (int i = 0; i <= 30; i++){
        if ((ans1 >> i) & 1 == 1){
            ans = (ans + (powMod[i] * powMod[n - 1])) % MOD;
        }
    } 
    cout << ans << "\n";
}

int main(){
    calPowMod();
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}