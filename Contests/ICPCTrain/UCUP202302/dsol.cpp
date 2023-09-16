#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> ans;

    bool flip = false;

    if (n == m){
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++){
            ans.push_back({i, 1});
        }
        for (int i = 2; i <= n-1; i++){
            ans.push_back({i, m});
        }
        cout << ans.size() << "\n";
        for (pair<int, int> p: ans) cout << p.first << " " << p.second << "\n";
        return 0;
    }

    if (n > m){
        int tmp = m;
        m = n;
        n = tmp;
        flip = true;
    }

    for (int i = 1; i <= n; i += 1){
        ans.push_back({i, 1});
    }

    for (int i = 1; i <= n; i++){
        ans.push_back({i, m});
    }

    if (n % 2 == 0){
        for (int i = n/2+2; i <= m-n/2-1; i+=2){
            ans.push_back({n/2, i});
            ans.push_back({n/2+1, i});
        }
    }

    else{
        for (int i = n/2+2; i <= m - n/2 - 1; i++){
            ans.push_back({n/2+1, i});
        }
    }

    if (flip){
        vector<pair<int, int>> ans2;
        for (pair<int, int> p: ans){
            ans2.push_back({p.second, p.first});
        }
        ans = ans2;
    }

    cout << ans.size() << "\n";
    
    for (pair<int, int> p: ans){
        cout << p.first << " " << p.second << "\n";
    }

}