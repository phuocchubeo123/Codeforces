#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4, MOD = 998244353;
int T, n, x, y, p[N];
vector<int> cl, adj[N], c[N];
Mint pow_mod[N], w[N];

struct Mint{
    int val;

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
        return Mint((val * 1ll * other.val) % (1ll * MOD));
    }

    Mint pow(int y){
        Mint x(val);
        Mint z(1);
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

    Mint(){
        val = 0;
    };

    Mint(int x){
        while (x < 0) x += MOD;
        while (x >= MOD) x -= MOD;
        val = x;
    };
};


void read(){
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void findChild(){
    for (int i = 1; i <= n; i++) p[i] = -1;
    
    stack<int> s;
    s.push(1);

    while (!s.empty()){
        int curr = s.top(); s.pop();
        for (int next: adj[curr]){
            if (p[curr] != next){
                c[curr].push_back(next);
                p[next] = curr;
                s.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (c[i].size() > 0){
            cl.push_back(c[i].size());
        }
    }
}

vector<Mint> ntt(vector<Mint> v){
    vector<Mint> odd, even;
    int length = v.size();
    vector<Mint> v_ntt(length);
    
    for (int i = 0; i < v.size(); i++){
        if (i % 2 == 0) even.push_back(v[i]);
        else odd.push_back(v[i]);
    }

    vector<Mint> odd_ntt = ntt(odd);
    vector<Mint> even_ntt = ntt(even);

    Mint wc = Mint(1);

    for (int i = 0; i < length / 2; i++){
        v_ntt[i] = even_ntt[i] + wc * odd_ntt[i];
        v_ntt[i + length / 2] = even_ntt[i] - wc * odd_ntt[i];
        wc = wc * w[n];
    }
}

void solve(){
    findChild();
}

int main(){
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}