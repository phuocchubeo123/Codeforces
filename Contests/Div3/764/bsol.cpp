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
    int a, b, c;
    cin >> a >> b >> c;
    if ((2 * b - a) % c == 0 && (2 * b - a) > 0) cout << "YES\n";
    else if ((2 * b - c) % a == 0 && (2 * b - c) > 0) cout << "YES\n";
    else if ((a + c) % 2 == 0 && ((a + c) / 2) % b == 0 && ((a + c) / 2) > 0) cout << "YES\n";
    else cout << "NO\n";
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