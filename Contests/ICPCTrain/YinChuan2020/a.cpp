#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>

void solve(){
    int n; cin >> n;
    vi x(n), y(n), z(n);

    forn(i, n){
        cin >> x[i] >> y[i] >> z[i];
    }

    set<pair<int, int>> xx, yy, zz;

    forn(i, n){
        zz.insert({x[i], y[i]});
        xx.insert({y[i], z[i]});
        yy.insert({x[i], z[i]});
    }

    int X = xx.size(), Y = yy.size(), Z = zz.size();

    if (X >= Y && X >= Z){
        cout << "X\n";
        return;
    }

    if (Y >= Z && Y >= X){
        cout << "Y\n";
        return;
    }

    if (Z >= X && Z >= Y){
        cout << "Z\n";
        return;
    }
}

int main(){
    int T = 1;
    while (T--){
        solve();
    }
}