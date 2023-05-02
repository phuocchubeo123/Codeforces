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
    string s;
    cin >> s;
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    if (k == 0){
        cout << 1 << "\n";
        return;
    }

    if (s == rev_s) cout << 1 << "\n";
    else cout << 2 << "\n";
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