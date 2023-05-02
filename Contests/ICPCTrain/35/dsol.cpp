#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;
vt<int> ans(N);

void prepare(){
    ans[1] = 1;
    ans[2] = 2;
    forlr(i, 3, N, 1){
        ans[i] = (ans[i-1] + ans[i-2] + 1) % 1000000007;
    }
}

void solve(){
    int n; cin >> n;
    cout << ans[n] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        solve();
    }
}