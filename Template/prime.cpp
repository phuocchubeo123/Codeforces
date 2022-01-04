#include <bits/stdc++.h>

using namespace std;
#define for1(i, n) for (int i = 1; i <= n; i++)

typedef long long ll;

const int N = 2e5 + 4;

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

int main(){
    eratosthenesSieve();
    cout << isp[1] << "\n";
}