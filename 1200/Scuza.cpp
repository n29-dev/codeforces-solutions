#include <bits/stdc++.h>
using namespace std;

#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
  cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p)
{
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
  cerr << "[ ";
  for (auto i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

void solve()
{
  int n, q;
  cin >> n >> q;

  int big = -1;
  ll prev = 0;

  vector<ll> v(n);
  vector<int> m(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];

    big = max(big * 1ll, v[i]);
    m[i] = big;

    prev += v[i];
    v[i] = prev;
  }

  vector<ll> ans(q);

  int y, t;

  for (int i = 0; i < q; i++)
  {
    cin >> y;
    t = upper_bound(m.begin(), m.end(), y) - m.begin();

    if (t != 0)
      ans[i] = v[t - 1];
  }

  for (int i = 0; i < q; i++)
  {
    cout << ans[i] << " ";
  }
  
  cout << nline;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("/home/nazib/Desktop/cf/Error.txt", "w", stderr);
#endif
  fastio();
  int TC;
  cin >> TC;

  while (TC)
  {
    solve();
    TC--;
  }
}
