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

int aliveMonster(vector<pair<ll, ll>> &v, int i, int n, ll sum)
{
  while (i < n)
  {
    v[i].first -= sum;

    if (v[i].first > 0)
      break;
    else
      i++;
  }

  return i;
}

void solve()
{
  int n, k;
  cin >> n >> k;

  vector<pair<ll, ll>> v(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> v[i].second;
  }

  auto compare = [](pair<ll, ll> &a, pair<ll, ll> &b)
  {
    if (a.second < b.second)
      return 1;
    return 0;
  };

  sort(v.begin(), v.end(), compare);

  debug(v);

  ll sum = 0;
  int i = 0;

  while (i < n && k > 0)
  {
    v[i].first -= sum;

    if (v[i].first < 1)
    {
      i++;
      continue;
    }

    while (k > 0 && v[i].first > 0)
    {
      v[i].first -= k;
      sum += k;

      if (v[i].first > 0)
      {
        k -= v[i].second;
      }
      else
      {
        i = aliveMonster(v, i + 1, n, sum);

        if (i == n)
        {
          break;
        }

        k -= v[i].second;
      }
    }
  }

  debug(v);

  if (v[n - 1].first < 1)
  {
    cout << "YES" << nline;
  }
  else
  {
    cout << "NO" << nline;
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
