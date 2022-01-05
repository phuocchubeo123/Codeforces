#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

int n;

void read(){
    cin >> n;
}

int query(int x){
    int y;
    cout << "? " << x << "\n";
    cout.flush();
    cin >> y;
    return y;
}

int vis[N], p[N];

void solve(){
    for1(i, n) vis[i] = 0;
    for1(i, n){
        if (vis[i]) continue;

        int curr = i;
        curr = query(curr);
        while (true){
            if (vis[curr]) break;
            int next = query(i);
            p[curr] = next;
            vis[curr] = 1;
            curr = next;
        }
    }

    cout << "! ";
    for1(i, n) cout << p[i] << " ";
    cout << "\n";
    cout.flush();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}