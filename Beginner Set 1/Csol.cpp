#include <bits/stdc++.h>

using namespace std;

int t;
int n, m;
int a, b, c, d;

int main(){
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        cin >> n >> m;
        bool flag = false;
        for (int i = 0; i < n; i++){
            cin >> a >> b >> c >> d;
            if (b == c) flag = true;
        }
        
        if (m % 2 == 0 && flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}