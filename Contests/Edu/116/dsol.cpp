#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int m, n;
vector<vector<int>> a;
vector<int> rowIndex;
vector<vector<pair<int, int>>> min_max;
int aa;

bool cmpRow(int x, int y){
    for (int c = 0; c < m; c++){
        if (a[x][c] > a[y][c]) return true;
        if (a[x][c] < a[y][c]) return false;
    }
    return true;
}

void sortRow(){
    sort(rowIndex.begin(), rowIndex.end(), cmpRow);
}

void findMinMax(){

}

bool check(int r){
    return true;
}

int main(){
    cin >> t;
    for (int tt=0;tt<t;tt++){
        a.clear(); rowIndex.clear();

        cin >> n >> m;
        for (int r=0;r<n;r++){
            vector<int> empty_vec;
            a.push_back(empty_vec);
            rowIndex.push_back(r);

            for (int c=0;c<m;c++){
                cin >> aa;
                a[r].push_back(aa);
            }
        }

        for (int i: rowIndex) cout << i << " ";
        cout << "\n";
        // for (vector<int> b: a){
        //     for (int bb:b) cout << bb << " "; 
        //     cout << "\n";
        // }

        sortRow();

        findMinMax();

        for (int i: rowIndex) cout << i << " ";
        cout << "\n";
        
        bool ans = false;
        for (int i = 0; i < n; i++){
            ans = check(i);
            if (ans) break;
        }
        if (not ans) cout << "NO" << "\n";
    }
}