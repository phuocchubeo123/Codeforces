#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, m, rb, cb, rd, cd;

void prepare(){

}

void read(){
    cin >> n >> m >> rb >> cb >> rd >> cd;
}

void solve(){
    // cout << rb << " " << cb << " " << rd << " " << cd << "\n";
    int r = rb, c = cb, dr = 1, dc = 1;
    int step = 0;
    while (true){
        if (rb == rd || cb == cd){
            cout << step << "\n";
            return;
        }

        if (rb + dr > n || rb + dr < 1) dr = -dr;
        if (cb + dc > m || cb + dc < 1) dc = -dc;
        rb = rb + dr;
        cb = cb + dc;
        step++;
    }
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