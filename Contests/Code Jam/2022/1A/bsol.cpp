#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
const int X = 1e9;
int T;

void prepare(){

}

void solve(){
    int n;
    cin >> n;
    if (n < 10){
        vt<ll> a(n), b(n);
        for0(i, n){
            a[i] = i + 1;
            cout << a[i] << " ";
            cout.flush();
        }
        cout << "\n";
        cout.flush();
        for0(i, n) cin >> b[i];
        
        vt<ll> c(n * 2);
        for0(i, n){
            c[i] = a[i];
            c[i + n] = b[i];
        }

        // for0(i, 2 * n) cout << c[i] << " ";
        // cout << "\n";
        // cout.flush();
        
        ll ss = 0;
        for0(i, 2 * n) ss += c[i];
        // cout << ss << "\n";
        // cout.flush();

        for0(i, (1 << 2 * n)){
            // cout << i << "\n";
            // cout.flush();
            vt<ll> ans;
            for0(j, 2 * n){
                if ((i >> j) & 1) ans.pb(c[j]);
            }

            ll tot = 0;
            for (ll x: ans) tot += x;
            // cout << i << " " << tot << "\n";
            cout.flush();
            if (tot == ss / 2){
                for (ll x: ans){
                    cout << x << " ";
                }
                cout << "\n";
                cout.flush();
                return;
            }
        }
        return;
    }

    vt<ll> a(n), b(n + 70);
    for0(i, 30) a[i] = (1 << i);
    ll ss = 0;
    forlr(i, 30, 100, 1){
        a[i] = 2 * a[29] + 3 * i;
        b[i + 100 - 31] = a[i];
    }

    // int cnt = 0;
    // vt<ll> lmao;
    // while (cnt < 100){
    //     ll x = rand() % X;
    //     bool flag = false;
    //     for0(j, n){
    //         if (x == a[j]){
    //             flag = true;
    //             break;
    //         }
    //     }

    //     for (int y: lmao){
    //         if (x == y){
    //             flag = true;
    //             break;
    //         }
    //     }

    //     if (flag) continue;
    //     else{
    //         lmao.pb(x);
    //         cnt++;
    //     }
    // }
    // for (int x: lmao) cout << x << " ";

    // return;

    // return;

    for0(i, n) ss += a[i];
    for0(i, n){
        cout << a[i] << " ";
    }
    cout << "\n";
    cout.flush();

    for0(i, n){
        cin >> b[i];
        ss += b[i];
    }

    // cout << b[99] << "\n";
    // cout.flush();
    // return;
    // for0(i, n + 69) cout << b[i] << " ";
    // cout << "\n";


    ss = ss / 2;
    // cout << ss << "\n";
    ll tot = 0;
    vt<ll> ans;

    for0(i, n + 69){
        if (tot + b[i] < ss){
            tot += b[i];
            ans.pb(b[i]);
            // cout << ans[i] << " " << b[i] << "\n";
        }

        else if (tot + b[i] == ss){
            tot += b[i];
            // cout << tot << "\n";
            ans.pb(b[i]);
            break;
        }

        else{
            // cout << "\n";
            ll remain = ss - tot;
            // cout << i << " " << b[i] << "\n";
            // for (int x: ans) cout << x << " ";
            // cout << "\n";
            for0(j, 31){
                if ((remain >> j) & 1){
                    // cout << a[j] << "\n";
                    ans.pb(a[j]);
                }
            }
            // cout << tot << " " << remain << "\n";
            break;
        }
    }

    ll tot2 = 0;
    for (ll x: ans){
        tot2 += x;
        cout << x << " ";
    }
    // cout << 5;
    // cout << "\n" << tot2 << "\n";
    cout << "\n";
    cout.flush();
    return;
}

void testFlush(){
    int n;
    cin >> n;
    cout << 5 << "\n";
    cout.flush();
    int x;
    cin >> x;
    cout << x + 5 << "\n";
    cout.flush();
}

void createRand(){
    int n;
    cin >> n;
    vt<ll> x(n);
    for0(i, n) cin >> x[i];
    cout << x[99] << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;

    // for0(i, 5) createRand();
    // T = 1;

    while (T--){
        solve();
        // testFlush();
        // createRand();
    }
}