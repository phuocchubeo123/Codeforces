#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int x[100];
int dp[N][101];
int main() {
  int mod = 1e9+7;
  int n, target;
  cin >> n >> target;
  for (int i = 0; i < n; i++) cin >> x[i];

  for (int i = 0; i <= n; i++){
      for (int j = 0; j <= target; j++) dp[j][i] = 0;
  }

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[j][i] = dp[j][i - 1];
      if (j - x[i - 1] >= 0) {
	dp[j][i] += dp[j - x[i - 1]][i];
    dp[j][i] %= mod;
      }
    }
  }
  cout << dp[target][n] << endl;
}