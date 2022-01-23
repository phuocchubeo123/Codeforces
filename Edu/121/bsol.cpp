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
    string s; cin >> s;
    s.push_back('0');
    int sz = s.size();
    int brk = -1;
    for0(i, sz - 1) if (s[i] - '0' + s[i + 1] - '0' >= 10) brk = i;

    if (brk == -1){
        cout << char('0' + (s[0] - '0') + (s[1] - '0'));
        forlr(i, 2, sz - 1, 1) cout << s[i];
    }

    else{
        for0(i, sz - 1){
            if (i == brk){
                cout << 1;
                cout << char('0' + (s[i] - '0') + (s[i + 1] - '0' - 10));
                i++;
            }

            else cout << s[i];
        }
    }
    cout << "\n";
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