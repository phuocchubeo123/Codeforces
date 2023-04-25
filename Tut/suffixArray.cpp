#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct suffix {
    int val;
    int left;
    int right;
    char chr;

    suffix(int val_in, char chr_in, int left_in = 0, int right_in = 0){
        val = val_in;
        chr = chr_in;
        left = left_in;
        right = right_in;
    }
};

class suffixArray{
    public:
        int length;
        string init_str;
        vector<int> ranking;
        vector<int> suffix_rank;
        vector<suffix> all_suffixes;

        suffixArray (int len, string str) {
            length = len;
            init_str = str;
            for (int i = 0; i < length; i++){
                ranking.push_back(i);
            }
            for (int i = 0; i < length; i++){
                all_suffixes.push_back(suffix(i, init_str[i]));
            }
        }

        static bool cmpSuffix(suffix a, suffix b){
            return (a.left < b.left) || (a.left == b.left && a.right < b.right);
        }
        
        static bool firstCmp(suffix a, suffix b){
            return a.chr < b.chr;
        }

        void firstSort(){
            sort(all_suffixes.begin(), all_suffixes.end(), firstCmp);
        }

        void firstUpdateRank(){
            int cnt = 0;
            for (int i = 0; i < length; i++){
                suffix curr_suffix = all_suffixes[i];
                if (i == 0){
                    ranking[curr_suffix.val] = 0; 
                }
                else {
                    suffix prev_suffix = all_suffixes[i-1];
                    if (curr_suffix.chr != prev_suffix.chr) cnt++;
                    ranking[curr_suffix.val] = cnt; 
                }
            }
        }

        void assignRank(int sffx_sz){
            for (int i = 0; i < length; i++){
                suffix curr_suffix = all_suffixes[i];
                curr_suffix.left = ranking[curr_suffix.val];
                curr_suffix.right = ranking[(curr_suffix.val + sffx_sz) % length];
                all_suffixes[i] = curr_suffix;
            }
        }

        void sortSuffix(){
            sort(all_suffixes.begin(), all_suffixes.end(), cmpSuffix);
        }

        void printSuffix(suffix sfx){
            for (int i = sfx.val; i < length; i++) cout << init_str[i];
            for (int i = 0; i< sfx.val; i++) cout << init_str[i];
            cout << "\n";
        }

        void printSuffixes(){
            for (suffix sfx: all_suffixes) printSuffix(sfx);
            cout << "\n";
        }

        void updateRank(){
            int cnt = 0;
            for (int i = 0; i < length; i++){
                suffix curr_suffix = all_suffixes[i];
                if (i == 0){
                    ranking[curr_suffix.val] = 0;
                }
                else{
                    suffix prev_suffix = all_suffixes[i-1];
                    if (prev_suffix.left != curr_suffix.left || prev_suffix.right != curr_suffix.right){
                        cnt++;
                    }
                    ranking[curr_suffix.val] = cnt;
                }
            }
        }

        void buildSuffixArray(){
            firstSort();
            firstUpdateRank();

            for (int i=0;pow(2,i) <= 2 * length; i++){
                assignRank(pow(2,i));
                sortSuffix();
                updateRank();
            }
        }
};


int main(){
    string str;
    cin >> str;
    str = str.append("$");
    suffixArray sffx = suffixArray(str.length(), str);
    sffx.buildSuffixArray();
    // cout << sffx.length << " ";
    for (suffix sfx: sffx.all_suffixes) cout << sfx.val << " ";
}