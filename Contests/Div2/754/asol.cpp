#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int N, M;
int a, b, c;

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        cin >> a >> b >> c;
        if (abs(a + c - 2 * b) % 3 == 0) cout << 0 << "\n";
        else cout << 1 << "\n";
        // cout << 0 << "\n";
    }
}