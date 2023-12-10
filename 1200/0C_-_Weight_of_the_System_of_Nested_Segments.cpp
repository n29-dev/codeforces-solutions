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

    vector<pair<int, int>> v(m), s;
    unordered_map<int, int> mp;

    for (int i = 0; i < m; i++)
    {
        cin >> v[i].first >> v[i].second;
        mp[v[i].first] = i + 1;
    };

    auto sort_weight = [](pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second < b.second)
            return 1;
        return 0;
    };

    sort(v.begin(), v.end(), sort_weight);

    ll total_weight = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        s.push_back(v[i]);
        total_weight += v[i].second;
    }

    auto sort_pos = [](pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first < b.first)
            return 1;
        return 0;
    };

    sort(s.begin(), s.end(), sort_pos);

    cout << total_weight << nline;
    int l = 0, r = 2 * n - 1;

    while (l < r)
    {
        cout << mp[s[l].first] << " " << mp[s[r].first] << nline;
        l++;
        r--;
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
