#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n, k;

void solve(ll n, ll k){
    ll transferred = 1;
    ll total_day = 0;
    while (transferred < n){
        if (transferred < k){
            transferred = transferred * 2;
            total_day++;
        }
        else{
            // cout << "> k" << transferred << "\n";
            total_day = total_day + ((n - transferred - 1) / k + 1);
            transferred = n;
        }
    }
    cout << total_day << "\n";
}

int main(){
    cin >> t;
    for (int tt=0; tt<t; tt++){
        cin >> n >> k;
        solve(n, k);
    }
}