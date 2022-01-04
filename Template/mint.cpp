#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 4, MOD = 998244353;

struct Mint{
    int val;

    Mint(){
        val = 0;
    }

    Mint(int x){
        while (x >= MOD) x -= MOD;
        while (x < 0) x += MOD;
        val = x;
    }

    bool operator==(const Mint& other){
        return val == other.val;
    }

    Mint operator+(const Mint& other){
        return Mint(val + other.val);
    }

    Mint operator-(const Mint& other){
        return Mint(val - other.val);
    }

    Mint operator*(const Mint& other){
        return Mint((val * 1ll * other.val) % MOD);
    }

    Mint pow(int y){
        Mint z(1);
        Mint x(val);
        while (y > 0){
            if (y % 2 == 1) z = z * x;
            x = x * x;
            y /= 2;
        }
        return z;
    }

    Mint operator/(const Mint& other){
        return Mint(val) * Mint(other.val).pow(MOD - 2);
    }
};

Mint pow_mod[N];

void calPowMod(){
    pow_mod[0] = Mint(1);
    for (int i = 1; i < N; i++) pow_mod[i] = pow_mod[i - 1] * Mint(2);
}

Mint factor_mod[N];

void calFactor(){
    factor_mod[0] = Mint(1);
    for (int i = 1; i < N; i++) factor_mod[i] = factor_mod[i - 1] * Mint(i);
}

Mint inv_mod[N];

Mint calInverse(){
    for (int i = 1; i < N; i++) inv_mod[i] = Mint(i).pow(MOD - 2);
}

int main(){
    calPowMod();
    calFactor();
    Mint x = factor_mod[5];
    cout << x.val;
}