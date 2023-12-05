#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
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
#define debug(x)       \
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
    int n, m;
    cin >> n;
    m = n - 1;
    vector<string> v(n);
    vector<char> t;
    char lg;
    ll ans = 0;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int r = 0; r < n / 2; r++)
    {
        for (int c = 0; c < n / 2; c++)
        {
            t.push_back(v[r][c]);
            t.push_back(v[c][m - r]);
            t.push_back(v[m - r][m - c]);
            t.push_back(v[m - c][r]);
            lg = 'a';

            for (int i = 0; i < 4; i++)
                if (t[i] > lg)
                    lg = t[i];

            for (int i = 0; i < 4; i++)
                ans += lg - t[i], t.pop_back();
        }
    }

    cout<<ans<<nline;
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
