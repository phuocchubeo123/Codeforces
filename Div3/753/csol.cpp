#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
int aa;
vector<int> a;

int max(int x, int y){
    if (x < y) return y;
    return x;
}

int main(){
    cin >> t;
    for (int tt=0;tt<t;tt++){
        a.clear();
        int curr = 0;
        int maxx = -1e9;

        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> aa;
            a.push_back(aa);
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++){
            // cout << a[i] << " ";
            // cout << a[i] - curr << " ";
            maxx = max(a[i] - curr, maxx);
            curr = a[i];
            // cout << curr << "\n";
        }
        // cout << "\n";
        cout << maxx << "\n";
    }
}