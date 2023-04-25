#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, l[4];

void read(){
    cin >> l[1] >> l[2] >> l[3];
}

void solve(){
    if (l[1] == l[2]){
        if (l[3] % 2 == 0){
            cout << "YES\n";
            return;
        }

        else{
            cout << "NO\n";
            return;
        }
    }

    if (l[1] == l[3]){
        if (l[2] % 2 == 0){
            cout << "YES\n";
            return;
        }

        else{
            cout << "NO\n";
            return;
        }
    }
    if (l[3] == l[2]){
        if (l[1] % 2 == 0){
            cout << "YES\n";
            return;
        }

        else{
            cout << "NO\n";
            return;
        }
    }

    if (l[1] == l[2] + l[3]){
        cout << "YES\n";
        return;
    }

    if (l[2] == l[1] + l[3]){
        cout << "YES\n";
        return;
    }

    if (l[3] == l[2] + l[1]){
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}