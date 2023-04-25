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

void solve(){
    int n; cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int init = 0;
    for0(i, n){
        if (s1[i] == s2[i]) init++;
    }
    cout << init << " ";

    int ans = init, rans = 0, lans = 0;

    for0(i, 2*(n-1)+1){
        if (i % 2 == 0){
            int mid = i / 2;
            int temp = init;
            for1(j, n){
                if (mid - j < 0 || mid + j > n-1) break;
                int l = mid - j, r = mid + j;
                if (s2[l] == s1[l]){
                    if (s2[l] != s1[r]) temp--;
                }
                else{
                    if (s2[l] == s1[r]) temp++;
                }
                if (s2[r] == s1[r]){
                    if (s2[r] != s1[l]) temp--;
                }
                else{
                    if (s2[r] == s1[l]) temp++;
                }

                if (temp > ans){
                    lans = l; rans = r;
                    ans = temp;
                }
                else if (temp == ans){
                    if (rans - lans > r - l){
                        rans = r; lans = l; 
                        ans = temp;
                    }
                }
                else{
                }
            }
        }
        else{
            int mid = i / 2;
            int temp = init;
            for1(j, n){
                if (mid - j + 1 < 0 || mid + j > n-1) break;
                int l = mid - j + 1, r = mid + j;
                if (s2[l] == s1[l]){
                    if (s2[l] != s1[r]) temp--;
                }
                else{
                    if (s2[l] == s1[r]) temp++;
                }
                if (s2[r] == s1[r]){
                    if (s2[r] != s1[l]) temp--;
                }
                else{
                    if (s2[r] == s1[l]) temp++;
                }

                if (temp > ans){
                    lans = l; rans = r;
                    ans = temp;
                }
                else if (temp == ans){
                    if (rans - lans > r - l){
                        rans = r; lans = l; 
                        ans = temp;
                    }
                }
                else{
                }
            }
        }
    }

    cout << ans << " " << lans + 1 << " " << rans + 1 << "\n";
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