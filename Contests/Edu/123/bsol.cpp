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

    if (n % 2 == 0){
        for0(i, n){
            for0(j, i) cout << n - j - 1 << " ";
            cout << n << " ";
            forlr(j, i, n - 1, 1) cout << n - j - 1 << " ";
            cout << "\n";
        }
    }

    if (n % 2 == 1){
        for0(i, n){
            if (i == n / 2 + 1) continue;
            for0(j, i) cout << n - j - 1 << " ";
            cout << n << " ";
            forlr(j, i, n - 1, 1) cout << n - j - 1 << " ";
            cout << "\n";
        }

        if (n == 3){
            cout << 3 << " " << 1 << " " << 2 << "\n";
        }
        else{
            for0(i, n - 3) cout << n - i - 1 << " ";
            cout << 1 << " " << 2 << " " << n << "\n";
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