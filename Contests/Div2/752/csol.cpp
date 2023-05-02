#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXX = 1e9 + 4;
int T, N, a;
vector<int> A;

void solve(){
    bool big_flag = true;
    for (int n = 0; n < N; n++){
        bool flag = false;
        for (int m = 1; m <= n + 2; m++){
            if (A[n] % m != 0){
                flag = true;
                break;
            }
        }
        if (!flag){
            big_flag = false;
            break;
        }
    }

    if (big_flag) cout << "YES\n";
    else cout << "NO\n";
}

void read(){
    cin >> N;
    for (int n = 0; n < N; n++){
        cin >> a;
        A.push_back(a);
    }
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        A.clear();
        read();
        solve();

    }
}