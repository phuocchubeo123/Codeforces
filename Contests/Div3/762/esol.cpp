#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a[N], cnt[N], cumu[N];
set<int> s;
vector<int> lt;

void read(){
    s.clear();
    cin >> n;
    for (int i = 0; i <= n; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s.insert(a[i]);
        cnt[a[i]]++;
    }
}

void solve(){
    lt.clear();
    cout << cnt[0] << " ";
    for (int i = 0; i < cnt[0]; i++) lt.push_back(0);
    int pt = cnt[0];
    bool flag = false;
    ll ans = 0;

    for (int i = 1; i <= n; i++){
        // cout << "\n";
        // for (int x: lt) cout << x << " ";
        // cout << "\n";
        // for (int x: s) cout << x << " ";
        // cout << "\n";
        if (flag){
            cout << -1 << " ";
            continue;
        }

        if (lt.size() == 0){
            flag = true;
            cout << -1 << " ";
            continue;
        }

        int leq = *(lt.end() - 1);
        // cout << "\n" << leq << "\n";
        // cout << "\n";
        // for (int x: lt) cout << x << " ";
        // cout << "\n";
        lt.pop_back();
        // cout << "\n" << leq << "\n";
        ans += 1ll * (i - 1 - leq);
        cout << ans + 1ll * cnt[i] << " ";

        for (int j = 0; j < cnt[i]; j++) lt.push_back(i);
    }

    cout << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}