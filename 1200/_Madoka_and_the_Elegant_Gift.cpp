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

void dfs(vector<string> &v, int n, int m, vector<vector<int>> &vis, int i, int j, int *up, int *down, int *left, int *right, int *cnt)
{
    *cnt += 1;
    vis[i][j] = 1;

    *up = min(*up, i);
    *down = max(*down, i);
    *left = min(*left, j);
    *right = max(*right, j);

    // up
    if (i - 1 >= 0)
        if (vis[i - 1][j] == 0 && v[i - 1][j] == '1')
            dfs(v, n, m, vis, i - 1, j, up, down, left, right, cnt);

    // down
    if (i + 1 < n)
        if (vis[i + 1][j] == 0 && v[i + 1][j] == '1')
            dfs(v, n, m, vis, i + 1, j, up, down, left, right, cnt);
    // left
    if (j - 1 >= 0)
        if (vis[i][j - 1] == 0 && v[i][j - 1] == '1')
            dfs(v, n, m, vis, i, j - 1, up, down, left, right, cnt);

    // right
    if (j + 1 < m)
        if (vis[i][j + 1] == 0 && v[i][j + 1] == '1')
            dfs(v, n, m, vis, i, j + 1, up, down, left, right, cnt);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<int>> vis;

    for (int i = 0; i < n; i++)
    {
        vector<int> t(m, 0);
        vis.push_back(t);
    }

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int cnt = 0, up = 0, down = 0, left = 0, right = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && v[i][j] == '1')
            {
                cnt = 0, up = n + 1, down = 0, right = 0, left = m + 1;
                dfs(v, n, m, vis, i, j, &up, &down, &left, &right, &cnt);
                int sqr = (down - up + 1) * (right - left + 1);
                if(cnt != sqr){
                    cout<<"NO"<<nline;
                    return;
                }
            }
        }
    }

    cout<<"YES"<<nline;
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
