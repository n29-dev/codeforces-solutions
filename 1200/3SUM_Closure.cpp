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
    int n, x;
    cin >> n;

    vector<int> v;

    int positives = 0, negatives = 0, zeros = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 0)
            zeros++;
        else if (x < 0)
            negatives++;
        else
            positives++;

        if (x != 0)
            v.push_back(x);
    }

    if (positives > 2 || negatives > 2)
    {
        cout << "NO" << nline;
    }
    else
    {
        for (int i = 1; i <= min(zeros, 2); i++)
            v.push_back(0);

        int sz = v.size(), found = 0;
        ll sum = 0;

        for (int i = 0; i < sz - 2; i++)
        {
            for (int j = i + 1; j < sz - 1; j++)
            {
                for (int k = j + 1; k < sz; k++)
                {
                    sum = v[i] + v[j] + v[k];
                    found = 0;

                    for (int l = 0; l < sz; l++)
                    {
                        if (v[l] == sum)
                            found = 1;
                    }

                    if (found == 0)
                    {
                        cout << "NO" << nline;
                        return;
                    }
                }
            }
        }

        cout << "YES" << nline;
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
