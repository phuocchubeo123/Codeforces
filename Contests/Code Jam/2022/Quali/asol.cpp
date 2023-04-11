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

int tt = 0;

void solve(){
    int r, c;
    cin >> r >> c; 
    tt++;
    cout << "Case #" << tt << ":\n";
    for0(i, 2 * r + 1){
        if (i == 0){
            cout << "..";
            for0(j, c - 1) cout << "+-";
            cout << "+\n";
        }

        else if (i == 1){
            cout << "..";
            for0(j, c - 1) cout << "|.";
            cout << "|\n";
        }

        else if (i % 2 == 0){
            for0(j, c) cout << "+-";
            cout << "+\n";
        }

        else if (i % 2 == 1){
            for0(j, c) cout << "|.";
            cout << "|\n";
        }
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