#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
int n;
array<int, N> a, b;

void read(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
}

bool can(int x){
    int p = 0;
    
    for (int i = 0; i < n; i++){
        if (x - 1 - a[i] <= p && p <= b[i]) p++;
    }

    return (p >= x);
}

void solve(){
    int pos = 1;
    int jump = n;

    while (jump > 0){
        if (pos + jump > n){
            jump = jump / 2;
            continue;
        }

        if (can(pos + jump)) pos = pos + jump;
        else jump = jump / 2;
    }

    cout << pos << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}