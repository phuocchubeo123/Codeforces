#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
ll a, b, c;
ll d;

int main(){
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        cin >> a >> b >> c;
        d = a + b + c - 1;
        cout << d << "\n";
    }
}