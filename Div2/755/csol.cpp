#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, n;
int aa, bb;
vector<int> a, b;

void read(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> aa; a.push_back(aa);
    }
    for (int i = 0; i < n; i++){
        cin >> bb; b.push_back(bb);
    }
    // for (int i = 0; i < n; i++) cout << a[i] << " " << b[i] << "\n";

}

void solve(){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // for (int i = 0; i < n; i++) cout << a[i] << " " << b[i] << "\n";

    for (int i = 0; i < n; i++){
        // cout << b[i] - a[i] << " ";
        if (b[i] - a[i] > 1 || b[i] < a[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        a.clear(); b.clear();
        read();
        solve();
    }
}