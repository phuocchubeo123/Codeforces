#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
void solve(){
    ll m,i,j,num,ul,numij;
    cin >> m;
    num=m*m+1;
    ll n[num],s[num],w[num],e[num];
    for(i=1;i<num;i++){
        cin >> n[i] >> s[i] >> w[i] >> e[i];
        if(n[i]==-1&&w[i]==-1){
            ul=i;
        }
 
   }
   ll ans[m+1][m+1];
   for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            if(i==1&&j==1){
                ans[i][j]=ul;
                continue;
            }
            if(j==1){
                ans[i][j]=s[ans[i-1][j]];
                continue;
            }
            ans[i][j]=e[ans[i][j-1]];
        }
   }
   for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            cout << ans[i][j];
            if(j!=m){
                cout << " ";
            }
        }
        cout << "\n";
   }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--){
        solve();
    }
}