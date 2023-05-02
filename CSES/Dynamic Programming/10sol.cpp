#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e6 + 4, MOD = 1e9 + 7;
int T;

void prepare(){
}

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    a[0] = 1; b[0] = 1;
    int tot_a = 1, tot_b = 1;
    for1(i, n){
        a[i] = (tot_a + tot_b) % MOD;
        (tot_a += a[i]) %= MOD;
        b[i] = (a[i] + tot_b) % MOD; 
        (tot_b *= 2) %= MOD;
        (tot_b += b[i]) %= MOD;
    }
    cout << a[n] << "\n";
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