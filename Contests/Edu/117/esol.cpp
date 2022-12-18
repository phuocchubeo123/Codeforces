#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
int n;
array<int, N> m, k, prob;
vector<pair<int, int>> stu(N);

void read(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> m[i] >> k[i];
    }
}

void solve(){
    pair<ll, ll> best = {0, 1};
    int ans = 0;
    for (int t = 1; t <= 20; t++){
        ll tmp = 0;
        for (int i = 0; i < N; i++) prob[i] = 0;

        for (int i = 0; i < n; i++){
            if (k[i] >= t) prob[m[i]] += t;
            else prob[m[i]] += k[i];    
        }

        // cout << "test" << t << "\n";
        // for (int i = 0; i < n; i++){
        //     cout << prob[m[i]] << " ";
        // }
        // cout << "\n";

        sort(prob.begin(), prob.end());
        reverse(prob.begin(), prob.end());

        for (int i = 0; i < t; i++) tmp = tmp + (ll) prob[i];

        if (tmp * best.second > best.first * t){
            best.first = tmp;
            best.second = t;
            ans = t;
        }
    }

    for (int i = 0; i < N; i++) prob[i] = 0;
    for (int i = 0; i < N; i++) stu[i].second = i;

    for (int i = 0; i < n; i++){
        if (k[i] >= ans) prob[m[i]] += ans;
        else prob[m[i]] += k[i];    
    }

    for (int i = 0; i < N; i++) stu[i].first = prob[i];
    sort(stu.begin(), stu.end());
    reverse(stu.begin(), stu.end());

    cout << ans << "\n";
    for (int i = 0; i < ans; i++) cout << stu[i].second << " ";
}

int main(){
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}