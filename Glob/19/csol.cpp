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
    vt<int> a(n);
    for0(i, n) cin >> a[i];   
    bool flag = false;
    forlr(i, 1, n - 1, 1){
        if (a[i] >= 2){
            flag = true;
            break;
        }
    }

    if (flag == false){
        cout << -1 << "\n";
        return;
    }

    if (n == 3){
        if (a[1] % 2 == 1){
            cout << -1 << "\n";
            return;
        }
    }

    ll tot = 0;
    forlr(i, 1, n - 1, 1){
        if (a[i] % 2 == 1) tot += 1ll * ((a[i] + 1) / 2);
        else tot += 1ll * (a[i] / 2);
    }

    cout << tot << "\n";
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