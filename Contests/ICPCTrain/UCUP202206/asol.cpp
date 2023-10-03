#include<bits/stdc++.h>

using namespace std;

#define ll long long

map<string, char> h;

string s;

void prepare(){
    h["UUU"] = 'F';
h["UUC"] = 'F';
h["UUA"] = 'L';
h["UUG"] = 'L';
h["CUU"] = 'L';
h["CUC"] = 'L';
h["CUA"] = 'L';
h["CUG"] = 'L';
h["AUU"] = 'I';
h["AUC"] = 'I';
h["AUA"] = 'I';
h["AUG"] = 'M';
h["GUU"] = 'V';
h["GUC"] = 'V';
h["GUA"] = 'V';
h["GUG"] = 'V';
h["UCU"] = 'S';
h["UCC"] = 'S';
h["UCA"] = 'S';
h["UCG"] = 'S';
h["AGU"] = 'S';
h["AGC"] = 'S';
h["CCU"] = 'P';
h["CCC"] = 'P';
h["CCA"] = 'P';
h["CCG"] = 'P';
h["ACU"] = 'T';
h["ACC"] = 'T';
h["ACA"] = 'T';
h["ACG"] = 'T';
h["GCU"] = 'A';
h["GCC"] = 'A';
h["GCA"] = 'A';
h["GCG"] = 'A';
h["UAU"] = 'Y';
h["UAC"] = 'Y';
h["CAU"] = 'H';
h["CAC"] = 'H';
h["CAA"] = 'Q';
h["CAG"] = 'Q';
h["AAU"] = 'N';
h["AAC"] = 'N';
h["AAA"] = 'K';
h["AAG"] = 'K';
h["GAU"] = 'D';
h["GAC"] = 'D';
h["GAA"] = 'E';
h["GAG"] = 'E';
h["UGU"] = 'C';
h["UGC"] = 'C';
h["UGG"] = 'W';
h["CGU"] = 'R';
h["CGC"] = 'R';
h["CGA"] = 'R';
h["CGG"] = 'R';
h["AGA"] = 'R';
h["AGG"] = 'R';
h["GGU"] = 'G';
h["GGC"] = 'G';
h["GGA"] = 'G';
h["GGG"] = 'G';
h["UAA"] = '0';
h["UAG"] = '0';
h["UGA"] = '0';
}

void solve(){
    string r;
    cin >> r;
    for (int i = 0; i < r.size(); i+= 3){
        string s = r.substr(i, 3);
        if (h[s] == '0'){
            cout << "\n";
            return;
        }
        cout << h[s];
    }
    cout << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    prepare();
    while (t--){
        solve();
    }
}