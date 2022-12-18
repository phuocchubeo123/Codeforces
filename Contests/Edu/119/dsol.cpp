#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a[105];

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

// bool check(int x, int y, int z){
//     for (int i = 1; i <= n; i++){
//         if (a[i] % 3 == 0){
//             if (a[i] / 3 > (x + min(y, z))) return false;
//         }

//         if (a[i] % 3 == 1){
//             if (((a[i] - 1) / 3 > x + min(y, z - 1)) && ((a[i] - 4) / 3 > x + min(y - 2, z))) return false;
//         }

//         if (a[i] % 3 == 2){
//             if (((a[i] - 2) / 3 > x + min(y - 1, z)) && ((a[i] - 2) / 3 > x + min(y, z - 1))) return false;
//         }
//     }
// }

void solve(){
    // if (n == 1){
    //     cout << (a[1] + 2) / 3 << "\n";
    // }
    sort(a + 1, a + n + 1);
    // for (int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << "\n";
    bool one = false, two = false;
    for (int i = 1; i <= n; i++){
        if (a[i] % 3 == 1) one = true;
        if (a[i] % 3 == 2) two = true;
    }

    bool minus = false;
    for (int i = 1; i <= n; i++){
        if (a[i] == a[n] - 1) minus = true;
    }

    if (a[n] % 3 == 0){
        if (one && two){
            cout << a[n] / 3 + 1;
        }

        else if (one){
            cout << a[n] / 3 + 1;
        }

        else if (two){
            cout << a[n] / 3 + 1;
        }

        else{
            cout << a[n] / 3;
        }
    }

    else if (a[n] % 3 == 1){
        if (two){
            if (a[1] == 1){
                cout << a[n] / 3 + 2;
            }

            else{
                if (minus) cout << a[n] / 3 + 2;
                else cout << a[n] / 3 + 1;
            }
        }

        else{
            cout << a[n] / 3 + 1;
        }
    }

    else if (a[n] % 3 == 2){
        if (one){
            cout << a[n] / 3 + 2;
        }

        else{
            cout << a[n] / 3 + 1;
        }
    }

    cout << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}