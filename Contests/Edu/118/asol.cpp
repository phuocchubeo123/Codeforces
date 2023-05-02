#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, x[3], p[3];

void read(){
    cin >> x[1] >> p[1] >> x[2] >> p[2];
}

int digitNum(int x){
    int tmp = x;
    int digit_num = 0;
    while (tmp > 0){
        tmp /= 10;
        digit_num++;
    }
    return digit_num;
}

void solve(){
    int n1 = digitNum(x[1]);
    int n2 = digitNum(x[2]);

    if (n1 == 0 && n2 == 0){
        cout << "=\n";
        return;
    }

    if (n1 == 0){
        cout << "<\n";
        return;
    }

    if (n2 == 0){
        cout << ">\n";
        return;
    }

    if (n1 + p[1] > n2 + p[2]){
        cout << ">\n";
        return;
    }

    if (n1 + p[1] < n2 + p[2]){
        cout << "<\n";
        return;
    }

    if (n1 < n2){
        while (n1 < n2){
            x[1] *= 10;
            n1++;
        }
    }

    else {
        while (n1 > n2){
            x[2] *= 10;
            n2++;
        }
    }

    // cout << n1 << " " << n2 << "\n";
    // return;

    if (x[1] > x[2]){
        cout << ">\n";
        return;
    }

    if (x[1] == x[2]){
        cout << "=\n";
        return;
    }

    if (x[1] < x[2]){
        cout << "<\n";
        return;
    }
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}