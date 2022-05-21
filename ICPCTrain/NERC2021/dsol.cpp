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
    string s, t;
    cin >> s >> t;
    int szs = s.length(), szt = t.length();
    int alp[30];
    for0(i, 30) alp[i] = 0;
    for0(i, szt){
        alp[(t[i] - 'A')]++;
    }
    
    string x;
    for (int i = szs - 1; i >= 0; i--){
        if (alp[(s[i] - 'A')] > 0){
            alp[(s[i] - 'A')]--;
            x.pb(s[i]);
        }
    }

    reverse(x.begin(), x.end());
    for0(i, szt){
        if (x[i] != t[i]){
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