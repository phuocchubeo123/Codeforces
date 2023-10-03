    #include<bits/stdc++.h>

    using namespace std;

    #define ll long long

    void solve(){
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];   

        int ans = 0;

        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (a[i] > a[j]) ans++;
            }
        }
        cout << ans << "\n";
    }

    int main(){
        int t; cin >> t;
        while (t--){
            solve();
        }
    }