#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, b[7];

void read(){
    for (int i = 0; i < 7; i++){
        cin >> b[i];
    }
}

void solve(){
    int sum_three = b[6];
    int one = b[0];
    int two_three = b[5];
    int one_three = b[4];
    int two = sum_three - one_three;
    int three = one_three - one;
    cout << one << " " << two << " " << three << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}