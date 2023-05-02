#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e5 + 4;
int T;

void prepare(){

}

ll sumDist(vt<int> v){
    int sz = v.size();
    if (sz <= 1) return 0;
    ll tot = v[0];
    ll anss = 0;
    for1(l, sz - 1){
        // cout << v[l] << " " << tot << " " << l * v[l] - tot << "\n";
        anss += (1ll * l * v[l] - tot);
        tot += 1ll * v[l];
    }
    return anss;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vt<vt<int>> x(N), y(N);
    for0(i, n){
        for0(j, m){
            int c;
            cin >> c;
            x[c].pb(i);
            y[c].pb(j);
        }
    }

    ll ans = 0;
    for0(k, N){
        sort(x[k].begin(), x[k].end());
        sort(y[k].begin(), y[k].end());
        ans += sumDist(x[k]);
        ans += sumDist(y[k]);
    }

    cout << ans << "\n";
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