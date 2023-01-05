#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

int n, k;

void read(){
    cin >> n >> k;
}

void solve(){
    if (k > (n + 1) / 2){
        cout << -1 << "\n";
        return;
    }

    for1(i, n){
        for1(j, n){
            if (i != j){
                cout << '.';
                continue;
            }

            if (i % 2 == 0){
                cout << '.';
                continue;
            }

            if (i + 1 <= 2 * k) cout << 'R';
            else cout << '.';
        }

    cout << "\n";
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