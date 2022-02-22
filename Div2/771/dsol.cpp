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
    int n, m;
    cin >> n >> m;
    vt<vt<int>> a(n, vt<int> (m, 0));
    for0(i, n){
        for0(j, m){
            cin >> a[i][j];
        }
    }

    vt<vt<int>> a2 = a;

    vt<vt<int>> f(n, vt<int> (m));
    for0(i, n - 1){
        for0(j, m - 1){
            int c = a[i][j];
            if (a[i + 1][j] == c && a[i][j + 1] == c && a[i + 1][j + 1] == c) f[i][j] = 1;
            else f[i][j] = 0;
        }
    }

    stack<pair<int, int>> s;
    for0(i, n - 1) for0(j, m - 1) if (f[i][j] == 1) s.push({i, j});

    vt<tuple<int, int, int>> ans;
    while (!s.empty()){
        pair<int, int> p = s.top(); s.pop();
        int i = p.first, j = p.second;
        int c = 0;
        for0(x, 2) for0(y, 2) if (a[i + x][j + y] != 0) c = a[i + x][j + y];
        ans.pb({i, j, c});
        for0(k, 2) for0(l, 2) a[i + k][j + l] = 0;

        forlr(k, -1, 2, 1){
            forlr(l, -1, 2, 1){
                if (i + k < 0 || i + k >= n - 1) continue;
                if (j + l < 0 || j + l >= m - 1) continue;
                
                set<int> se;
                for0(x, 2) for0(y, 2) if (a[i + k + x][j + l + y] != 0) se.insert(a[i + k + x][j + l + y]);
                if (se.size() >= 2) continue;
                if (f[i + k][j + l] == 1) continue;
                f[i + k][j + l] = 1;
                s.push({i + k, j + l});
            }
        }
    }
    // cout << "\n";

    reverse(ans.begin(), ans.end());
    vt<tuple<int, int, int>> anss;
    vt<vt<int>> b(n, vt<int> (m, 0));
    for (auto tp: ans){
        int i = get<0>(tp), j = get<1>(tp), c = get<2>(tp);
        if (c == 0) continue;
        anss.pb({i + 1, j + 1, c});
        b[i][j] = c;
        b[i + 1][j] = c;
        b[i][j + 1] = c;
        b[i + 1][j + 1] = c;
    }

    // for0(i, n){
    //     for0(j, m) cout << b[i][j] << " ";
    //     cout << "\n";
    // }

    for0(i, n){
        for0(j, m){
            if (b[i][j] != a2[i][j]){
                cout << -1;
                return;
            }
        } 
    }

    cout << anss.size() << "\n";
    for (auto x: anss){
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
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