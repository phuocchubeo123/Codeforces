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
    int x = 1;
    while (2 * x < n) x *= 2;
    for1(i, x - 1) cout << i << " ";
    cout << 0 << " ";
    forlr(i, x, n, 1) cout << i << " ";
    cout << "\n";
    return;
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