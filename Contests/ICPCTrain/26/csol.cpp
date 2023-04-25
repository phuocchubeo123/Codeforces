#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 4;
int T, n, m, x, in[N], can[N], pres[N];
char c;
vector<pair<int, int>> l;

void prepare(){

}

void read(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> c;
        cin >> x;
        
        if (c == '+') l.push_back({1, x});

        else l.push_back({0, x});
    }
}

void solve(){
    int pres, cnt;
    vector<int> cannot;

    int first_one = -1;
    for (int i = 1; i <= n; i++) in[i] = 0;

    for (auto p: l){
        if (p.first == 0){
            if (in[p.second] == 0){
                first_one = p.second;
                pres = 1;
                cnt = 1;
            }
            
            else in[p.second]--;
        }

        else in[p.second]++;
    }

    for (auto p: l){
        if (p.first == 1){
            if (first_one == -1){
                first_one = p.second;
                pres = 0;
                cnt = 0;
            }
            break;
        }
    }

    if (first_one != -1){
        for (auto p: l){
            if (p.first == 1){
                cnt++;
                if (p.second == first_one) pres++;
            }

            else{
                cnt--;
                if (p.second == first_one) pres--;
            }

            if (pres == 0 && cnt > 0){
                cannot.push_back(first_one);
                break;
            } 
        }
    }
    // cout << first_one << "\n";

    for (auto p: l){
        if (p.first == 1 && p.second != first_one){
            cannot.push_back(p.second);
        }
    }

    reverse(l.begin(), l.end());
    first_one = -1;
    for (int i = 1; i <= n; i++) in[i] = 0;

    for (auto p: l){
        if (p.first == 1){
            if (in[p.second] == 0){
                first_one = p.second;
                pres = 1;
                cnt = 1;
            }
            
            else in[p.second]--;
        }

        else in[p.second]++;
    }

    for (auto p: l){
        if (p.first == 0){
            if (first_one == -1){
                first_one = p.second;
                pres = 0;
                cnt = 0;
            }
            break;
        }
    }

    if (first_one != -1){
        // cout << first_one << "\n";
        for (auto p: l){
            if (p.first == 0){
                cnt++;
                if (p.second == first_one) pres++;
            }

            else{
                cnt--;
                if (p.second == first_one) pres--;
            }

            if (pres == 0 && cnt > 0){
                cannot.push_back(first_one);
                break;
            } 
        }
    }


    for (auto p: l){
        if (p.first == 0 && p.second != first_one){
            cannot.push_back(p.second);
        }
    }

    int boss[N];
    for (int i = 1; i <= n; i++) boss[i] = 1;
    for (int x: cannot){
        boss[x] = 0;
    } 

    int ans = 0;
    for (int i = 1; i <= n; i++) if (boss[i] == 1) ans++;
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) if (boss[i] == 1) cout << i << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}