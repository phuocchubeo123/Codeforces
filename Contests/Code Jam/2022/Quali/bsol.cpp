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

int minv(vector<int> v){
    int mn = 1e9 + 4;
    for (int x: v) mn = min(x, mn);
    return mn;
}

int tt = 0;

void solve(){
    tt++;
    cout << "Case #" << tt << ": ";
    vt<vt<int>> c(4, vt<int> (3));
    for0(i, 3){
        for0(j, 4) cin >> c[j][i];
    }

    // for0(i, 4) cout << minv(c[i]) << " ";
    // cout << "\n";

    int tot = 0;
    vt<int> ans;
    for0(i, 4){
        ans.pb(minv(c[i]));
        tot += minv(c[i]);
    }

    if (tot >= 1000000){
        int tot2 = 0;
        for0(i, 4){
            cout << min(ans[i], 1000000 - tot2) << " ";
            tot2 = min(tot2 + ans[i], 1000000);
        }
        cout << "\n";
    }

    else cout << "IMPOSSIBLE\n";
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