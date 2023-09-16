// I_Love_LPL
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5 + 5;
long long mod = 1e9 + 7;
const int lim = 2e5;
const int lg = 19;
const int base = 311;
const long double eps = 1e-6;
ll n, m, k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("tests.inp", "r")){
        freopen("tests.inp", "r", stdin);
        freopen("tests.out", "w", stdout);
    }
    cin >> n >> m >> k;
    if (m >= k) return cout << "No", 0;
    if (m == 0){
        if (n > 26) cout << "No";
        else {
            cout << "Yes" << endl;
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= k; j++){
                    cout << char('a' + i - 1);
                }
                cout << endl;
            }
        }
        return 0;
    } else {
        ll cnt = 0;
        cout << "Yes" << endl;
        ll chg = k - m;
        chg = chg & 1;
        for (int x = 1; x <= k; x++){
            ll rem = k - x + 1;
            char c1 = char('a' + 1 - 1);
            char c2 = char('a' + 2 - 1);
            if (rem <= m) cout << "z";
            else if ((x + chg) & 1) cout << c1;
            else cout << c2;
        }
        cnt++;
        cout << endl;
        
        for (int x = 1; x <= k; x++){
            ll rem = k - x + 1;
            char c1 = char('a' + 1 - 1);
            char c2 = char('a' + 3 - 1);
            if (rem <= m) cout << "z";
            else if ((x + chg) & 1) cout << c1;
            else cout << c2;
        }
        cnt++;
        cout << endl;
        for (int i = 1; i <= 25; i++){
            for (int j = i + 1; j <= 25; j++){
                if (cnt >= n) break;
                if (i == 1 && j <= 3) continue;        
                for (int x = 1; x <= k; x++){
                    ll rem = k - x + 1;
                    char c1 = char('a' + i - 1);
                    char c2 = char('a' + j - 1);
                    if ((x + chg) & 1) cout << c1;
                    else cout << c2;
                }
                cnt++;
                cout << endl;
            }
        }
    }
}
/*
Ans:
 
Out:
*/