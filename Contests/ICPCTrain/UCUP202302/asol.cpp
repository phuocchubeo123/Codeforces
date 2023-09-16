#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
    ll n,i,j;
    string s;
    cin >> n;
    cin >> s;
    vector<ll> v[5];
    for(i=0;i<5;i++){
        v[i].push_back(-1);
    }
    for(i=0;i<n;i++){
        if(s[i]=='s'){
            v[0].push_back(i);
            v[3].push_back(i);
        }

        if(s[i]=='p'){
            v[1].push_back(i);
        }

        if(s[i]=='b'){
            v[2].push_back(i);
        }

        if(s[i]=='u'){
            v[4].push_back(i);
        }
    }
    for(i=0;i<5;i++){
        v[i].push_back(n);
    }
    ll ans;
    ans=1e10+1;
    for(i=0;i<5;i++){
        for(auto so:v[i]){
            ll num=0;
            ll a[5];
            a[i]=so;
            for(j=i-1;j>=0;j--){
                auto it=upper_bound(v[j].begin(),v[j].end(),a[j+1]);
                it--;
                a[j]=*it;
            }
            for(j=i+1;j<5;j++){
                a[j]=*(upper_bound(v[j].begin(),v[j].end(),a[j-1]));
            }
            if(a[0]<0||a[4]>=n){
                continue;
            }
            for(j=i-1;j>=0;j--){
                num=num+abs(a[i]-a[j]-(i-j));
            }
            for(j=i+1;j<5;j++){
                num=num+abs(a[j]-a[i]-(j-i));
            }
            ans=min(ans,num);
        }
    }
    cout << ans;
}