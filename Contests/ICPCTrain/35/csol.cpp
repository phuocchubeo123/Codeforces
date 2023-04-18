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
    int x, y, n;
    cin >> x >> y >> n;
    int s = x+y;
    int ans;
    if (n % s == 0) ans = n / s * x;
    else{
        int buy = n / s;
        int left = n - buy * s;
        // cout << left << "\n";
        ans = buy * x + min(x, left);
    }
    cout << ans * 3 << "\n";
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