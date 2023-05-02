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

int tt = 0;
void solve(){
    tt++;
    string n;
    cin >> n;
    int tot = 0;
    for (char c: n){
        tot += (c - '0');
        // cout << c << " ";
        // cout << (c - '0') << "\n";
    }

    int res = tot % 9;
    int ans;
    if (res == 0) ans = 0;
    else ans = 9 - res;

    int brk = -1;
    for0(i, n.size()){
        if ((n[i] - '0') > ans){
            // cout << i << " " << n[i] << "\n";
            brk = i;
            break;
        }
    }

    cout << "Case #" << tt << ": ";
    if (brk == -1){
        cout << n << ans << "\n";
    }
    else{
        if (ans == 0) brk = 1;
        for0(i, brk) cout << n[i];
        cout << ans;
        forlr(i, brk, n.size(), 1) cout << n[i];
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