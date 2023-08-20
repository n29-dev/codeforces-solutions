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
  vector<pair<int, int>> v(n);
  int small = 1e9 + 1;
  int big = -1;

  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first;
    v[i].second = i;

    small = min(v[i].first, small);
    big = max(v[i].first, big);
  }

  if (small == big)
  {
    cout << 0 << nline;
  }
  else if (small == 1)
  {
    cout << (-1) << nline;
  }
  else
  {
    vector<pair<int, int>> ans;
    sort(v.begin(), v.end());
    small = v[0].first;

    int q;

    for (int j = 0; j < 30; j++)
    {
      for (int i = 0; i < n; i++)
      {
        q = v[i].first / small;

        if (q * small < v[i].first)
          q++;

        if (q >= 2)
        {
          v[i].first = q;
          ans.push_back(make_pair(v[i].second + 1, v[0].second + 1));
        }
      }

      sort(v.begin(), v.end());
      small = v[0].first;

      if (v[0] == v[n - 1])
      {
        break;
      }
    }

    cout << ans.size()<< nline;
    for(int i = 0; i < ans.size(); i++){
      cout<<ans[i].first<<" "<<ans[i].second<<nline;
    }
    // debug('v')
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
