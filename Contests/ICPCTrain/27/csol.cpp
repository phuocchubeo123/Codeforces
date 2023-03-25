#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 1e3 + 4;
int T;

void prepare(){

}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> srtd, nsrtd;
    for0(i, m){
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) srtd.pb({l, r});
        else nsrtd.pb({l, r});
    }

    vt<bool> sted(N);

    for (auto p: srtd){
        forlr(i, p.first, p.second, 1) sted[i] = 1;
    }

    // for1(i, n) cout << sted[i] << " ";
    // cout << "\n";

    vt<int> ans(N);
    for1(i, n) ans[i] = 0;
    int num = 2000;
    for1(i, n){
        if (sted[i] == 1){
            num++;
            ans[i + 1] = num;
        }
    }

    // for1(i, n) cout << ans[i] << " ";
    // cout << "\n";

    num = 1999;
    for1(i, n){
        if (ans[i] == 0){
            num--;
            ans[i] = num;
        }
    }

    for (auto p: nsrtd){
        bool flag = false;
        forlr(i, p.first, p.second, 1){
            if (ans[i] > ans[i + 1]) flag = true;
        }

        if (flag) continue;
        else{
            cout << "NO";
            return;
        }
    }

    cout << "YES\n";
    for1(i, n) cout << ans[i] << " ";
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