#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, N;
int a;
vector<int> A;

void solve(){
    if (N % 2 == 0){
        cout << "YES" << "\n";
        return;
    }

    for (int n = 1; n < N; n++){
        if (A[n] <= A[n-1]){
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
    return;
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        A.clear();
        cin >> N;
        for (int n = 0; n < N; n++){
            cin >> a;
            A.push_back(a);
        }
        solve();
    }
}