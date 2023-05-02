#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a[N];
bool done[N];
vector<int> need_change;

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
    need_change.clear();

    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] > n) need_change.push_back(a[i]);
        else{
            if (done[a[i]]) need_change.push_back(a[i]);
            else done[a[i]] = 1;
        }
    }

    sort(need_change.begin(), need_change.end());
    // for (int i = 1; i <= n; i++) cout << done[i] << " ";
    // cout << "\n";
    // for (int x: need_change) cout << x << " ";
    // cout << "\n";

    int pt = 1, ans = 0;
    for (int x: need_change){
        while (done[pt]) pt++;
        if (x == pt || (x - 1) / 2 >= pt){
            done[pt] = 1;
            ans++;
        }

        else{
            cout << -1 << "\n";
            return;
        }
    }

    cout << ans << "\n";
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