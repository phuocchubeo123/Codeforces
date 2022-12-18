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
    int n, k;
    cin >> n >> k;
    if (k == n - 1){
        if (n == 4){
            cout << -1 << "\n";
            return;
        }
        
        forlr(i, 2, n / 2 - 1, 1){
            cout << i << " " << n - i - 1 << "\n";
        }

        cout << 0 << " " << n / 2 << "\n";
        cout << 1 << " " << n / 2 - 1 << "\n";
        cout << n - 2 << " " << n - 1 << "\n";
        return;
    }

    for0(i, n / 2){
        if (i != 0 && i != k && n - i - 1 != k){
            cout << i << " " << n - i - 1 << "\n";
        }
    }

    cout << 0 << " " << n - k - 1 << "\n";
    if (k != 0){
        cout << k << " " << n - 1 << "\n";
    }
    // cout << "\n";
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