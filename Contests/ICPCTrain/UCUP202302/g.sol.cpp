#include<bits/stdc++.h>

using namespace std;

#define ll int
const ll maxN=1e5;
bitset<maxN> num[maxN];
bitset<maxN> remain,query,can;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,i,j,m,q;
    cin >> n >> m;
    ll a,b,u,v;
    for(i=0;i<m;i++){
        cin >> a >> b;
        num[a-1][i]=1;
        num[b-1][i]=1;
    }
    remain=~remain;
    cin >> q;
    char qr;
    for(i=1;i<=q;i++){
        cin >> qr;
        if(qr!='?'){
            cin >> u;
            query^=num[u];
        }
        else{
            can=(query&remain);
            v=can._Find_first();
            if(v<m){
                remain[v]=0;
                cout << v+1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
    }
}