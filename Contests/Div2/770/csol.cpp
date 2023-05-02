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

    if (k == 1){
        cout << "YES\n";
        for1(i, n){
            cout << i << "\n";
        }
        return;
    }

    if (n % 2 == 1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for0(i, n / 2){
        for1(j, 2 * k){
            int num = 2 * i * k + j;
            if (num % 2 == 1) cout << num << " ";
        }
        cout << "\n";
        for1(j, 2 * k){
            int num = 2 * i * k + j;
            if (num % 2 == 0) cout << num << " ";
        }
        cout << "\n";
    }
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