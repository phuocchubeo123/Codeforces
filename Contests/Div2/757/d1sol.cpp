#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e7 + 4, M = 1e5 + 4;
int T, n, a, cnt[N], maxx, k, prm[N], prm_cnt;
ll dp[N], nmaxx;
bool is_prm[N];

void read(){
    for (int i = 0; i < N; i++) cnt[i] = 0;
    cin >> n;
    // cout << n << "\n";
    for (int i = 1; i <= n; i++){
        cin >> a;
        // cout << a << "\n";
        cnt[a]+=1;
    }
    
    bool flag = false;
    for (int i = 0; i < prm_cnt; i++){
        // cout << prm[i] << "\n";
        for (int j = ((N - 1) / prm[i]); j >= 1; j--){
            cnt[j] += cnt[j * prm[i]];
        }
        
        // if (cnt[6] != 1 && flag == false){
        //     cout << 6 * prm[i] * prm[i] << "\n";
        //     cout << cnt[6 * prm[i]] << "\n";
        //     flag = true;
        // }
    } 

    // cout << cnt[6] << "\n";
}

void findPrime(){
    for (int i = 2; i < N; i++) is_prm[i] = 1;
    for (int i = 2; i < N; i++){
        if (!is_prm[i]){
            continue;
        }

        prm[prm_cnt++] = i;
        for (int j = 2; j * i < N; j++){
            is_prm[i * j] = 0;
        }
    }
}

void solve(){
    for (int i = 1; i < N; i++) dp[i] = (1ll * cnt[i]) * (1ll * i);
    // cout << prm[0] << "\n";

    for (int i = N - 1; i >= 1; i--){
        for (int j = 0; (j < prm_cnt && i * prm[j] < N); j++){
            k = i * prm[j];
            nmaxx = dp[k] + (1ll * i) * (1ll * (cnt[i] - cnt[k]));
            dp[i] = max(dp[i], nmaxx);
        }
        // if (i == 1) cout << dp[i] << "\n";
    }
    cout << dp[1] << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    // cin >> T;
    T = 1;

    while (T--){
        findPrime();
        read();
        solve();
    }
}