#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, aa;
string s;
vector<int> a, blue, red;
vector<bool> color;

int main(){
    cin >> t;
    for (int tt=0;tt<t;tt++){
        a.clear(); color.clear(); blue.clear(); red.clear();
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> aa;
            a.push_back(aa);
        }

        cin >> s;
        for (char c: s){
            if (c == 'B') color.push_back(true);
            if (c == 'R') color.push_back(false);
        }
        
        for (int i=0;i<n;i++){
            if (color[i]){
                blue.push_back(a[i]);
            }
            else red.push_back(a[i]);
        }

        sort(blue.begin(), blue.end());
        sort(red.begin(), red.end());

        bool flag = true;

        for (int i =0; i< blue.size(); i++){
            int x = blue[i];
            int curr = i+1;
            if (blue[i] < i+1) flag = false;
        }

        for (int i = 0; i < red.size(); i++){
            int x = red[i];
            int curr = n - red.size() + i + 1;
            if (x > curr) flag = false;
        }

        if (flag) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}