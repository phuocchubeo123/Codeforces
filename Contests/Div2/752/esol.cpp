#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 9, mod = 998244353;
int T;
int a[N];
int last, k, q;
vector<int> v[2];
int dp[2][N];
ll ans;

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        ans = 0; v[0].clear(); v[1].clear();
        int n; cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        for (int i = n; i > 0; i--){
            k = i & 1; q = k ^ 1;
            k = i & 1; v[k].clear();
            last = a[i]; v[k].push_back(last);
            dp[k][last] = 1;

            for (int x: v[q]){
                int split = (a[i] + x - 1) / x;
                int nx = a[i] / split;

                if (nx != last){
                    dp[k][nx] = 0;
                    last = nx;
                    v[k].push_back(last);
                }

                dp[k][nx] += dp[q][x];
                // cout << "split " << split << "\n";
                // cout << "dp " << dp[q][nx] << "\n";
                ans += 1LL * (split - 1) * dp[q][x] * i;
                ans %= mod;

                // cout << x << " " << nx << "\n";
                // cout << "ans: " << ans << "\n";
            }

            // cout << "All x: ";
            // for (int x: v[k]) cout << x << " ";
            // cout << "\nAll dp: ";
            // for (int x: v[k]) cout << dp[k][x] << " ";
            // cout << "\n";
        }
        cout << ans << "\n";
    }
}