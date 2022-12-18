#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 2e5 + 4, MOD = 998244353;

struct mint{
    ll val;

    mint(){
        val = 0;
    }

    mint(int x){
        val = 1ll * x;
        if (val < 0) val = MOD - (-val) % MOD;
        if (val >= MOD) val %= MOD;
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

    void operator+=(const mint& other){
        val = (mint(val) + other).val;
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

mint pow_mod[N];

void calPowMod(){
    pow_mod[0] = mint(1);
    for (int i = 1; i < N; i++) pow_mod[i] = pow_mod[i - 1] * mint(2);
}

mint factor_mod[N];

void calFactor(){
    factor_mod[0] = mint(1);
    for (int i = 1; i < N; i++) factor_mod[i] = factor_mod[i - 1] * mint(i);
}

mint inv_mod[N];

mint calInverse(){
    for (int i = 1; i < N; i++) inv_mod[i] = mint(i).pow(MOD - 2);
}

int main(){
    calPowMod();
    calFactor();
    mint x = factor_mod[5];
    cout << x.val;
}