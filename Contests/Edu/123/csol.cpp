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
    int n, x;
    cin >> n >> x;
    vt<int> a(n + 1, 0);
    for1(i, n) cin >> a[i];
    // return;

    vt<ll> cumu(n + 1);
    ll tot = 0;
    for1(i, n){
        tot += 1ll * a[i];
        cumu[i] = tot;
    }

    vt<ll> best(n + 1, -100000 * 5000 - 4);
    best[0] = 0;
    for1(i, n){
        for1(j, n){
            if (j + i - 1 > n) continue;
            best[i] = max(best[i], cumu[j + i - 1] - cumu[j - 1]);
        }
    }

    for0(i, n + 1){
        ll ans = -100000 * 5000 - 4;
        for0(j, n + 1){
            ans = max(ans, best[j] + x * min(j, i));
        }
        cout << ans << " ";
    }
    cout << "\n";
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