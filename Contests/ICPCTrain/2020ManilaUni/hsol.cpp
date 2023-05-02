#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 4e7 + 4;
int T;

bool isp[N + 1];

void eratosthenesSieve(){
    for1(i, N) isp[i] = 1;
    for1(i, N){
        if (i == 1){
            isp[i] = 0;
            continue;
        }

        for (int j = 2; i * j <= N; j++) isp[i * j] = 0;
    }
}

vt<int> primes;

void prepare(){
    eratosthenesSieve();
    for1(i, N){
        if (isp[i]) primes.pb(i);
    }
}

int num_of_divisors(int x){
    int y = x;
    int nod = 1;
    for (int p: primes){
        if (p * p > y) return nod;
        if (y % p == 0){
            int pow = 1;
            while (y % p == 0){
                y /= p;
                pow++;
            }
            nod *= pow;
        }
    }
    return nod;
}

for1(i, N){
    
}

void solve(){
    int m; cin >> m;
    for (int i = 2; i * i < m; i++){
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}