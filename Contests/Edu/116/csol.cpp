#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, k;
vector<int> a;
int aa;

int main(){
    cin >> t;
    for (int tt=0; tt<t; tt++){
        a.clear();
        cin >> n >> k;

        for (int i=0;i<n;i++){
            cin >> aa;
            a.push_back(aa);
        }

        int remaining = k + 1;
        ll ans = 0;
        for (int i=0;i<n-1;i++){
            ll max_sub = pow(10, a[i+1] - a[i]) - 1;
            if (remaining <= max_sub){
                ans = ans + remaining * pow(10, a[i]); 
                remaining = 0;
                break;
            }
            else{
                ans = ans + max_sub * pow(10, a[i]);
                remaining = remaining - max_sub;
            }
        }

        ans = ans + remaining * pow(10, a[n-1]);
        cout << ans << "\n";
    }
}