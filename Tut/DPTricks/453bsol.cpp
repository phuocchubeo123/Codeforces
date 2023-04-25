#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 101;
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

int bitmask[61];
vector<int> primes;

void prepare(){
    eratosthenesSieve();
    for1(i, 60) if (isp[i]) primes.pb(i);
    cout << primes.size();

    for1(i, 60){
        int bm = 0;
        for0(j, primes.size()) if (i % j == 0) bm |= 1 << j;
        bitmask[i] = bm;
    }
}

int n;
ll dp[101][1 << 17], a[N];

void read(){
    cin >> n;
    for1(i, n) cin >> a[i];
}


void solve(){
    for0(j, 1 << 17) dp[1][j] = 1e9 + 4;
    for1(i, 60) dp[1][bitmask[i]] = min(abs(a[1] - 1ll * i), dp[1][bitmask[i]]);

    for1(i, n - 1){
        for1(j, 60){
            
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}