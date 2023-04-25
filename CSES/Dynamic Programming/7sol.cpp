#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

void solve(){
    int n, x; 
    cin >> n >> x;
    vector<int> h(n), s(n);
    for0(i, n) cin >> h[i];
    for0(i, n) cin >> s[i];
    vector<int> books(n);
    for0(i, n) books[i] = i;
    sort(books.begin(), books.end(), [&](int x, int y){
        return h[x] < h[y];
    });
    vector<int> nh(n), ns(n);
    for0(i, n){
        nh[i] = h[books[i]];
        ns[i] = s[books[i]];
    }
    
    // for0(i, n) cout << ns[i] << " ";
    // cout << "\n";

    vector<vector<int>> dp(x + 1, vector<int> (n, 0));
    for0(i, x){
        if (i >= nh[0]) dp[i][0] = ns[0];
    }
    for0(i, x + 1){
        for0(j, n - 1){
            // cout << i << " " << j << " " << i + nh[j + 1] << "\n";
            dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);
            if (i + nh[j + 1] <= x){
                dp[i + nh[j + 1]][j + 1] = max(dp[i + nh[j + 1]][j + 1], dp[i][j] + ns[j + 1]);
                // cout << dp[j + 1][i + nh[j + 1]] << " " << dp[j][i] + ns[j + 1] << "\n";
            }
        }
    }
    // for0(i, x + 1){
    //     cout << i << ": ";
    //     for0(j, n){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[x][n - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}