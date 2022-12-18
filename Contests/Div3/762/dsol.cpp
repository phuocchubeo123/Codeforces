#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 4;
int T, n, m;
ll c[N], l[N], pp;
vector<vector<ll>> p;
vector<vector<bool>> a;

void read(){
    p.clear();
    cin >> m >> n;
    // cout << m << " " << n << "\n";
    p.push_back({});
    for (int i = 1; i <= m; i++){
        p.push_back({});
        p[i].push_back(0);
        for (int j = 1; j <= n; j++){
            cin >> pp;
            p[i].push_back(pp);
        }
    }

}

bool can(int num){
    // cout << num << "\n";
    a.clear();
    for (int j = 1; j <= n; j++) c[j] = 0;
    for (int i = 1; i <= m; i++) l[i] = 0;

    a.push_back({});
    for (int i = 1; i <= m; i++){
        // a.push_back({});
        for (int j = 1; j <= n; j++){
            if (p[i][j] >= num){
                // a[i].push_back(1);
                c[j] = 1;
                l[i]++;
            }
            // else a[i].push_back(0);
        }
    }

    // for (auto x: p){
    //     for (auto y: x){
    //         if (y) cout << 1 << " ";
    //         else cout << 0 << " ";
    //     }
    //     cout << "\n";
    // }

    // for (auto x: a){
    //     for (auto y: x){
    //         if (y) cout << 1 << " ";
    //         else cout << 0 << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for (int j = 1; j <= n; j++){
        if (c[j] == 0) return false;
    }

    if (m <= n - 1) return true;

    // cout << "l: ";
    // for (int i = 1; i <= m; i++) cout << l[i] << " ";
    // cout << "\n";

    for (int i = 1; i <= m; i++){
        if (l[i] >= 2) return true;
    }

    return false;
}

void solve(){
    ll l = 0, h = 1e9 + 4;
    while (l < h){
        ll m = l + (h - l + 1) / 2;
        // cout << l << " " << h << " " << (h - l + 1) / 2 << " " << m << "\n";
        if (can(m)) l = m;
        else h = m - 1;
    }

    cout << l << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}