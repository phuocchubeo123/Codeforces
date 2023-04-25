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
    string s;
    cin >> s;

    int r = 0, g = 0, b = 0;
    for (char c: s){
        if (c == 'r') r = 1;
        if (c == 'g') g = 1;
        if (c == 'b') b = 1;
        if (c == 'R'){
            if (r == 1) continue;
            cout << "NO\n";
            return;
        }
        if (c == 'G'){
            if (g == 1) continue;
            cout << "NO\n";
            return;
        }
        if (c == 'B'){
            if (b == 1) continue;
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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