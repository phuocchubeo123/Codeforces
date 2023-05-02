#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, p[N];
bool dp[N][2][2];

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
}

void solve(){
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                dp[i][j][k] = 0;
            }
        }
    }

    for (int j = 0; j < 2; j++){
        for (int k = 0; k < 2; k++){
            dp[1][j][k] = 1;
        }
    }

    for (int i = 2; i <= n; i++){
        if (p[i] > p[i - 1]){
            dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]);
        }


    }
}

int main(){
    cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}