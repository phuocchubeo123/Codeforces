#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4, LOG = 19;
int T, pow2[N];

void prepare(){
    pow2[0] = 1;
    for1(i, N - 1) pow2[i] = pow2[i - 1] * 2;
}

vt<int> csum(N);

int segSum(int l, int r){
    if (l == 0) return csum[r];
    return csum[r] - csum[l - 1];
}

void solve(){
    int n; cin >> n;     
    vt<int> a(n), cnt(n + 1, 0);
    for0(i, n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for0(i, n + 1) csum[i] = 0;
    int tot = 0;
    for0(i, n + 1){
        tot += cnt[i];
        csum[i] = tot;
    }
    
    // for0(i, n + 1) cout << csum[i] << " ";
    // cout << "\n";
    
    int ans = 1e9 + 4;
    int ansi, ansj, ansk, ansx, ansy;

    for0(i, LOG){
        for0(j, LOG){
            for0(k, LOG){
                int l = 0, r = n;
                while (l < r){
                    int m = l + (r - l + 1) / 2;
                    if (segSum(0, m) > pow2[i]) r = m - 1;
                    else l = m;
                }
                int x = l;
                if (x == n){
                    // cout << i << " " << j << " " << k << "\n";
                    if (ans > pow2[i] + pow2[j] + pow2[k] - n){
                        ansi = i;
                        ansj = j; 
                        ansk = k;
                        ansx = x;
                        ansy = x + 1;
                    }
                    ans = min(ans, pow2[i] + pow2[j] + pow2[k] - n);
                    continue;
                }

                l = x; r = n;
                while (l < r){
                    int m = l + (r - l + 1) / 2;
                    if (segSum(x + 1, m) > pow2[j]) r = m - 1;
                    else l = m;
                }
                int y = l;
                

                if (y == n){
                    // cout << i << " " << j << " " << k << "\n";
                    if (ans > pow2[i] + pow2[j] + pow2[k] - n){
                        ansi = i;
                        ansj = j; 
                        ansk = k;
                        ansx = x;
                        ansy = y;
                    }
                    ans = min(ans, pow2[i] + pow2[j] + pow2[k] - n);
                    continue;
                }

                if (segSum(y + 1, n) <= pow2[k]){
                    if (ans > pow2[i] + pow2[j] + pow2[k] - n){
                        ansi = i;
                        ansj = j; 
                        ansk = k;
                        ansx = x;
                        ansy = y;
                    }
                    ans = min(ans, pow2[i] + pow2[j] + pow2[k] - n);
                }
            }
        }
    }

    cout << ans << "\n";
    // cout << ansi << " " << ansj << " " << ansk << " " << ansx << " " << ansy << "\n";
    // cout << segSum(0, ansx) << " " << segSum(ansx + 1, ansy) << " " << segSum(ansy + 1, n) << "\n";
    // cout << "\n";
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