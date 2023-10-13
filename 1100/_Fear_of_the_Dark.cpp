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
    string s;
    cin >> n;
    cin >> s;

    vector<int> lefts, rights;
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            if (i < n / 2)
                lefts.push_back(i + 1);
            sum += i;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'R')
        {
            if (i >= n / 2)
                rights.push_back(i + 1);
            sum += (n - i) - 1;
        }
    }

    debug(lefts);
    debug(rights);

    int l = 0, r = 0, sl = lefts.size(), sr = rights.size();

    for (int i = 0; i < n; i++)
    {
        if (l < sl && r < sr)
        {
            if ((n - lefts[l]) - (lefts[l] - 1) > (rights[r] - 1) - (n - rights[r]))
            {
                sum += n - lefts[l];
                sum -= lefts[l] - 1;
                l++;
            }
            else
            {
                sum += rights[r] - 1;
                sum -= n - rights[r];
                r++;
            }
        }
        else if (l < sl)
        {
            sum += n - lefts[l];
            sum -= lefts[l] - 1;
            l++;
        }
        else if (r < sr)
        {
            sum += rights[r] - 1;
            sum -= n - rights[r];
            r++;
        }

        cout << sum << " ";
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
