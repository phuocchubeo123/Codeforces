#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T, tcase = 0;

void prepare(){

}

int gr[1000][1000], l[1000][1000], r[1000][1000], u[1000][1000], d[1000][1000];

int findAns(int x, int y){
    ll ans2 = 0;
    if (x <= 1 || y <= 1) return 0;
    return 1ll * min(x - 1, y / 2 - 1) + 1ll * min(y - 1, x / 2 - 1);
}

void solve(){
    int ro, co;
    cin >> ro >> co;
    for0(i, ro){
        for0(j, co){
            cin >> gr[i][j];
        }
    }

    for0(i, ro){
        if (gr[i][0] == 0) l[i][0] = 0;
        else l[i][0] = 1;

        for1(j, co - 1){
            if (gr[i][j] == 0){
                l[i][j] = 0;
                continue;
            }
            l[i][j] = l[i][j - 1] + 1;
        }
    }

    for0(i, ro){
        if (gr[i][co - 1] == 0) r[i][co - 1] = 0;
        else r[i][co - 1] = 1;

        for (int j = co - 2; j >= 0; j--){
            if (gr[i][j] == 0){
                r[i][j] = 0;
                continue;
            }
            r[i][j] = r[i][j + 1] + 1;
        }
    }

    for0(j, co){
        if (gr[0][j] == 0) u[0][j] = 0;
        else u[0][j] = 1;

        for1(i, ro - 1){
            if (gr[i][j] == 0){
                u[i][j] = 0;
                continue;
            }
            u[i][j] = u[i - 1][j] + 1;
        }
    }

    for0(j, co){
        if (gr[ro - 1][j] == 0) d[ro - 1][j] = 0;
        else d[ro - 1][j] = 1;

        for (int i = ro - 2; i >= 0; i--){
            if (gr[i][j] == 0){
                d[i][j] = 0;
                continue;
            }
            d[i][j] = d[i + 1][j] + 1;
        }
    }

    // for0(i, ro){
    //     for0(j, co) cout << d[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    ll ans = 0;
    for0(i, ro){
        for0(j, co){
            ll ans1 = 0;
            ans1 += 1ll * findAns(l[i][j], u[i][j]);
            ans1 += 1ll * findAns(l[i][j], d[i][j]);
            ans1 += 1ll * findAns(r[i][j], u[i][j]);
            ans1 += 1ll * findAns(r[i][j], d[i][j]);
            // cout << ans1 << " ";
            ans += ans1;
        }
        // cout << "\n";
    }

    cout << "Case #" << tcase << ": " << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        tcase++;
        solve();
    }
}