#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
ll aa;
array<int, 31> cnt;

void countBit(ll aa){
    int bit_pos = 0;
    while (aa > 0){
        cnt[bit_pos] += aa % 2;
        aa = aa >> 1;
        bit_pos++;
    }
}

int gcd(int a, int b){
    if (a == 0) return b;

    if (b == 0) return a;

    if (a > b) return gcd(b, a);

    if (b % a == 0) return a;

    return gcd(a, b % a);
}

int main(){
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        fill(cnt.begin(), cnt.end(), 0);

        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> aa;
            countBit(aa);
        }

        int curr = 0;
        for (int bit_num: cnt) curr = gcd(bit_num, curr);
        for (int i = 1; i <= n; i++){
            if (curr % i == 0) cout << i << " ";
        }
        cout << "\n";
    }
}