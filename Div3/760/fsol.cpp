#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
ll x, y;

void read(){
    cin >> x >> y;
}

string reverseAndClear(string s){
    string new_s = s;

    reverse(new_s.begin(), new_s.end());
    for (int i = 0; i < new_s.size(); i++){
        if (new_s[i] == '1'){
            return new_s.substr(i, new_s.size() - i);
        }
    }

    return "";
}

string bin(ll num){
    if (num == 0) return "0";

    string s = "";
    for (int i = 0; i < 64; i++){
        if (((num >> i) & 1) == 1) s.push_back('1');
        else s.push_back('0');
    }

    // cout << s << "\n";

    s = reverseAndClear(s);

    return s;
}

bool check(string x_bin, string y_bin){
    if (x_bin.size() > y_bin.size()) return false;
    for (int i = 0; i + x_bin.size() - 1 < y_bin.size(); i++){
        if (y_bin.substr(i, x_bin.size()).compare(x_bin) != 0){
            continue;
        }
        
        bool flag = true;

        for (int j = 0; j < i; j++){
            if (y_bin[j] == '0'){
                flag = false;
                break;
            }
        }

        for (int j = i + x_bin.size(); j < y_bin.size(); j++){
            if (y_bin[j] == '0'){
                flag = false;
                break;
            }
        }

        if (flag){
            return true;
        }
    }

    return false;
}

void solve(){
    string x_bin = bin(x), y_bin = bin(y);

    // cout << x_bin << "\n" << y_bin << "\n";
    // if (x_bin.size() > y_bin.size()){
    //     cout << "NO\n";
    //     return;
    // }

    if (x_bin.compare(y_bin) == 0){
        cout << "YES\n";
        return;
    }

    string x_bin_2 = x_bin, x_bin_3 = x_bin;

    x_bin_2.push_back('0'); x_bin_3.push_back('1');
    x_bin_2 = reverseAndClear(x_bin_2); 
    x_bin_3 = reverseAndClear(x_bin_3);
    string x_bin_4 = reverseAndClear(x_bin_2);
    string x_bin_5 = reverseAndClear(x_bin_3);

    // cout << x_bin_2 << "\n";
    // cout << x_bin_3 << "\n";
    // cout << x_bin_4 << "\n";
    // cout << x_bin_5 << "\n";
    // cout << y_bin << "\n";

    bool a1 = check(x_bin_2, y_bin), a2 = check(x_bin_3, y_bin), a3 = check(x_bin_4, y_bin), a4 = check(x_bin_5, y_bin);

    if ((a1 || a2) || (a3 || a4)){
        cout << "YES\n";
        return;
    }

    cout << "NO\n";

    return;
}

int main(){
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}