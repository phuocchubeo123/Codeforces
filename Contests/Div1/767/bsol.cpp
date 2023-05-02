#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T; void prepare(){

}

vt<int> exst(27 * 27 * 27);

int decode(string s){
    if (s.size() == 2) return ((s[0] - 'a') + 1) * 27 * 27 + ((s[1] - 'a') + 1) * 27;
    if (s.size() == 3) return ((s[0] - 'a') + 1) * 27 * 27 + ((s[1] - 'a') + 1) * 27 + ((s[2] - 'a') + 1);
    return 0;
}

void solve(){
    int n; cin >> n;
    vt<string> s(n);
    for0(i, n) cin >> s[i];

    for0(i, n){
        string tmp = s[i];
        reverse(tmp.begin(), tmp.end()); 
        if (tmp == s[i]){
            // cout << 1 << " " << s[i] << " ";
            cout << "YES\n";
            return;
        }
    }

    fill(exst.begin(), exst.end(), 0);
    for0(i, n){
        if (exst[decode(s[i])] == 1){
            // cout << 2 << " " << s[i] << " ";
            cout << "YES\n";
            return;
        }
        string tmp = s[i];
        reverse(tmp.begin(), tmp.end());
        exst[decode(tmp)] = 1;
    }

    fill(exst.begin(), exst.end(), 0);
    for0(i, n){
        if (s[i].size() == 2){
            if (exst[decode(s[i])] == 1){
                // cout << 3 << " " << s[i] << " ";
                cout << "YES\n";
                return;
            }
        }

        else{
            string tmp;
            for0(j, 2) tmp.pb(s[i][j]);
            reverse(tmp.begin(), tmp.end());
            exst[decode(tmp)] = 1;
        }
    }

    fill(exst.begin(), exst.end(), 0);
    for0(i, n){
        if (s[i].size() == 2){
            string tmp = s[i];
            reverse(tmp.begin(), tmp.end());
            exst[decode(tmp)] = 1;
        }

        else{
            string tmp;
            for1(j, 2) tmp.pb(s[i][j]);
            if (exst[decode(tmp)] == 1){
                // cout << 4 << " " << s[i] << " ";
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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