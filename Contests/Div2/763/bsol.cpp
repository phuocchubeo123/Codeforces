#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, l, r, remain[N];
vector<pair<int, int>> pr;

void prepare(){

}

void read(){
    pr.clear();
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> l >> r;
        pr.push_back({l, r});
    }
}

void solve(){
    sort(pr.begin(), pr.end(), [&](pair<int, int> x, pair<int, int> y){
        return x.second - x.first <= y.second - y.first;
    });

    for (int i = 1; i <= n; i++) remain[i] = 1;

    for (auto x: pr){
        // cout << x.first << ", " << x.second << "\n";
        for (int y = x.first; y <= x.second; y++){
            if (remain[y] == 1){
                cout << x.first << " " << x.second << " " << y << "\n";
                remain[y] = 0;
                break;
            }
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
        read();
        solve();
    }
}