#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))

const int maxn = 1e5 + 5;
const ll MOD = 5; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;


struct mint{
    ll val;
    mint(){
        val = 0;
    }
    mint(ll x){
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
        if (y == 0) return mint(1);
        if (y == 1) return mint(val);
        mint x = mint(val).pow(y/2);
        if (y % 2 == 0) return x * x;
        else return x * x * mint(val);
    }
    mint operator/(const mint& other){
        return mint(val) * mint(other.val).pow(MOD - 2);
    }

    friend ostream& operator<<(ostream& os, const mint& x);
};

ostream& operator<<(ostream& cout, const mint& x){
    cout << x.val;
    return cout;
}

mint pow_mod[maxn];
void calPowMod(){
    pow_mod[0] = mint(1);
    for (int i = 1; i < maxn; i++) pow_mod[i] = pow_mod[i - 1] * mint(2);
}

mint factor_mod[maxn];
void calFactor(){
    factor_mod[0] = mint(1);
    for (int i = 1; i < maxn; i++) factor_mod[i] = factor_mod[i - 1] * mint(i);
}

mint inv_mod[maxn];
void calInverse(){
    for (int i = 1; i < maxn; i++) inv_mod[i] = mint(i).pow(MOD - 2);
}

int main(){
    calPowMod();
    calFactor();
    calInverse();
    mint x;
    x = factor_mod[5];
    cout << x << "\n";
    x = pow_mod[6];
    cout << x << "\n";
    x = mint(2).pow(3);
    cout << x << "\n";
    cout << inv_mod[3] << "\n";
    for (int i = 1; i < 5; i++){
        cout << mint(i) << " " << mint(i).pow(3) << "\n";
    }
}