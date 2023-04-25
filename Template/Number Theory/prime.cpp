#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define for1(i,n) for(int i=1;i<=n;i++)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;


bool isp[maxn];

void eratosthenesSieve(){
    forn(i, maxn) isp[i] = true;
    isp[0] = false;
    rep(i, 1, maxn-1){
        if (i == 1){
            isp[i] = false;
            continue;
        }

        for (int j = 2; i * j < maxn; j++) isp[i * j] = false;
    }
}

vi primes;

void findPrimes(){
    forn(i, maxn) if (isp[i]) primes.push_back(i);
}

bool checkPrime(int x){
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= x; i++){
        if (x % primes[i] == 0) return false; 
    }
    return true;
}

int main(){
    eratosthenesSieve();
    findPrimes();
    forn(i, 10) cout << primes[i] << " ";
    cout << "\n";
    cout << checkPrime(125) << "\n";
    cout << checkPrime(7) << "\n";
    cout << checkPrime(91019) << "\n";
    cout << checkPrime(48409) << "\n";
}