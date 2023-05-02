#include <bits/stdc++.h>

using namespace std;

int t;
int n;

int main(){
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        cin >> n;

        int total = 0;
        vector<int> a;
        int x;
        for (int i = 0; i < n; i++){
            cin >> x;
            total += x;
            a.push_back(x);
        }

        if (total == 0) cout << "NO" << "\n";
        else if (total < 0){
            cout << "YES" << "\n";
            sort(a.begin(), a.end());
            for (int x: a) cout << x << " ";
            cout << "\n";
        }
        else{
            cout << "YES" << "\n";
            sort(a.begin(), a.end());
            reverse(a.begin(), a.end());
            for (int x: a) cout << x << " ";
            cout << "\n";
        }
    }
}