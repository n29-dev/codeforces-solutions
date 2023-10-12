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
    string s;
    cin >> s;

    int n = s.length();
    vector<pair<char, int>> v(n);

    for (int i = 1; i < n - 1; i++)
    {
        v[i].first = s[i];
        v[i].second = i;
    };

    auto indexOf = [](char c)
    {
        return int(c - 'a') + 1;
    };

    vector<int> ans;
    ans.push_back(1);
    int l = indexOf(s[0]), r = indexOf(s[n - 1]), t;

    auto compare = [l, r](pair<char, int> &a, pair<char, int> &b)
    {
        if (l > r)
        {
            if (a.first - 'a' > b.first - 'a')
                return 1;
        }
        else
        {
            if (a.first - 'a' < b.first - 'a')
                return 1;
        }

        return 0;
    };

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++)
    {
        t = indexOf(v[i].first);

        if (t >= min(l, r) && t <= max(l, r))
            ans.push_back(v[i].second + 1);
    }

    ans.push_back(n);

    cout << abs(l - r) << " " << ans.size() << nline;

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

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
