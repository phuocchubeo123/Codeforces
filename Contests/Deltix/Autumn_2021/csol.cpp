#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4, M = 1e6 + 4;
int T, n, e, a[N], is_prm[M], prod[N];
vector<int> primes, ones, arr, b;
ll bonus;

void read(){
    cin >> n >> e;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    ll ans = 0;
    for (int i = 1; i <= e; i++){
        // cout << "i: " << i << "\n";
        arr.clear(); b.clear();

        for (int j = 0; i + j * e <= n; j++){
            arr.push_back(a[i + j * e]);
        }
    
        // cout << "arr: ";
        // for (int j: arr) cout << j << " ";
        // cout << "\n";

        for (int j = 0; j < arr.size(); j++){
            if (arr[j] != 1) b.push_back(j);
        }

        // cout << "b: ";
        // for (int j: b) cout << j << " ";
        // cout << "\n";

        for (int j = 0; j < b.size(); j++){
            if (!is_prm[arr[b[j]]]) continue;

            if (j == 0 && j == b.size() - 1){
                // cout << "bingo";
                // cout << " " << arr.size() - b[j];
                bonus = 1ll * (b[j] + 1) * (arr.size() - b[j]);
                // cout << bonus << " ";
            }

            else if (j == 0){
                bonus = 1ll * (b[j + 1] - b[j]) * (b[j] + 1);
            }

            else if (j == b.size() - 1){
                bonus = 1ll * (b[j] - b[j - 1]) * (arr.size() - b[j]);
            }

            else{
                bonus = 1ll * (b[j] - b[j - 1]) * (b[j + 1] - b[j]);
            }
            // cout << j << " " << b[j] << " " << bonus << "\n";
            ans += (bonus - 1);

        }

        // cout << "ans: " << ans << "\n";
    }

    cout << ans << "\n";
}

void calPrime(){
    is_prm[0] = 0;
    is_prm[1] = 0;
    
    for (int i = 2; i < M; i++) is_prm[i] = 1;

    for (int i = 2; i < M; i++){
        for (int j = 2; j * i < M; j++) is_prm[i * j] = 0;
    }
}

int main(){
    calPrime();
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}