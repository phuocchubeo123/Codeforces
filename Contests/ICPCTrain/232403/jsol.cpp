#include<bits/stdc++.h>

using namespace std;

const int LOG = 21;
const int maxn = 1e6 + 5;

int st[maxn][LOG];
int lg[maxn];

int query(int l, int r){
    return max(st[l][lg[r-l+1]], st[r - (1 << lg[r-l+1]) + 1][lg[r-l+1]]);
}

void solve(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s.push_back('0');
    reverse(s.begin(), s.end());
    int n = s.size() - 1;

    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;

    vector<int> pre(n+1);
    int num0 = 0;
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + ((s[i] == '0') ? 1 : -1);
        num0 += (s[i] == '0') ? 1 : 0;
    }

    // for (int i = 1; i <= n; i++) cout << s[i];
    // cout << "\n";

    // for (int i = 1; i <= n; i++) cout << pre[i] << " ";
    // cout << "\n";

    for (int i = 1; i <= n; i++) st[i][0] = pre[i];
    for (int j = 1; j < LOG; j++){
        for (int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]); 
        }
    }

    int q; cin >> q;
    
    for (int _ = 0; _ < q; _++){
        int k; cin >> k;
        int cnt = 0;
        int cur = n;
        for (int i = 1; i <= n; i++){
            if (s[i] == '1'){
                if (cnt == k) break;
                cnt++;
            }
            cur = i;
        }
        
        int ans = query(1, cur);
        for (int i = 2; i <= n; i++){
            if (s[i-1] == '1'){
                cnt--;
                for (int j = cur+1; j <= n; j++){
                    if (s[j] == '1'){
                        if (cnt == k) break;
                        cnt++;
                    }
                    cur = j;
                }
            }
            ans = max(ans, query(i, cur) - pre[i-1]);
        }

        cout << min(ans + k, num0) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    solve();
}