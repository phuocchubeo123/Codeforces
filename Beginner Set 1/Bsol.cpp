#include <bits/stdc++.h>

using namespace std;

int t;
int n;

int main(){
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        cin >> n;
        if (n == 1) cout << 0 << "\n";
        else if (n == 2) cout << 1 << "\n";
        else{
            float m = sqrt(n + 1);
            int p = (int) m;
            cout << p - 1 + ((n - 1) / p) << "\n";
        }
    }
}