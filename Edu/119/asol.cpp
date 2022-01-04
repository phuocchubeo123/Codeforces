#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
string s;

void read(){
    cin >> s;
}

void solve(){
    int no = 0;
    for (char c: s){
        if (c == 'N') no++;
    }

    if (no == 0){
        cout << "YES\n";
        return;
    }

    if (no == 1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    return;
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}