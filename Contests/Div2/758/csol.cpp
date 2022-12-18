#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4, MAXN = 1e9 + 4;
int T, n, a[N], b[N], pos_a[N], pos_b[N], corr_a[N], corr_b[N], can[N];
pair<int, int> a_sorted[N], b_sorted[N];


void read(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a_sorted[i] = {a[i], i};
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        b_sorted[i] = {b[i], i};
    }
}

void solve(){
    int max_a, winner;

    sort(a_sorted + 1, a_sorted + n + 1);
    sort(b_sorted + 1, b_sorted + n + 1);

    for (int i = 1; i <= n; i++){
        // cout << b_sorted[i].first << " " << b_sorted[i].second << "\n";
        pos_a[a_sorted[i].second] = i;
        pos_b[b_sorted[i].second] = i;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << pos_b[i] << " ";
    // }
    // cout << "\n";

    int min_b = MAXN;
    int min_a = MAXN;
    int min_ib, min_ia;

    for (int i = n; i >= 1; i--){
        if (b[a_sorted[i].second] < min_b){
            min_b = b[a_sorted[i].second];
            min_ib = pos_b[a_sorted[i].second];
            // cout << min_b << " " << min_ib << "\n";
        }
        corr_b[i] = min_ib;

        if (a[b_sorted[i].second] < min_a){
            min_a = a[b_sorted[i].second];
            min_ia = pos_a[b_sorted[i].second];
            // cout << min_b << " " << min_ib << "\n";
        }
        corr_a[i] = min_ia;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << corr_b[i] << " " << corr_a[i] << "\n";
    // }
    // cout << "\n";

    int curr_a = n;
    int curr_b = corr_b[curr_a];

    while (true){
        curr_a = corr_a[curr_b];
        curr_b = corr_b[curr_a];

        if (curr_a == curr_b) break;
    }

    for (int i = 1; i <= n; i++) can[i] = 0;

    for (int i = curr_a; i <= n; i++){
        can[a_sorted[i].second] = 1;
    }

    for (int i = 1; i <=n ;i++) cout << can[i];
    
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