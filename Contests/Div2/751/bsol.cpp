#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, q, x, k, b;
vector<int> a;
array<int, 2001> cnt; 
vector<vector<int>> all_a;

vector<int> transformation(vector<int> a){
    fill(cnt.begin(), cnt.end(), 0);
    for (int i: a) cnt[i] += 1;
    vector<int> a_after;
    for (int i: a) a_after.push_back(cnt[i]);
    return a_after;
}

int main(){
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        all_a.clear(); a.clear();
        cin >> n;

        for (int i = 0; i < n; i++){
            cin >> b;
            a.push_back(b);
        }

        all_a.push_back(a);
        int len = 0;
        while (true){
            vector<int> a_after = transformation(a);
            if (a_after == a) break;

            len++;
            a = a_after;
            all_a.push_back(a);
        }

        cin >> q;
        for (int i = 0; i < q; i++){
            cin >> x >> k;
            // cout << x << " " << k << "\n";
            if (k >= len) k = len;
            cout << all_a[k][x-1] << "\n";
        }
    }
}