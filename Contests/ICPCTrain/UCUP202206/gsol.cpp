#include<bits/stdc++.h>

using namespace std;

map<string, vector<int>> p;

void solve(){
    p.clear();
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++){
        for (int j = i; j < s.size(); j++){
            string r = s.substr(i, j-i+1);
            if (p.find(r) == p.end()) p[r] = {};
            if (p[r].size() == 0){
                p[r].push_back(i);
                continue;
            }
            if (p[r].back() + j - i + 1 <= i) p[r].push_back(i);
        }
    }

    string ans = "";
    int fi = s.size();

    for (auto pp: p){
        string r = pp.first;
        vector<int> q = pp.second;

        if (q.size() == 1) continue;

        // cout << r << ": ";
        // for (int i: q) cout << i << " ";
        // cout << "\n";

        if (r.size() < ans.size()) continue;
        if (r.size() > ans.size()){
            ans = r;
            fi = q[0];
            continue;
        }
        if (q[0] < fi){
            ans = r;
            fi = q[0];
            continue;
        }
    }

    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}