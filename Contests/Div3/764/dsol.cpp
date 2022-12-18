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

void prepare(){

}

vt<int> cnt(26);

bool can(int m, int k, int even, int odd){
    if (m % 2 == 0){
        if (m * k <= even) return true; 
        else return false;
    }

    else{
        if (k <= odd){
            if ((m - 1) * k <= even) return true;
            else return false;
        }

        else{
            if ((k - odd) % 2 == 0){
                if ((m - 1) * k <= even - (k - odd)) return true;
                else return false;
            }
            else{
                if ((m - 1) * k <= even - (k - odd + 1)) return true;
                else return false;
            }
        }
    }
}

void solve(){
    fill(cnt.begin(), cnt.end(), 0);
    int n, k; 
    cin >> n >> k;
    string s;
    cin >> s;
    for (char c: s) cnt[c - 'a']++;
    int even = 0, odd = 0;
    for0(i, 26){
        if (cnt[i] % 2 == 0) even += cnt[i];
        else{
            odd += 1;
            even += (cnt[i] - 1);
        }
    }

    // cout << odd << " " << even << "\n";

    int l = 0, r = n / k;
    while (l < r){
        int m = l + (r - l + 1) / 2;
        if (can(m, k, even, odd)) l = m;
        else r = m - 1;
    }

    cout << l << "\n";
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