#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n;
int a;

int bitNum(int a){
    int a_bit_num = 0;
    while (a > 0){
        a = a >> 1;
        a_bit_num++;
    }
    return a_bit_num;
}

int main(){
    cin >> t;
    // cout << (3 >> 1) << "\n";
    for (int tt = 0; tt < t; tt++){
        array<ll, 100> bit_num;
        fill(bit_num.begin(), bit_num.end(), 0);
        
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a;
            int a_bit_num = bitNum(a);
            bit_num[a_bit_num] = bit_num[a_bit_num] + 1;
        }

        ll total = 0;
        for (ll x: bit_num) total += (x * (x - 1)) / 2;
        cout << total << "\n";
    }
}