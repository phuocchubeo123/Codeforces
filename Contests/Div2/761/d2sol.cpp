#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, q;
bool a[N];
vector<int> impostors, non_im;

void read(){
    cin >> n;
}

void query(int a, int b, int c){
    cout << "? " << a << " " << b << " " << c << "\n\n";
    fflush(stdout);
    cin >> q;
}

int cycle(int num){
    if (1 <= num && num <= n) return num;
    else{
        if (num % n == 0) return n;
        else return num % n;
    }
}

void findFirstImpostorFirstNot(){
    for (int i = 1; i <= n; i += 3){
        query(i, cycle(i + 1), cycle(i + 2));
        a[i] = q;
    }

    int dif;

    for (int i = 1; i <= n; i += 3){
        bool flag = false;
        if (a[i] != a[cycle(i + 3)]){
            for (int j = 1; j <= 2; j++){
                query(cycle(i + j), cycle(i + j + 1), cycle(i + j + 2));
                a[cycle(i + j)] = q;
            }

            for (int j = 0; j <= 2; j++){
                if (a[cycle(i + j)] != a[cycle(i + j + 1)]){
                    dif = cycle(i + j + 1);
                    flag = true;
                    break;
                }
            }
        }

        if (flag) break;
    }

    if (a[cycle(dif + n - 1)] == 0){
        impostors.push_back(cycle(dif + n - 1));
        non_im.push_back(cycle(impostors[0] + 3));
    }

    else{
        impostors.push_back(cycle(dif + 2));
        non_im.push_back(cycle(dif + n - 1));
    }

}

void findAllImpostors(){
    for (int i = 1; i <= n; i += 3){
        if (impostors[0] >= i && impostors[0] <= i + 2){
            for (int j = i; j <= i + 2; j++){
                if (j != impostors[0]){
                    query(j, impostors[0], non_im[0]);
                    if (q == 0) impostors.push_back(j);
                    else non_im.push_back(j);
                }
            }
        }

        else if (non_im[0] >= i && non_im[0] <= i + 2){
            for (int j = i; j <= i + 2; j++){
                if (j != non_im[0]){
                    query(j, impostors[0], non_im[0]);
                    if (q == 0) impostors.push_back(j);
                    else non_im.push_back(j);
                }
            }
        }

        else{
            if (a[i] == 0){
                query(non_im[0], i, i + 1);
                if (q == 0){
                    impostors.push_back(i);
                    impostors.push_back(i + 1);

                    query(i + 2, impostors[0], non_im[0]);
                    if (q == 0) impostors.push_back(i + 2);
                    else non_im.push_back(i + 2);
                }

                else{
                    impostors.push_back(i + 2);

                    query(i, impostors[0], non_im[0]);
                    if (q == 0){
                        impostors.push_back(i);
                        non_im.push_back(i + 1);
                    }

                    else{
                        impostors.push_back(i + 1);
                        non_im.push_back(i);
                    }
                }
            }

            else{
                query(impostors[0], i, i + 1);
                if (q == 1){
                    non_im.push_back(i);
                    non_im.push_back(i + 1);

                    query(i + 2, impostors[0], non_im[0]);
                    if (q == 0) impostors.push_back(i + 2);
                    else non_im.push_back(i + 2);
                }

                else{
                    non_im.push_back(i + 2);

                    query(i, impostors[0], non_im[0]);
                    if (q == 0){
                        impostors.push_back(i);
                        non_im.push_back(i + 1);
                    }

                    else{
                        impostors.push_back(i + 1);
                        non_im.push_back(i);
                    }
                }
            }
        }
    }
}

void solve(){
    int ans = 1;
    impostors.clear(); non_im.clear();

    findFirstImpostorFirstNot();
    findAllImpostors();

    cout << "! " << impostors.size() << " ";
    for (int x: impostors) cout << x << " ";
    cout << "\n";
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