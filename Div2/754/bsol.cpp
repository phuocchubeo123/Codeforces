#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int T, N, ans, x;
string A;

bool isSorted(){
    for (int n = 1; n <= N - 1; n++){
        if (A[n] > A[n + 1]) return false;
    }
    return true;
}

void reVerse(int ind1, int ind2){
    int tmp = A[ind1];
    A[ind1] = A[ind2];
    A[ind2] = tmp;
}

int findBalance(){
    int zero = 0;
    for (int n = 1; n <= N; n++){
        if (A[n] == '0') zero++;
    }

    int one = 0;

    for (int n = 1; n <= N; n++){
        if (A[n] == '1') one++;
        if (A[n] == '0') zero--;

        if (one == zero){
            cout << 2 * one << " ";
            return n;
        }
    }

    return -1;
}

void findSortIndex(){
    for (int n = 1; n <= x; n++){
        if (A[n] == '1') cout << n << " ";
    }

    for (int n = x + 1; n <= N; n++){
        if (A[n] == '0') cout << n << " ";
    }

    cout << "\n";
}

void solve(){
    if (isSorted()){
        cout << 0 << "\n";
        return;
    }

    cout << 1 << "\n";

    x = findBalance();

    findSortIndex();
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        cin >> N >> A;
        A.insert(0, "0");
        solve();
    }
}