#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
const int maxn = 1e5+5;
 
int n, m, d;
int sq;
int small[maxn], large[maxn];
int step[maxn];
bool mark[maxn];
 
void update(int a, int b){
    int block = (a - 1) / sq;
    int mx = min((block + 1) * sq, n);
    small[a] = min(a+b, n+1);
    large[a] = (small[a] > mx) ? small[a] : large[small[a]];
    step[a] = (small[a] > mx) ? 1 : step[small[a]] + 1;
    mark[a] = true;

    for (int i = a-1; i > block * sq; i--){
        if (mark[small[i]] && small[i] <= a){
            large[i] = large[small[i]];
            step[i] = step[small[i]] + 1;
            mark[i] = true;
        }
    }

    for (int i = a; i > block * sq; i--) mark[i] = false;
}
 
void solve(){
    cin >> n >> m;
    sq = sqrt(n);
    for (int i = 1; i <= n; i++){
        cin >> d;
        small[i] = min(n+1, i+d);
        large[i] = 0;
    }
 
    for (int i = 0; i < n / sq + 1; i++){
        int mx = min((i+1) * sq, n);
        for (int j = mx; j > i * sq; j--){
            if (small[j] > mx){
                large[j] = small[j];
                step[j] = 1;
            }
            else{
                large[j] = large[small[j]];
                step[j] = step[small[j]] + 1;
            }
        }
    }
 
    for (int _ = 0; _ < m; _++){
        int t; cin >> t;
        if (t == 0){
            int a, b; cin >> a >> b;
            update(a, b);
        }
        else{
            int a; cin >> a;
            int ans = 0, last = a;
            while (a < n+1){
                ans += step[a];
                last = a;
                a = large[a];
            }

            while (small[last] < n+1) last = small[last];

            cout << last << " " << ans << "\n";
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    solve();
    // cout << "done\n";
}