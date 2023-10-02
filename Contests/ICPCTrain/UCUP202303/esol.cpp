#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxn = 1e5;

map<pair<int, int>, int> blk;
map<pair<int, int>, int> alr;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    set<pair<int, int>> ans;
    for (int mask = 0; mask < (1<<n); mask++){
        blk.clear();
        alr.clear();
        int x = 0, y = 0;
        bool flag = true;
        int nx, ny;
        alr[{0, 0}] = 1;
        for (int bit = 0; bit < n; bit++){
            if (s[bit] == 'L'){ nx = x-1; ny = y;}
            if (s[bit] == 'R'){ nx = x+1; ny = y;}
            if (s[bit] == 'U'){ nx = x; ny = y+1;}
            if (s[bit] == 'D'){ nx = x; ny = y-1;}

            if ((mask >> bit) & 1){
                if (blk[{nx, ny}] == 1){
                    flag = false; break;
                }
                x = nx; y = ny;
                alr[{x, y}] = 1;
            }
            else{
                if (alr[{nx, ny}] == 1){
                    flag = false; break;
                }
                blk[{nx, ny}] = 1;
            }
        }

        // for (int bit = 0; bit < n; bit++) cout << ((mask >> bit) & 1);
        // cout << ":\n";
        // for (auto p: blk) cout << p.first.first << " " << p.first.second << " ";
        // cout << "\n";
        // cout << flag << " " << x << " " << y << "\n";

        if (flag) ans.insert({x, y});
    }

    cout << ans.size() << "\n";
    for (auto p: ans){
        cout << p.first << " " << p.second << "\n";
    }
}