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

string solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n >= 3) return "NO\n";
    if (n == 1) return "YES\n";
    if (s == "01") return "YES\n";
    if (s == "10") return "YES\n";
    return "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        cout << solve();
    }
}