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
    cin >> n >> m;

    vector<int> v(m), a;

    for (int i = 0; i < m; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < m - 1; i++)
        a.push_back(v[i + 1] - v[i] - 1);

    a.push_back((n - v[m - 1]) + (v[0] - 1));

    sort(a.begin(), a.end(), greater<int>());

    int sum = 0, cnt = 0, sz = a.size();

    for (int i = 0; i < sz; i++)
    {
        a[i] -= cnt * 2;

        if (a[i] >= 1)
            sum += max(a[i] - 1, 1), cnt += 2;
    }

    cout << (n - sum) << nline;
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
