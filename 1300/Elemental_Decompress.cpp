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
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    vector<int> m(n + 1, 2), q(n, 0), p(n, 0), qr(n + 1, 0), pr(n + 1, 0);
    int valid = 1, j = n;

    for (int i = 0; i < n; i++)
    {
        v[i].first = i;
        cin >> v[i].second;
        m[v[i].second]--;

        if (m[v[i].second] < 0)
            valid = 0;
    }

    auto compare = [](pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second > b.second)
            return 1;
        return 0;
    };

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            p[v[i].first] = v[i].second;
            pr[v[i].second] = 1;
        }
        else if (v[i].second == v[i + 1].second)
        {
            p[v[i].first] = v[i].second;
            q[v[i + 1].first] = v[i + 1].second;

            pr[v[i].second] = 1;
            qr[v[i + 1].second] = 1;
            i++;
        }
        else
        {
            p[v[i].first] = v[i].second;
            pr[v[i].second] = 1;
        }
    }

    int idx, val, pi = n, qi = n;

    for (int i = 0; i < n; i++)
    {
        idx = v[i].first;
        val = v[i].second;

        if (p[idx] >= 1)
        {
            while (qr[qi] == 1 || qi > val)
                qi--;

            if (qi == 0)
            {
                valid = 0;
                break;
            }

            q[idx] = qi;
            qr[qi] = 1;
        }
        else
        {
            while (pr[pi] == 1 || pi > val)
                pi--;

            if (pi == 0)
            {
                valid = 0;
                break;
            }

            p[idx] = pi;
            pr[pi] = 1;
        }
    }

    if (valid == 0)
    {
        cout << "NO" << nline;
    }
    else
    {
        cout << "YES" << nline;
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << nline;
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
        cout << nline;
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
