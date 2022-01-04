#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 4, S = 300;
int T, n, q, t, x, y, i, k, p[N], p300[N], inv[N];

void read(){
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
}

void firstQuery(){
    int tmp = p[x];
    p[x] = p[y];
    p[y] = tmp;

    tmp = inv[p[x]];
    inv[p[x]] = inv[p[y]];
    inv[p[y]] = tmp;

    int curr1 = p[x], curr2 = p[x], curr3 = p[y], curr4 = p[y];
    for (int s = 0; s < S; s++) curr2 = p[curr2];
    for (int s = 0; s <= S + 1; s++){
        p300[curr1] = curr2;
        curr1 = inv[curr1];
        curr2 = inv[curr2];
    }

    for (int s = 0; s < S; s++) curr4 = p[curr4];
    for (int s = 0; s <= S + 1; s++){
        p300[curr3] = curr4;
        curr3 = inv[curr3];
        curr4 = inv[curr4];
    }
    
    // for (int id = 0; id < n; id++) cout << p[id] << " ";
    // cout << "\n";
    // for (int id = 0; id < n; id++) cout << inv[id] << " ";
    // cout << "\n";
    // for (int id = 0; id < n; id++) cout << p300[id] << " ";
    // cout << "\n";
}

void secondQuery(){
    int curr = i;
    while (k >= S){
        k -= S;
        curr = p300[curr];
    }
    while (k--) curr = p[curr];
    
    cout << curr + 1 << "\n";
}

void solve(){
    for (int i = 0; i < n; i++){
        int curr = i;
        for (int s = 0; s < S; s++) curr = p[curr];
        p300[i] = curr;
    }

    for (int i = 0; i < n; i++) inv[p[i]] = i;

    // for (int id = 0; id < n; id++) cout << p[id] << " ";
    // cout << "\n";
    // for (int id = 0; id < n; id++) cout << inv[id] << " ";
    // cout << "\n";
    // for (int id = 0; id < n; id++) cout << p300[id] << " ";
    // cout << "\n";

    for (int qq = 0; qq < q; qq++){
        cin >> t;
        if (t == 1){
            cin >> x >> y;
            x--; y--;
            // cout << x << " " << y << "\n";
            firstQuery();
        }
        else{
            cin >> i >> k;
            i--;
            secondQuery();
        }
    }
}

int main(){
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}