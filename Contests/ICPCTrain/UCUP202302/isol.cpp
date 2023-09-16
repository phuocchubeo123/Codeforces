#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    if (n % 2 == 0){
        int ans = 2;
        int x = (n - 2) / 2;
        ans += 2 * (x / 3);
        cout << ans << " " << n << "\n";
    }
    else{
        int ans = 1;
        int x = (n-1) / 2;
        ans += 2 * (x / 3);
        cout << ans << " " << n << "\n";
    }
}