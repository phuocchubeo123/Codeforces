/**
 *    author:  tourist
 *    created: 27.01.2023 18:33:08       
**/
#include <bits/stdc++.h>

using namespace std;

// #ifdef LOCAL
// #include "algo/debug.h"
// #else
// #define debug(...) 42
// #endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      --c[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> pv(n);
    function<void(int)> Dfs = [&](int v) {
      for (int u : g[v]) {
        if (u == pv[v]) {
          continue;
        }
        pv[u] = v;
        Dfs(u);
      }
    };
    pv[0] = -1;
    Dfs(0);
    int ans = n + 1;
    vector<int> best(n, n + 1);
    for (int i = 0; i < n; i++) {
      int v = c[i];
      int val = 0;
      while (v >= 0 && val < ans) {
        ans = min(ans, val + best[v]);
        best[v] = min(best[v], val);
        v = pv[v];
        val += 1;
      }
      if (i > 0) {
        cout << ans << " \n"[i == n - 1];
      }
    }
  }
  return 0;
}
