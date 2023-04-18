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

void prepare(){

}

void solve(){
    int n, k;
    cin >> n >> k;
    vt<int> a(n);
    for0(i, n) cin >> a[i];
    vt<int> b;
    for0(i, n - 1) b.pb(a[i] - a[i + 1]);
    sort(b.begin(), b.end());
    int ans = a[n - 1] - a[0];
    for0(i, k - 1) ans += b[i];

    cout << ans;
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