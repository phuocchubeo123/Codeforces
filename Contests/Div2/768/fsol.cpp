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

int gcd(int x, int y){
    if (x > y) return gcd(y, x);
    if (y % x == 0) return x;
    return gcd(x, y % x);
}

void solve(){
    int n, m; 
    cin >> n >> m;
    vt<int> a(n), b(m);
    for0(i, n) cin >> a[i];
    for0(i, m) cin >> b[i];
    
    int g = b[0];
    for0(i, m) g = gcd(g, b[i]);

    vt<bool> prty(g);
    for0(i, n) if (a[i] < 0) prty[i % g] = prty[i % g] ^ 1;

    for0(i, n) if (a[i] < 0) a[i] = -a[i];
    vt<int> mn(g, 1e9 + 4);
    for0(i, n) mn[i % g] = min(mn[i % g], a[i]);

    ll ans1 = 0;
    for0(i, n) ans1 += 1ll * a[i];
    ll ans2 = ans1;
    for0(i, g){
        if (prty[i]) ans1 -= 1ll * 2 * mn[i];
        else ans2 -= 1ll * 2 * mn[i];
    }

    cout << max(ans1, ans2) << "\n";
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