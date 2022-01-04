#include <bits/stdc++.h>

using namespace std;

int t, n, a, tot;
vector<int> arr;
bool isComposite(int num){
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0) return true;
    }
    return false;
}

bool isEven(int num){
    return num % 2 == 0;
}

void solve(){
    tot = 0;
    for (int i: arr) tot += i;
    if (isComposite(tot)){
        cout << n << "\n";
        for (int ind = 0; ind < n; ind++) cout << ind + 1 << " ";
        cout << "\n";
    }
    else {
        bool found_odd = false;
        cout << n - 1 << "\n";
        for (int ind =0; ind < n; ind++){
            int num = arr[ind];
            if (isEven(num) || found_odd) cout << ind + 1 << " ";
            else found_odd = true;
        }
        cout << "\n";
    }
}

void read(){
    arr.clear();
    cin >> n;
    for (int j = 0; j < n; j++){
        cin >> a; arr.push_back(a);
    }
}

int main(){
    cin >> t;
    for (int i = 0; i < t; i++){
        read();
        solve();
    }
    return 0;
}