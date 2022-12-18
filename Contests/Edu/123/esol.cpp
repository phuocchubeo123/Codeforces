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
    string s;
    cin >> s;
    if (s[0] == 'R'){
        string s2;
        for (char c: s){
            if (c == 'D') s2.pb('R');
            if (c == 'R') s2.pb('D');
        }
        s = s2;
    }


    int ro = 1, co = 1;
    for (char c: s){
        // cout << c << " ";
        if (c == 'D') ro++;
        if (c == 'R') co++;
        // cout << ro << " " << co << "\n";
    }
    // cout << "\n";
    
    // cout << ro << " " << co << "\n";
    // return;

    int h = n - ro, w = n - co;

    ll ans = 1ll * h * (co - 1);
    int r2 = 1;
    int i = 0;
    while (i <= s.size() - 1 && s[i] == 'D'){
        r2++;
        i++;
    }

    ans = ans + 1ll * w * (ro - r2);
    ans = ans + 1ll * s.size() + 1;
    // cout << ans << "\n";
    int rr = 0;
    for (char c: s) if (c == 'R') rr = 1;
    // cout << rr << "\n";
    if (rr == 1){
        ans = ans + 1ll * (w + 1) * (h + 1) - 1;
        cout << ans << "\n";
    }
    else cout << n << "\n";
    // cout << "\n";
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