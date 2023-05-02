#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>

vector<string> p = {"-F", "-Cl", "-Br", "-I", "-CH3", "-CH2CH3", "-CH2CH2CH3", "-H"};

void solve(){
    vector<string> r(4);
    forn(i, 4) cin >> r[i];

    vector<int> pr(4);
    forn(i, 4){
        forn(j, 8) if (p[j] == r[i]) pr[i] = j;
    }

    if (pr[0] == pr[2] || pr[1] == pr[3]){
        cout << "None\n";
        return;
    }

    set<int> pri;
    forn(i, 4) pri.insert(pr[i]);
    if (pri.size() < 4){
        if (r[0] == r[1] || r[2] == r[3]){
            cout << "Cis\n";
            return;
        }
        else{
            cout << "Trans\n";
            return;
        }
    }

    int l, rr;
    if (pr[0] < pr[2]) l = 1;
    else l = 3;
    if (pr[1] < pr[3]) rr = 2;
    else rr = 4;

    if (l == 1 && rr == 2){
        cout << "Zasamman\n";
        return;
    }
    if (l == 3 && rr == 4){
        cout << "Zasamman\n";
        return;
    }

    cout << "Entgegen\n";
    return;
}

int main(){
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
} 