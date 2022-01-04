#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
string a, s;
vector<int> b;

void read(){
    cin >> a >> s;
}

void solve(){
    b.clear();
    int pt = a.size() - 1, pt2 = s.size() - 1;
    while (pt >= 0){
        if (pt2 < 0){
            cout << -1 << "\n";
            return;
        }

        // cout << a[pt] << " " << s[pt2] << "\n";
        if (s[pt2] >= a[pt]){
            b.push_back(s[pt2] - a[pt]);
            pt2--;
        }

        else{
            if (s[pt2 - 1] != '1'){
                cout << -1 << "\n";
                return;
            }

            b.push_back(10 - (a[pt] - s[pt2]));
            pt2 -= 2;
        }
        
        pt--;
    }

    // cout << pt2 << " " << s[pt2] << "\n";

    if (pt2 >= 0){
        while (pt2 >= 0){
            b.push_back(s[pt2] - '0');
            pt2--;
        }
    }

    while (b[b.size() - 1] == 0) b.pop_back();
    reverse(b.begin(), b.end());
    for (int x: b) cout << x;
    cout << "\n";
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}