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

vt<vt<pair<pair<int, int>, int>>> has(10, vt<pair<pair<int, int>, int>>(10));

void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    vt<string> num(n);
    for0(i, n) cin >> num[i];
    cin >> s;

    int last = 0;
    for0(i, 10) for0(j, 10) has[i][j] = {{-1, -1}, -1};

    for0(i, n){
        for0(j, m - 1){
            // cout << num[i][j] << num[i][j + 1] << "\n";
            has[num[i][j] - '0'][num[i][j + 1] - '0'] = {{j + 1, j + 2}, i + 1};
        }
    }
    // return;

    vt<int> can;
    for0(i, m - 1){
        if (has[s[i] - '0'][s[i + 1] - '0'].second != -1){
            // cout << i << " ";
            can.pb(i);
        }
    }

    if (can.empty()){
        cout << -1 << "\n";
        return;
    }

    if (can[0] != 0){
        cout << -1 << "\n";
        return;
    }
    
    if (can[can.size() - 1] != m - 2){
        cout << -1 << "\n";
        return;
    }

    for0(i, can.size() - 1){
        if (can[i + 1] - can[i] > 2){
            cout << -1 << "\n";
            return;
        }
    }

    cout << can.size() << "\n";
    for0(i, can.size()){
        cout << has[s[can[i]] - '0'][s[can[i] + 1] - '0'].first.first << " ";
        cout << has[s[can[i]] - '0'][s[can[i] + 1] - '0'].first.second << " ";
        cout << has[s[can[i]] - '0'][s[can[i] + 1] - '0'].second << "\n";
    }
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