#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAX = 1e6;
array<char, MAX> a;
array<bool, MAX+1> changeable;
array<int, MAX+1> min_range;
int n, m;
string s;

bool blocked(int r, int c) {
    return true;
}

bool getCoordinate(int r, int c) {
    return a[r * m + c];
}

void blockedColumns(){
    for (int r = 0; r < n - 1; r++){
        for (int c = 1; c < m; c++){
            if (blocked(r, c)) changeable[c + 1] = true;
        }
    }
}

int main(){
    cin >> n >> m;
    fill(changeable.begin(), changeable.begin() + m + 1, false);

    for (int row = 0; row < n; row++){
        cin >> s;

        for (int col = 0; col < m; col++){
            a[row * m + col] = s[col];
            cout << a[row * m + col];
        }
    }
    blockedColumns();

    array<int, MAX> min_range;
    ll l = 0;
    for (ll r = 1; r <= m; r++){
        if (changeable[r]){
            while (l < r - 1){
                min_range[l++] = r;
            }
        }
    }
    return 0;
}