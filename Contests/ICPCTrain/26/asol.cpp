#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a, b, A[N], B[N];

void prepare(){

}

void read(){
    cin >> n >> a >> b;
    int x;
    for (int i = 1; i <= 100; i++){
        A[i] = 0;
        B[i] = 0;
    }

    for (int i = 1; i <= a; i++){
        cin >> x;
        A[x] = 1;
    }

    for (int i = 1; i <= b; i++){
        cin >> x;
        B[x] = 1;
    }
}

void solve(){
    // cout << 5 << "\n";
    for (int i = 1; i <= n; i++){
        if (A[i] == 1){
            cout << 1 << " ";
        }
        else{
            cout << 2 << " ";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cout << 5 << "\n";
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}