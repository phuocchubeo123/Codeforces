#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 4;
int T, n, a[N], cnt[N];

void read(){
    // cout << "\n";
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

bool findParity(){
    int vis[n];
    for (int i = 1; i <= n; i++) vis[i] = 0;

    int even = 0;

    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;

        int curr = i, start = i, length = 1;
        while (true){
            curr = a[curr];
            // cout << curr << "\n";
            vis[curr] = 1;
            
            if (curr == start) break;
            else length++;
        }

        // cout << length << " ";
        cout << "";

        if (length % 2 == 0){
            even++;
        }
    }

    // cout << even << "\n";

    return (even % 2 == 0);
}

void solve(){
    for (int i = 1; i <= n; i++) cnt[a[i]] = 0;
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    for (int i = 1; i <= n; i++){
        if (cnt[a[i]] > 1){
            cout << "YES\n";
            return;
        }
    }

    bool parity = findParity();

    if (parity) cout << "YES\n";
    else cout << "NO\n";

    return;
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}