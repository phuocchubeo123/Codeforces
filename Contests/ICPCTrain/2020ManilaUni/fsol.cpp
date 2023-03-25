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
    n++;
    vt<pair<int, pair<int, int>>> bd;
    int y, m, d;
    string s;
    for0(i, n){
        cin >> s;
        y = (s[0] - '0'); m = 0; d = 0;
        if (s.length() == 10){
            for1(j, 3){
                y = y * 10;
                y = y + (s[j] - '0');
            }
            m = (s[5] - '0') * 10 + s[6] - '0';
            d = (s[8] - '0') * 10 + s[9] - '0';
        }

        else{
            for1(j, 4){
                y = y * 10;
                y = y + (s[j] - '0');
            }
            m = (s[6] - '0') * 10 + s[7] - '0';
            d = (s[9] - '0') * 10 + s[10] - '0';
        }
        bd.pb({y, {m, d}});
    }

    sort(bd.begin(), bd.end());
    vt<pair<int, pair<int, int>>> ans;
    for0(i, n-1){
        auto curr = bd[i];
        auto next = bd[i+1];
        if (curr.first == next.first) continue;
        forlr(j, curr.first+1, next.first, 1) ans.pb({j, {2, 27}});
        if (next.second.first > 2){
            ans.pb({next.first, {2, 27}});
        }
    }

    cout << ans.size() << "\n";
    for (auto date: ans){
        y = date.first;
        m = date.second.first;
        d = date.second.second;
        cout << y << "-";
        if (m < 10) cout << "0";
        cout << m << "-";
        if (d < 10) cout << "0";
        cout << d << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}