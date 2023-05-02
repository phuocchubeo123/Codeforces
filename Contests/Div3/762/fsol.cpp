#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, m, k, g[N];
vector<int> zero, one, add_zero, add_one, new_zero, new_one;

void read(){
    cin >> n >> m >> k;
}

void solve(){
    int a = n / m, b = a + 1, y = n - m * a, x = m - y;

    zero.clear(); one.clear();
    for (int i = 1; i <= n; i++) zero.push_back(i);

    for (int game = 0; game < k; game++){
        add_one.clear(); add_zero.clear(); new_zero.clear(); new_one.clear();
        int zero_size = zero.size(), one_size = one.size();

        if (zero_size < b * y){
            for (int i = 0; i < zero_size; i++){
                add_one.push_back(zero[i]);
                new_zero.push_back(zero[i]);
            }
            for (int i = 0; i < b * y - zero_size; i++){
                add_one.push_back(one[i]);
                new_one.push_back(one[i]);
            }
            for (int i = b * y - zero_size; i < one_size; i++){
                add_zero.push_back(one[i]);
                new_zero.push_back(one[i]);
            }
        }

        else{
            for (int i = 0; i < b * y; i++){
                add_one.push_back(zero[i]);
                new_one.push_back(zero[i]);
            }
            for (int i = b * y; i < zero_size; i++){
                add_zero.push_back(zero[i]);
                new_zero.push_back(zero[i]);
            }
            for (int i = 0; i < one_size; i++){
                add_zero.push_back(one[i]);
                new_one.push_back(one[i]);
            }
        }

        zero.clear(); one.clear();
        for (int x: new_zero) zero.push_back(x);
        for (int x: new_one) one.push_back(x);

        for (int i = 0; i < b * y; i++){
            if (i % b == 0){
                cout << "\n";
                cout << b << " ";
            }
            cout << add_one[i] << " ";
        }

        for (int i = 0; i < a * x; i++){
            if (i % a == 0){
                cout << "\n";
                cout << a << " ";
            }
            cout << add_zero[i] << " ";
        }
    }

    cout << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}