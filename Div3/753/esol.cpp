#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, m;
string s;
int l, r, u, d;
int nl, nr, nu, nd;
int x, y;

int main(){
    cin >> t;
    for (int tt=0;tt<t;tt++){
        x = 0; y = 0; l = 0; r = 0; u = 0; d = 0;
        cin >> n >> m;
        cin >> s;

        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'L') x--;
            if (s[i] == 'R') x++;
            if (s[i] == 'U') y++;
            if (s[i] == 'D') y--;

            nl = min(l, x);
            nr = max(r, x);
            nu = max(u, y);
            nd = min(d, y);

            if ((nr - nl + 1 > m) || (nu - nd + 1 > n)) break;

            l = nl; r = nr; u = nu; d = nd;
        }
        // cout << l << " " << r << " " << u << " " << d << " ";
        cout << 1 + u << " " << m - r;
        cout << "\n";
    }
}