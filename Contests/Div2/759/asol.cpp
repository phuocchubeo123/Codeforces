#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, water[N];

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> water[i];
}

void solve(){
    int consecutive = 0, not_water = 0, tall = 1;

    for (int i = 1; i <= n; i++){
        if (water[i]){
            consecutive++;
            not_water = 0;
            tall++;
            if (consecutive >= 2) tall += 4;
        }

        else{
            not_water++;
            consecutive = 0;
            if (not_water >= 2){
                cout << -1 << "\n";
                return;
            }
        }
    }

    cout << tall << "\n";
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