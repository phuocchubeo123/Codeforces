#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, N;
string s;
int ans;
int a, b, c;

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        cin >> N;
        cin >> s;
        s.insert(N, "ddddddddd");
        // cout << s << "\n";

        ans = 10;
        a = 0; b = 0; c = 0;
        for (int n = 0; n < N; n++){
            if (s.substr(n, 2) == "aa") ans = min(ans, 2);

            else if (s.substr(n, 3) == "aba" || s.substr(n, 3) == "aca") ans = min(ans, 3);

            else if (s.substr(n, 4) == "abca" || s.substr(n, 4) == "acba") ans = min(ans, 4);

            else if (s.substr(n, 7) == "abbacca" || s.substr(n, 7) == "accabba") ans = min(ans, 7);
        }

        if (ans == 10) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}