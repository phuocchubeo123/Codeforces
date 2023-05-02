#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;
bool a[N];
vector<int> impostors, non_im;

void read(){
    cin >> n;
}

int query(int a, int b, int c){
    cout << "? " << a << " " << b << " " << c << "\n\n";
    fflush(stdout);
    int q;
    cin >> q;
    return q; 
}

int cycle(int num){
    if (1 <= num && num <= n) return num;
    else{
        if (num % n == 0) return n;
        else return num % n;
    }
}

void solve(){
    for (int i = 1; i <= n; i++){
        int q = query(i, cycle(i + 1), cycle(i + 2));
        a[i] = q;
    }

    int dif;

    for (int i = 1; i <= n; i++){
        if (a[i] != a[cycle(i + 1)]){
            dif = cycle(i + 1);
            break;
        }
    }

    int ans = 1;
    impostors.clear(); non_im.clear();

    for (int i = 1; i <= n; i++){
        if (i != dif && i != cycle(dif + 1)){
            int q = query(i, dif, cycle(dif + 1));
            if (q == 0){
                ans++;
                impostors.push_back(i);
            }
            else{
                non_im.push_back(i);
            }
        }
    }

    bool q = query(dif, impostors[0], non_im[0]);

    if (q == 0){
        impostors.push_back(dif);
    }

    else{
        impostors.push_back(cycle(dif + 1));
    }

    cout << "! " << ans << " ";
    for (int im: impostors) cout << im << " ";
    cout << "\n\n";
    cout.flush();
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}