#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define sz(a) int((a).size())

const int MOD = 998244353;

struct Mint
{
  int val;

  bool operator==(const Mint& other)
  {
    return val == other.val;
  }

  Mint operator+(const Mint& other)
  {
    int res = val + other.val;
    while(res >= MOD) res -= MOD;
    while(res < 0) res += MOD;
    return Mint(res);
  }

  Mint operator-(const Mint& other)
  {
    int res = val - other.val;
    while(res >= MOD) res -= MOD;
    while(res < 0) res += MOD;
    return Mint(res);  
  }

  Mint operator*(const Mint& other)
  {
    return Mint((val * 1ll * other.val) % MOD);
  }

  Mint pow(int y)
  {
    Mint z(1);
    Mint x(val);
    while(y > 0)
    {
      if(y % 2 == 1) z = z * x;
      x = x * x;
      y /= 2;
    }
    return z;
  }

  Mint operator/(const Mint& other)
  {
    return Mint(val) * Mint(other.val).pow(MOD - 2);
  }

  Mint() {
      val = 0;
  };
  Mint(int x)
  {
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    val = x;
  };
};

ostream& operator<<(ostream& out, const Mint& x)
{
  return out << x.val;
}

const int g = 3;
const int LOGN = 19;

vector<Mint> w[LOGN];
vector<int> rv[LOGN];

void prepare() {
  Mint wb = Mint(g).pow((MOD - 1) / (1 << LOGN));
  forn(st, LOGN - 1) {
    w[st].assign(1 << st, 1);
    Mint bw = wb.pow(1 << (LOGN - st - 1));
    Mint cw = 1;
    forn(k, 1 << st) {
      w[st][k] = cw;
      cw = cw * bw;
    }
  }
  forn(st, LOGN) {
    rv[st].assign(1 << st, 0);
    if (st == 0) {
      rv[st][0] = 0;
      continue;
    }
    int h = (1 << (st - 1));
    forn(k, 1 << st)
      rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
  }
}

void ntt(vector<Mint> &a, bool inv) {
  int n = sz(a);
  int ln = __builtin_ctz(n);
  forn(i, n) {
    int ni = rv[ln][i];
    if (i < ni) swap(a[i], a[ni]);
  }
  forn(st, ln) {
    int len = 1 << st;
    for (int k = 0; k < n; k += (len << 1)) {
      fore(pos, k, k + len){
        Mint l = a[pos];
        Mint r = a[pos + len] * w[st][pos - k];
        a[pos] = l + r;
        a[pos + len] = l - r;
      }
    }
  }
  if (inv) {
    Mint rn = Mint(n).pow(MOD - 2);
    forn(i, n) a[i] = a[i] * rn;
    reverse(a.begin() + 1, a.end());
  }
}

vector<Mint> mul(vector<Mint> a, vector<Mint> b) {
  int cnt = 1 << (32 - __builtin_clz(sz(a) + sz(b) - 1));
  a.resize(cnt);
  b.resize(cnt);
  ntt(a, false);
  ntt(b, false);
  vector<Mint> c(cnt);
  forn(i, cnt) c[i] = a[i] * b[i];
  ntt(c, true);
  return c;
}

vector<Mint> norm(vector<Mint> a)
{
  while(a.size() > 1 && a.back() == Mint(0))
    a.pop_back();
  return a;
}

const int N = 250043;
vector<int> G[N];
int d[N];

Mint fact[N * 2];
Mint rev[N * 2];

void dfs(int x, int p)
{
  if(p != x) d[p]++;
  for(auto y : G[x]) if(y != p) dfs(y, x);
}

Mint C(int n, int k)
{
  return fact[n] * rev[k] * rev[n - k];
}

int main()
{
  prepare();
  fact[0] = Mint(1);
  for(int i = 1; i < N * 2; i++) fact[i] = fact[i - 1] * i;
  for(int i = 0; i < N * 2; i++) rev[i] = Mint(1) / fact[i];
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    G[x].push_back(y);
    G[y].push_back(x);  
  }
  dfs(0, 0);
  vector<vector<Mint>> cur;
  for(int i = 0; i < n; i++)
    if(d[i] > 0)
      cur.push_back(vector<Mint>({Mint(1), Mint(d[i])}));
  while(cur.size() > 1)
  {
    vector<vector<Mint>> ncur;
    for(int i = 0; i + 1 < cur.size(); i += 2)
      ncur.push_back(norm(mul(cur[i], cur[i + 1])));
    if(cur.size() % 2 == 1) ncur.push_back(cur.back());
    cur = ncur;  
  }
  Mint ans = 0;
  for(int i = 0; i < cur[0].size(); i++)
  {
    if(i % 2 == 0) ans = ans + cur[0][i] * fact[n - i];
    else ans = ans - cur[0][i] * fact[n - i];
  }
  cout << ans << endl;
}