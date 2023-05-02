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
    int n;
    cin >> n;
    vt<int> a(n);
    for0(i, n) cin >> a[i];

    vt<vt<int>> mex(n, vt<int> (n));
    for0(i, n){
        for0(j, n){
            if (i + j >= n) continue;
            vt<int> nsa;
            forlr(k, i, i + j + 1, 1) nsa.pb(a[k]);
            sort(nsa.begin(), nsa.end());
            int me = 0;
            for (int x: nsa){
                while (me == x) me++;
            }
            mex[i][i + j] = me + 1;
        }
    }

    vt<vt<int>> ans(n, vt<int> (n));
    for0(j, n){
        for0(i, n){
            if (i + j >= n) continue;
            int tot = mex[i][i + j];
            forlr(k, i, i + j, 1){
                tot = max(tot, ans[i][k] + ans[k + 1][i + j]);
            }
            ans[i][i + j] = tot;
        }
    }

    ll tot_ans = 0;
    for0(i, n){
        for0(j, n){
            if (i + j <= n - 1){
                // cout << i << " " << i + j << " " << ans[i][i + j] << "\n";
                tot_ans += 1ll * ans[i][i + j];
            }
        }
    }

    cout << tot_ans << "\n";
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