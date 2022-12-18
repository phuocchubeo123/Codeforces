#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
string n;

void read(){
    cin >> n;
}

bool isEven(char c){
    if (c == '0') return true;
    if (c == '2') return true;
    if (c == '4') return true;
    if (c == '6') return true;
    if (c == '8') return true;
    return false;
}

void solve(){
    if (isEven(n[n.size() - 1])){
        cout << 0 << "\n";
        return;
    }

    if (isEven(n[0])){
        cout << 1 << "\n";
        return;
    }

    for (int i = 0; i < n.size(); i++){
        if (isEven(n[i])){
            cout << 2 << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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