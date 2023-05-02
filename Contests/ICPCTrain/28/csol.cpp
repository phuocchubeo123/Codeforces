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

    vt<int> tot(27, 0), curr(27, 0), ans(27);
    int sign = 1;
    for0(i, n){
        int c = i;
        for0(j, 27){
            curr[j] = c % k;
            c /= k;
        }
        reverse(curr.begin(), curr.end());
        // for0(j, 27){
        //     cout << curr[j] << " ";
        // }
        // cout << "\n";
        // cout.flush();

        for0(j, 27) ans[j] = (tot[j] + sign * curr[j] + k) % k;
        int qr = 0;
        for0(j, 27){
            qr *= k;
            qr += ans[j];
        }

        cout << qr << "\n";
        cout.flush();

        int r;
        cin >> r;
        if (r == 1) return;
        
        sign = sign * (-1);
        for0(j, 27) tot[j] = (ans[j] - tot[j] + k) % k;
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