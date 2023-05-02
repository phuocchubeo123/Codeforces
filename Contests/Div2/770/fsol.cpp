#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 3e5 + 4;
int T, F[N];

void prepare(){
    
}

int cnt;

void changeCnt(int old_d, int new_d){
    if (new_d != 0 && old_d == 0) cnt++;
    if (new_d == 0 && old_d != 0) cnt--;
}

void solve(){
    int n, q, MOD;
    cin >> n >> q >> MOD;
    F[1] = 1;
    F[2] = 1;
    forlr(i, 3, N, 1) F[i] = (F[i - 1] + F[i - 2]) % MOD;

    vt<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1);
    for1(i, n) cin >> a[i];
    for1(i, n) cin >> b[i];
    for1(i, n) c[i] = (b[i] % MOD - a[i] % MOD + MOD) % MOD;
    forlr(i, 3, n + 1, 1) d[i] = (c[i - 2] + c[i - 1] - c[i] + MOD) % MOD;
    d[1] = c[1];
    d[2] = c[2];
    for1(i, n) cout << d[i] << " ";
    cout << "\n";

    cnt = 0;
    for1(i, n) if (d[i] != 0) cnt++;
    cout << cnt << "\n";

    char cc;
    int l, r, sign, new_d, old_d;
    while (q--){
        cin >> cc >> l >> r;
        if (cc == 'A') sign = -1;
        else sign = 1;

        if (l <= 1 && 1 <= r) {
            old_d = d[1];
            new_d = (d[1] + sign * F[2 - l] + MOD) % MOD;
            changeCnt(old_d, new_d);
            d[1] = new_d;
        }
            
        if (l <= 2 && 2 <= r){
            old_d = d[2];
            new_d = (d[2] + sign * F[3 - l] + MOD) % MOD;
            changeCnt(old_d, new_d);
            d[2] = new_d;
        }

        if (l - 2 >= 1){
            old_d = d[l];
            new_d = (d[l] - sign * F[1] + MOD) % MOD;
            changeCnt(old_d, new_d);
            d[l] = new_d;
        }

        if (l - 1 >= 1 && l + 1 <= n){
            old_d = d[l + 1];
            new_d = (d[l + 1] + sign * ((F[2] - F[1] + MOD) % MOD) + MOD) % MOD;
            changeCnt(old_d, new_d);
            d[l + 1] = new_d;
        }
        if (r + 1 <= n && r + 1 >= max(3, l + 1)){
            old_d = d[r + 1];
            new_d = (d[r + 1] + (F[r - l] + F[r - l + 1]) % MOD) % MOD;
            changeCnt(old_d, new_d);
            d[r + 1] = new_d;
        }

        if (r + 2 <= n){
            old_d = d[r + 2];
            new_d = (d[r + 2] + F[l - r + 1]) % MOD;
            changeCnt(old_d, new_d);
            d[r + 2] = new_d;
        }

        for1(i, n) cout << d[i] << " ";
        cout << "\n";
        cout << cnt << "\n";

        if (cnt == 0) cout << "YES\n";
        else cout << "NO\n";
    }
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