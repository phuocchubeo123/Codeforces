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
    vt<int> a(n + 1);
    for1(i, n) cin >> a[i];
    map<int, int> cnt;
    for1(i, n) cnt[a[i]] = 0;
    for1(i, n) cnt[a[i]]++;
    for1(i, n){
        if (cnt[a[i]] % 2 == 1){
            cout << -1 << "\n";
            return;
        }
    }

    vt<pair<int, int>> ans;
    int start = 0, stop;
    vt<int> b = a;
    // for (int x: b) cout << x << " ";
    // cout << "\n";
    vt<int> c;
    vt<int> ans2;

    while (b.size() != 1){
        forlr(i, 2, b.size(), 1){
            if (b[i] == b[1]){
                stop = i;
                break;
            }
        }

        // cout << "start: " << start << " " << stop << "\n";

        forlr(j, 2, stop, 1){
            ans.pb({start + stop + j - 2, b[j]});
        }

        start = start + 2 * stop - 2;
        ans2.pb(start);
        reverse(b.begin() + 2, b.begin() + stop);
        c.clear();
        c.pb(0);
        forlr(i, 2, stop, 1){
            c.pb(b[i]);
        }
        forlr(i, stop + 1, b.size(), 1) c.pb(b[i]);

        // cout << "c: ";
        // for (int x: c) cout << x << " ";
        // cout << "\n";
        b.clear();
        for0(i, c.size()) b.pb(c[i]);
        // break;
    }

    cout << ans.size() << "\n";
    for (auto x: ans){
        cout << x.first << " " << x.second << "\n";
    }

    cout << ans2.size() << " ";
    cout << ans2[0] << " ";
    for0(i, ans2.size() - 1) cout << ans2[i + 1] - ans2[i] << " ";
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