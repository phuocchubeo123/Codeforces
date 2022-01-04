#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
int n, x, y;
array<int, N> a;

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void solve(){
    // cout << "new test\n";
    bool flag = true;
    for (int i = 1; i <= n; i++){
        // cout << i << ": ";
        // cout << a[i] << " " << a[n + 1 - i] << "\n";
        if (a[i] != a[n + 1 - i]){
            // cout << "detect\n";
            x = a[i];
            y = a[n + 1 - i];
            flag = false;
            break;
        }
    }

    if (flag){
        cout << "YES\n";
        return;
    }

    int R = n, L = 1;
    flag = true;
    while (L < R){
        if (a[L] == a[R]){
            L++;
            R--;
        }

        else{
            if (a[L] == x){
                L++;
            }

            else if (a[R] == x){
                R--;
            }

            else{
                flag = false;
                break;
            }
        }
    }

    if (flag){
        cout << "YES\n";
        return;
    }

    R = n; L = 1;
    flag = true;
    while (L < R){
        if (a[L] == a[R]){
            L++;
            R--;
        }

        else{
            if (a[L] == y){
                L++;
            }

            else if (a[R] == y){
                R--;
            }

            else{
                flag = false;
                break;
            }
        }
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";

}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}