#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 250 + 4;
int T;

void prepare(){

}

int n, c[2 * N][2 * N];

void read(){
    cin >> n;
    for1(i, 2 * n) for1(j, 2 * n) cin >> c[i][j];
}

void solve(){
    int ans = 1e9 + 4;
    ans = min(ans, c[1][n + 1]);
    ans = min(ans, c[1][2 * n]);
    ans = min(ans, c[n][n + 1]);
    ans = min(ans, c[n][2 * n]);
    ans = min(ans, c[n + 1][1]);
    ans = min(ans, c[n + 1][n]);
    ans = min(ans, c[2 * n][1]);
    ans = min(ans, c[2 * n][n]);
    ll tot = 1ll * ans;
    forlr(i, n + 1, 2 * n + 1, 1) forlr(j, n + 1, 2 * n + 1, 1) tot += 1ll * c[i][j];
    cout << tot << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}