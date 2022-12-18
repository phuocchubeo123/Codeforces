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
    int n; cin >> n;
    vt<vt<int>> gr(n, vt<int> (n));
    for0(i, n) for0(j, n) cin >> gr[i][j];

    int ans = 0;
    forlr(i, 1, n, 4){
        int x = 0, y = i;
        while (x < n && y < n){
            // cout << x << y << "\n";
            ans = ans ^ gr[x][y];
            x += 2;
            y += 2;
        }
    }

forlr(j, 3, n, 4){
        int x = j, y = 0;
        while (x < n && y < n){
            // cout << x << y << "\n";
            ans = ans ^ gr[x][y];
            x += 2;
            y += 2;
        }
    }

    for0(i, n){
        reverse(gr[i].begin(), gr[i].end());
    }

    forlr(i, 1, n, 4){
        int x = 0, y = i;
        while (x < n && y < n){
            // cout << x << y << "\n";
            ans = ans ^ gr[x][y];
            x += 2;
            y += 2;
        }
    }

    forlr(j, 3, n, 4){
        int x = j, y = 0;
        while (x < n && y < n){
            // cout << x << y << "\n";
            ans = ans ^ gr[x][y];
            x += 2;
            y += 2;
        }
    }

    cout << ans << "\n";
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