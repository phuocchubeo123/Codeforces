#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, p[N];
string s;
vector<pair<int, int>> zero, one;

void read(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    cin >> s;
}

void solve(){
    zero.clear(); one.clear();

    for (int i = 0; i < n; i++){
        if (s[i] == '0'){
            zero.push_back({p[i], i});
        }

        else{
            one.push_back({p[i], i});
        }
    }

    // for (auto p: zero){
    //     cout << p.first << " " << p.second << "\n";
    // }
    // cout << "\n";

    // for (auto p: one){
    //     cout << p.first << " " << p.second << "\n";
    // }

    sort(zero.begin(), zero.end());
    sort(one.begin(), one.end());

    for (int i = 0; i < zero.size(); i++){
        p[zero[i].second] = 1 + i;
    }

    for (int i = 0; i < one.size(); i++){
        p[one[i].second] = zero.size() + i + 1;
    }

    for (int i = 0; i < n; i++) cout << p[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}