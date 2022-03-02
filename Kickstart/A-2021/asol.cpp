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

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s.pb('a');
    reverse(s.begin(), s.end());
    int good = 0;
    for1(i, n / 2){
        if (s[i] != s[n - i + 1]){
            // cout << i << " ";
            good++;
        }
    }
    // cout << "\n";
    // cout << good << "\n";
    cout << "Case #" << tcase << ": " << abs(good - k) << "\n";
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