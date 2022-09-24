#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 4, MOD = 998244353;

template <typename T>
struct mint{
    T val;

    mint(){
        val = 0;
    }

    mint(int x){
        while (x >= MOD) x -= MOD;
        while (x < 0) x += MOD;
        val = x;
    }

    bool operator==(const mint& other){
        return val == other.val;
    }

    mint operator+(const mint& other){
        return mint(val + other.val);
    }

    mint operator-(const mint& other){
        return mint(val - other.val);
    }

    mint operator*(const mint& other){
        return mint((val * 1ll * other.val) % MOD);
    }

    mint pow(int y){
        mint z(1);
        mint x(val);
        while (y > 0){
            if (y % 2 == 1) z = z * x;
            x = x * x;
            y /= 2;
        }
        return z;
    }

    mint operator/(const mint& other){
        return mint(val) * mint(other.val).pow(MOD - 2);
    }
};

mint<int> pow_mod[N];

void calPowMod(){
    pow_mod[0] = mint<int>(1);
    for (int i = 1; i < N; i++) pow_mod[i] = pow_mod[i - 1] * mint<int>(2);
}

mint<int> factor_mod[N];

void calFactor(){
    factor_mod[0] = mint<int>(1);
    for (int i = 1; i < N; i++) factor_mod[i] = factor_mod[i - 1] * mint<int>(i);
}

mint<int> inv_mod[N];

mint<int> calInverse(){
    for (int i = 1; i < N; i++) inv_mod[i] = mint<int>(i).pow(MOD - 2);
}

int main(){
    calPowMod();
    calFactor();
    mint<int> x = factor_mod[5];
    cout << x.val;
}