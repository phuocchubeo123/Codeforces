#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
ll a, b;

void read(){
    cin >> a >> b;

    if (a > b){
        ll tmp = a;
        a = b;
        b = tmp;
    }
}

void solve(){
    if (b <= 3 * a){
        cout << (a + b) / 4 << "\n";
    }

    else{
        cout << a << "\n";
    }
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}