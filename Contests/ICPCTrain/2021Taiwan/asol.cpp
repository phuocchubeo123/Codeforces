#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

void solve(){
    int n;
    cin >> n;
    vt<string> names(n);
    vt<pair<pair<int, int>, pair<int, int>>> info(n);
    for0(i, n){
        int g, s, b;
        string name;
        cin >> g >> s >> b;
        getline(cin, name);
        name = name.substr(1, name.length()-1);
        // cout << name << "\n";   
        names[i] = name;
        info[i] = {{g, s}, {b, i}};
    }

    sort(info.begin(), info.end());
    reverse(info.begin(), info.end());
    auto best = info[0];
    auto country = best.second.second;
    cout << names[country] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}