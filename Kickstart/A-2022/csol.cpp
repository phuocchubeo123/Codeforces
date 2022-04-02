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

vt<string> bitrep(64);
vt<int> can(64);

bool isPalindrome(string s){
    string s2 = s;
    reverse(s2.begin(), s2.end());
    if (s2 == s) return true;
    else return false;
}

void prepare(){
    for0(i, 64){
        string s = "";
        for0(j, 6){
            if ((i >> j) & 1) s.pb('1');
            else s.pb('0');
        }
        reverse(s.begin(), s.end());
        bitrep[i] = s;

        string s1 = s.substr(0, 5), s2 = s.substr(1, 5), s3 = s;
        if (isPalindrome(s1) || isPalindrome(s2) || isPalindrome(s3)) can[i] = 0;
        else can[i] = 1;
    }
}

int tt = 0;
void solve(){
    tt++;
    cout << "Case #" << tt << ": ";
    int n;
    string S;
    cin >> n >> S;

    if (S.size() <= 4){
        cout << "POSSIBLE\n";
        return;
    }

    if (S.size() == 5){
        int tot = 0;
        for (char c: S) if (c == '?') tot++;
        if (tot >= 2) cout << "POSSIBLE\n";
        else if (S[2] == '?' && isPalindrome(S)) cout << "IMPOSSIBLE\n";
        else cout << "POSSIBLE\n";
        return;
    }

    string fin6 = S.substr(S.size() - 6, 6);
    // cout << fin6 << "\n";
    vt<int> need;
    for0(i, 6) if (fin6[i] != '?') need.pb(i);

    if (S.size() == 6){
        for0(i, 64){
            string s = bitrep[i];
            bool flag = true;
            for (int x: need){
                if (s[x] != fin6[x]){
                    flag = false;
                    break;
                }
            }

            if (!flag) continue;

            if (can[i]){
                cout << "POSSIBLE\n";
                return;
            }
        }
        cout << "IMPOSSIBLE\n";
        return;
    }

    vt<vt<int>> dp(n + 1, vt<int> (64, 0));

    if (S[0] == '?'){
        for0(j, (1 << 6)){
            if (!can[j]){
                continue;
            }

            int jj = (j >> 1);
            int j1 = jj, j2 = (1 << 5) + jj;
            if (can[j1] || can[j2]) dp[0][j] = 1;
        }
    }

    else{
        for0(j, 64){
            if (!can[j]){
                continue;
            }

            int jj = (j >> 1) + (S[0] - '0') * (1 << 5);
            if (can[jj]) dp[0][j] = 1;
        }
    }

    // for0(i, 64){
    //     cout << bitrep[i] << " " << can[i] << "\n";
    // }
    // cout << dp[0][3] << "\n";

    for1(i, n - 1){
        if (S[i] == '?'){
            for0(j, 64){
                if (!can[j]){
                    continue;
                }

                int jj = (j >> 1);
                int j1 = jj, j2 = 32 + jj;
                if (dp[i - 1][j1] || dp[i - 1][j2]) dp[i][j] = 1;
            }       
        }

        else{
            for0(j, 64){
                if (!can[j]) continue;

                int jj = (j >> 1) + (S[i] - '0') * 32;
                if (dp[i - 1][jj]) dp[i][j] = 1;
            }
        }
    }

    for0(i, 64){
        string s = bitrep[i];
        bool flag = true;
        for (int x: need){
            if (s[x] != fin6[x]){
                flag = false;
                break;
            }
        }

        if (!flag) continue;
        if (dp[n - 7][i]){
            cout << "POSSIBLE\n";
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        solve();
    }
}