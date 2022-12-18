#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4, LOG = 20;
int T, l, r, cnt[N][LOG];

void read(){
    cin >> l >> r;
}

void preCal(){
    for (int j = 0; j < LOG; j++) cnt[0][j] = 0;

    for (int i = 1; i < N; i++){
        for (int j = 0; j < LOG; j++){
            if ((i >> j) & 1 == 1) cnt[i][j] = cnt[i - 1][j] + 1;
            else cnt[i][j] = cnt[i - 1][j];
        }
    }

    // for (int i = 1; i < 10; i++) cout << cnt[i][0] << " ";
    // cout << "\n";
}

void solve(){
    int ans = 0;
    for (int j = 0; j < LOG; j++) ans = max(ans, cnt[r][j] - cnt[l - 1][j]);
    cout << r - l + 1 - ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    // T = 1;
    preCal();

    while (T--){
        read();
        solve();
    }
}