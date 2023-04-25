#include <bits/stdc++.h>

using namespace std;

int t;
int n, x;

int main(){
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        cin >> n >> x;
        if (n == 1 || n == 2) cout << "1" << "\n";
        else cout << (n - 3) / x + 2 << "\n";
    }
}