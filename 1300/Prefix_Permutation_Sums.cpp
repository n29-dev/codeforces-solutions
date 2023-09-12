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
  int n;
  cin >> n;

  int m = n - 1;

  vector<ll> v(m);
  unordered_map<ll, ll> mp;

  for (int i = 1; i <= n; i++)
    mp[i] = 0;

  ll gap = -1, prev = 0, diff = 0;
  bool valid = true;

  for (int i = 0; i < m; i++)
  {
    cin>>v[i];
    diff = v[i] - prev;
    prev = v[i];

    if (diff > n)
    {
      if (gap > -1)
        valid = false;
      else
        gap = diff;
    }
    else if (mp[diff] == 1)
    {
      if (gap > -1)
        valid = false;
      else
        gap = diff;
    }
    else
    {
      mp[diff] = 1;
    }
  }

  int cnt = 0;
  ll sum = 0;

  for (auto &pr : mp)
  {
    if (pr.second == 0)
    {
      cnt++;
      sum += pr.first;
    }
  }

  debug(gap);

  if (valid == false || cnt > 2)
  {
    cout << "NO" << nline;
    return;
  }

  if (gap == -1 && cnt == 1)
  {
    cout << "YES" << nline;
    return;
  }

  if (gap == sum)
  {
    cout << "YES" << nline;
    return;
  }
  else
  {
    cout << "NO" << nline;
    return;
  }
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
