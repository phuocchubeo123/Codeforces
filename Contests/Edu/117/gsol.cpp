#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4, M = 1e6 + 4, P = 1e7 + 4, MOD = 1e9 + 7;
int T, m, c[M];
ll cnt[M], tot[M], factor[P];

void read(){
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> c[i];
    }
}

ll numPair(ll num){
    return ((num * (num + 1)) / 2) % MOD;
}

void solve(){
    for (int i = 0; i <= M - 1; i++) cnt[i] = 0;

    for (int i = 1; i <= m; i++){
        cnt[c[i] - 1] += 1; 
    }

    tot[M - 1] = cnt[M - 1];
    tot[M - 2] = cnt[M - 2];

    for (int i = M - 3; i >= 0; i--){
        tot[i] = tot[i + 2] + cnt[i];
    }   

    // for (int i = 0; i <= 10; i++) cout << cnt[i] << " ";
    // cout << "\n";
    // for (int i = 0; i <= 10; i++) cout << tot[i] << " ";

    ll now = 1;
    ll next = 0;
    ll ans = 0;
    ll num_way = 1;
    // cout << "\n";
    for (int i = -M + 1; i <= M - 1; i++){
        // cout << now << " ";
        next = now + tot[abs(i)];
        ll tot2 = (numPair(next - 1) - numPair(now - 1) + MOD) % MOD;
        if (i < 0){
            ans = (ans + ((i + MOD) * tot2) % MOD) % MOD;
        }
        else{
            ans = (ans + (i * tot2) % MOD) % MOD;
        }
        num_way = (num_way * factor[tot[abs(i)]]) % MOD;
        // cout << ans << "\n";
        now = now + tot[abs(i)];
    }

    cout << ans << " " << num_way;
}

void calFactor(){
    factor[0] = 1;
    for (int i = 1; i < P; i++){
        factor[i] = (i * factor[i - 1]) % MOD;
    }
}

int main(){
    // cin >> T;
    T = 1;

    for (int t = 0; t < T; t++){
        read();
        calFactor();
        // cout << factor[500000] << "\n";
        solve();
    }
}